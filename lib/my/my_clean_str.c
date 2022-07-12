/*
** EPITECH PROJECT, 2022
** my_clean_str
** File description:
** clean the string from spaces and tab
*/

#include "my.h"

int is_char(char c)
{
    if (c >= 65 && c <= 90 || c >= 97 && c <= 122)
        return 0;
    return 1;
}

char *delete_sub_space(char *str, int i, int len)
{
    while (str[i] == ' ' && str[i + 1] == ' ') {
        for (int j = i; j != len - 1; j++)
            str[j] = str[j + 1];
    }
    return str;
}

char *my_clean_str(char *str)
{
    int len = my_strlen(str);
    for (int i = 0; i != len - 1; i++)
        str[i] += str[i] == 9 ? 23 : 0;
    while (is_char(str[0]) != 0) {
        for (int i = 0; i != len - 1; i++)
            str[i] = str[i + 1];
    }
    for (int i = 0; str[i] != '\0'; i++)
        delete_sub_space(str, i, len);
    for (int i = my_strlen(str) - 1; is_char(str[i]) != 0; i++)
        str[i] += str[i] == ' ' ? -32 : 0;
    return str;
}
