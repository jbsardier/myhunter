/*
** EPITECH PROJECT, 2019
** MUL_my_hunter_2019
** File description:
** my
*/

#ifndef MY_H_
#define MY_H_

#include <stdio.h>
#include <SFML/Graphics.h>
#include <stddef.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <fcntl.h>
#include <SFML/Audio.h>
#include <SFML/System.h>
#include <time.h>

typedef struct struct_disp
{
    sfSprite *duck;
    sfRenderWindow **window;
    sfSprite *cursor;
    sfSprite *heart;
}disp_t;

typedef struct vect
{
    int x;
    int y;
}vect_t;

typedef struct score
{
    int vie;
    int score;
    char *max;
}score_t;

#include "proto.h"

#endif /* !MY_H_ */
