/*
** EPITECH PROJECT, 2019
** Untitled (Workspace)
** File description:
** proto
*/

#ifndef PROTO_H_
#define PROTO_H_

#include "my.h"

//main.c
void message_h(void);

//hunter.c
int hunter(void);
score_t game(sfRenderWindow **, sfSprite **, sfClock **);
sfSprite *creat_sprite(char *, int , int );
void set_text_sheet(sfSprite **, int );
int get_event(sfEvent *, sfRenderWindow **, score_t);

//game.c
int hit(sfRenderWindow **, sfSprite **, int *);
void set_move(sfSprite **, int, int);
void anim(disp_t *, int *, int *, vect_t *);
void set_heart(disp_t *);
void game_over(score_t, sfRenderWindow *);

//display.c
int reset_pos(disp_t *, int *, int *, score_t *);
void display(disp_t, sfSprite *, score_t);
sfText *disp_score(score_t );
disp_t creat_to_disp(sfRenderWindow **);
sfText *disp_max(char *);

//clock.c
void timer(sfClock **, sfTime *, int *, int *);
void timer_dead(int *, int *);

//int_to_str.c
char *int_to_str(int );
int len_nbr(int );
char *my_revstr(char *);
int my_strlen(char const *);

//score.c
char *score(void);
void new_score(score_t );

//get_nbr.c
int where_num(char const *);
int negatif(int , char const *);
int my_getnbr(char const *);

#endif /* !PROTO_H_ */
