/*
** EPITECH PROJECT, 2019
** Day4
** File description:
** my_getnbr
*/

int where_num(char const *str)
{
    int count = 0;
    while (str[count] != '\0') {
        if (str[count] >= '0' && str[count] <= '9') {
            return (count);
        }
        ++count;
    }
    return (-1);
}

int negatif(int max, char const *str)
{
    int count = 0;
    int result = 1;
    while (count < max) {
        if (str[count] == '-') {
            result = result * -1;
        }
        ++count;
    }
    return (result);
}

int my_getnbr(char const *str)
{
    int count = where_num(str);
    unsigned int result = 0;
    int neg = negatif(count, str);
    int res_neg = 0;
    if (count >= 0) {
        while (str[count] != '\0' && str[count] >= '0' && str[count] <= '9') {
            result = (result * 10) + (str[count] - 48);
            if ((result > 2147483648 && neg == -1)
                || (result > 2147483647 && neg == 1))
                return (0);
            ++count;
        }
    }
    res_neg = neg * result;
    return (res_neg);
}
