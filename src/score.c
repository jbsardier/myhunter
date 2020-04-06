/*
** EPITECH PROJECT, 2019
** MUL_my_hunter_2019
** File description:
** score
*/

#include "my.h"

char *score(void)
{
    int fd = open("save/save", O_RDONLY);
    char *buff = malloc(sizeof(char) * 50 + 1);
    buff[50] = '\0';
    if (buff == NULL)
        return (NULL);
    read(fd, buff, 50);
    return (buff);
}

void new_score(score_t new_score)
{
    int fd = open("save/save", O_RDWR);
    int max = my_getnbr(new_score.max);
    char *new_str = malloc(sizeof(char) * 50 + 1);
    new_str[50] = '\0';
    char *new_max_char;
    int i = 0;
    int j = 0;
    char tmp[] = "MAX = ";
    if (max < new_score.score) {
        new_max_char = int_to_str(new_score.score);
        while (i < 6) {
            new_str[i] = tmp[i];
            ++i;
        }
        while (new_max_char[j] != '\0') {
            new_str[i] = new_max_char[j];
            ++i;
            ++j;
        }
    }write(fd, new_str, i);
}
