/*
** EPITECH PROJECT, 2022
** count_arg
** File description:
** count arg in a char **
*/

#include "minishell.h"

int is_clear(char *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == ' ' || str[i] == 9 || str[i] == '\n'
        || str[i] == '\\' || str[i] == '/' || str[i] == '|'
        || str[i] == '<' || str[i] == ';' || str[i] == '>')
            ;
        else
            return 1;
    }
    return 0;
}

int count_arg(char **argv)
{
    int i = 0;
    while (argv[i])
        i++;
    return i;
}

int count_adv_cmd(char *buff)
{
    int i = 0;
    int count = 1;
    while(buff[i] != '\0') {
        if (buff[i] == ';' || buff[i] == '|' ||
        buff[i] == '<' || buff[i] == '>')
            count++;
        i++;
    }
    return count;
}
