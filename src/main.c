/*
** EPITECH PROJECT, 2019
** Untitled (Workspace)
** File description:
** main
*/

#include "my.h"

void message_h(void)
{
    write(1, "Manual Duck Hunt\n", 17);
    write(1, "    input :left click\n", 22);
    write(1, "    echap :quit\n", 16);
    write(1, "    goal  :shoot the maximum of duck\n", 38);
}

int main(int ac, char **av)
{
    if (ac == 2 && av[1][0] == '-' && av[1][1] == 'h') {
        message_h();
        return (0);
    }
    else if (ac != 1) {
        return (84);
    }
    else {
        srand(time(NULL));
        return (hunter());
    }
    return (84);
}
