/*
** EPITECH PROJECT, 2019
** MUL_my_hunter_2019
** File description:
** int_to_str
*/

#include "my.h"

int my_strlen(char const *str)
{
    int count = 0;
    while (*str != '\0') {
        ++str;
        ++count;
    }
    return (count);
}

char *my_revstr(char *str)
{
    int max = my_strlen(str)-1;
    int first = 0;
    char trans;
    while (first < max) {
        trans = str[first];
        str[first] = str[max];
        str[max] = trans;
        ++first;
        --max;
    }
    return (str);
}

int len_nbr(int nbr)
{
    int count = 0;
    while (nbr != 0) {
        nbr = nbr / 10;
        ++count;
    }
    return (count);
}

char *int_to_str(int nbr)
{
    int size = len_nbr(nbr);
    int i = 0;
    char *str_nbr = malloc(sizeof(char) * size + 1);
    str_nbr[size] = '\0';
    if (str_nbr == NULL)
        return (NULL);
    if (nbr == 0) {
        str_nbr[0] = '0';
        return (str_nbr);
    }
    while (i < size) {
        str_nbr[i] = nbr % 10 + 48;
        nbr = nbr / 10;
        ++i;
    }
    str_nbr = my_revstr(str_nbr);
    return (str_nbr);
}