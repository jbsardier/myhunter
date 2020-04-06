/*
** EPITECH PROJECT, 2019
** Untitled (Workspace)
** File description:
** hunter
*/

#include "my.h"

int hunter(void)
{
    sfRenderWindow *window;
    sfSprite *back_ground;
    sfClock *clock;
    sfVideoMode mode = {800, 600, 32};
    sfVector2f orig = {0, 0};
    sfTexture *back_ground_text;

    back_ground_text = sfTexture_createFromFile\
    ("sprite/Duck_Hunt_fond.png", NULL);
    back_ground = sfSprite_create();
    sfSprite_setPosition(back_ground, orig);
    sfSprite_setTexture(back_ground, back_ground_text, sfTrue);
    window = sfRenderWindow_create(mode, "hunter", sfDefaultStyle, NULL);
    sfRenderWindow_setMouseCursorVisible(window, sfFalse);
    sfRenderWindow_setFramerateLimit(window, 30);
    sfRenderWindow_drawSprite(window, back_ground, NULL);
    clock = sfClock_create();
    game_over(game(&window, &back_ground, &clock), window);
    return (0);
}

score_t game(sfRenderWindow **window, sfSprite **back_ground, sfClock **clock)
{
    sfEvent event;
    sfTime time;
    char *max_score = score();
    disp_t to_disp = creat_to_disp(window);
    vect_t vit = {12, 0};
    score_t score = {3, 0, max_score};
    int dead = 0;
    int i = 0;
    while (sfRenderWindow_isOpen(*window)) {
        if (get_event(&event, window, score))
            return (score);
        anim(&to_disp, &i, &dead, &vit);
        timer(clock, &time, &i, &dead);
        set_text_sheet(&(to_disp.duck), i);
        display(to_disp, *back_ground, score);
        reset_pos(&to_disp, &i, &dead, &score);
    }
    return (score);
}

sfSprite *creat_sprite(char *filepath, int x, int y)
{
    sfSprite *sprite;
    sfTexture *sprite_text;
    sfVector2f orig = {x, y};
    sprite_text = sfTexture_createFromFile(filepath, NULL);
    sprite = sfSprite_create();

    sfSprite_setPosition(sprite, orig);
    sfSprite_setTexture(sprite, sprite_text, sfTrue);
    return (sprite);
}

void set_text_sheet(sfSprite **sprite, int i)
{
    sfIntRect int_rect;
    int_rect.height = 110;
    int_rect.width = 335 / 3;
    int_rect.left = (i * int_rect.width);
    int_rect.top = 0;
    sfSprite_setTextureRect(*sprite, int_rect);
}

int get_event(sfEvent *event, sfRenderWindow **window, score_t score)
{
    while (sfRenderWindow_pollEvent(*window, event)) {
        if (event->type == sfEvtClosed ) {
            sfRenderWindow_close(*window);
            return (1);
        }
    }
    if (score.vie == 0) {
        return (1);
    }
    return (0);
}