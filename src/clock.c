/*
** EPITECH PROJECT, 2019
** Untitled (Workspace)
** File description:
** clock
*/

#include "my.h"

void timer(sfClock **clock, sfTime *time, int *i, int *dead)
{
    *time = sfClock_getElapsedTime(*clock);
    if (time->microseconds/1000000.00 > 0.15) {
        sfClock_restart(*clock);
        *time = sfClock_getElapsedTime(*clock);
        ++*i;
    }
    if (*i == 3 && *dead == 0)
        *i = 0;
    else if (*dead > 0) {
        timer_dead(dead, i);
    }
}

void timer_dead(int *dead, int *i)
{
    if (*dead < 10) {
        *i = 3;
        ++*dead;
    } else {
        *i = 4;
    }
}