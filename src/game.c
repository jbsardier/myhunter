/*
** EPITECH PROJECT, 2019
** Untitled (Workspace)
** File description:
** game
*/

#include "my.h"

int hit(sfRenderWindow **window, sfSprite **sprite, int *i)
{
    sfVector2i posSouris;
    sfFloatRect posSprite;
    posSouris = sfMouse_getPositionRenderWindow(*window);
    posSprite = sfSprite_getGlobalBounds(*sprite);
    float left = posSprite.left;
    float right = posSprite.width + left;
    float top = posSprite.top;
    float bot = posSprite.height + top;
    if (posSouris.x > left && posSouris.x < right &&
    posSouris.y > top && posSouris.y < bot &&
    sfMouse_isButtonPressed(sfMouseLeft) == sfTrue) {
        *i = 4;
        return (1);
    }
    return (0);
}

void set_move(sfSprite **sprite, int x, int y)
{
    sfVector2f offset = {x, y};
    sfSprite_move(*sprite, offset);
}

void anim(disp_t *to_disp, int *i, int *dead, vect_t *vit)
{
    if (hit(to_disp->window, &to_disp->duck, i) || *dead) {
        ++*dead;
        if (*dead == 1)
            vit->x = (rand() % (5 - 2 + 1)) + 2 + vit->x;
        vit->y = 0;
        set_move(&to_disp->duck, 0, 12);
    }
    else {
        set_move(&to_disp->duck, vit->x, vit->y);
    }
}

void set_heart(disp_t *to_disp)
{
    sfIntRect int_rect = sfSprite_getTextureRect(to_disp->heart);
    int_rect.left = int_rect.left + 60;
    sfSprite_setTextureRect(to_disp->heart, int_rect);
}

void game_over(score_t score, sfRenderWindow *window)
{
    sfSprite *game_over = creat_sprite("sprite/game_over.png", 0, 0);
    sfText *score_disp = disp_score(score);
    sfVector2f pos = {375, 230};
    sfText_setPosition(score_disp, pos);
    sfEvent event;
    sfRenderWindow_setMouseCursorVisible(window, sfTrue);
    new_score(score);

    while (sfRenderWindow_isOpen(window)) {
        sfRenderWindow_drawSprite(window, game_over, NULL);
        sfRenderWindow_drawText(window, score_disp, NULL);
        sfRenderWindow_display(window);
        while (sfRenderWindow_pollEvent(window, &event)) {
            if (event.type == sfEvtClosed || sfKeyboard_isKeyPressed(sfKeyQ)) {
                sfRenderWindow_close(window);
            }
        }
    }
}
