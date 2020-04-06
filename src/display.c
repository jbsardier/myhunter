/*
** EPITECH PROJECT, 2019
** Untitled (Workspace)
** File description:
** display
*/

#include "my.h"

void display(disp_t to_disp, sfSprite *back_ground, score_t score)
{
    sfVector2i posSouris = sfMouse_getPositionRenderWindow(*(to_disp.window));
    sfVector2f pos_cursor = {posSouris.x - 25, posSouris.y - 25};
    sfText *score_disp = disp_score(score);
    sfText *score_max = disp_max(score.max);
    sfSprite_setPosition(to_disp.cursor, pos_cursor);
    sfRenderWindow_drawSprite(*(to_disp.window), back_ground, NULL);
    sfRenderWindow_drawSprite(*(to_disp.window), to_disp.heart, NULL);
    sfRenderWindow_drawSprite(*(to_disp.window), to_disp.duck, NULL);
    sfRenderWindow_drawSprite(*(to_disp.window), to_disp.cursor, NULL);
    sfRenderWindow_drawText(*(to_disp.window), score_disp, NULL);
    sfRenderWindow_drawText(*(to_disp.window), score_max, NULL);
    sfRenderWindow_display(*(to_disp.window));
}

int reset_pos(disp_t *to_disp, int *i, int *dead, score_t *score)
{
    sfFloatRect posSprite;
    sfVector2u size_window;
    sfVector2f orig = {-20, rand() % 400};
    posSprite = sfSprite_getGlobalBounds(to_disp->duck);
    size_window = sfRenderWindow_getSize(*to_disp->window);
    if (posSprite.top > size_window.x) {
        *i = 0;
        *dead = 0;
        set_move(&to_disp->duck, 12, 0);
        sfSprite_setPosition(to_disp->duck, orig);
        score->score = score->score + 50;
        return (1);
    }
    if (posSprite.left > size_window.y + 2 * posSprite.width) {
        sfSprite_setPosition(to_disp->duck, orig);
        set_heart(to_disp);
        --score->vie;
        return (2);
    }
    return (0);
}

sfText *disp_score(score_t score)
{
    sfVector2f pos = {15, 50};
    sfText *score_disp = sfText_create();
    sfFont *font = sfFont_createFromFile("sprite/theboldfont.ttf");
    char *text_score = int_to_str(score.score);
    sfText_setFont(score_disp, font);
    sfText_setPosition(score_disp, pos);
    sfText_setCharacterSize(score_disp, 30);
    sfText_setColor(score_disp, sfBlack);
    sfText_setString(score_disp, text_score);
    return (score_disp);
}

sfText *disp_max(char *res)
{
    sfVector2f pos = {15, 15};
    sfText *score_disp = sfText_create();
    sfFont *font = sfFont_createFromFile("sprite/theboldfont.ttf");
    char *text_score = res;
    sfText_setFont(score_disp, font);
    sfText_setPosition(score_disp, pos);
    sfText_setCharacterSize(score_disp, 30);
    sfText_setColor(score_disp, sfBlack);
    sfText_setString(score_disp, text_score);
    return (score_disp);
}

disp_t creat_to_disp(sfRenderWindow **window)
{
    sfSprite *duck = creat_sprite("sprite/duck_sprite_sheet.png", 20, 10);
    sfSprite *heart = creat_sprite("sprite/hearts.png", 550, 10);
    sfSprite *cursor = creat_sprite("sprite/viseur.png", 20, 10);
    disp_t to_disp = {duck, window, cursor, heart};
    return (to_disp);
}