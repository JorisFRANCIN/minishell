/*
** EPITECH PROJECT, 2022
** str_to_word_array
** File description:
** Transform a string into an array
*/

#include "my.h"

int opt_separators(char s, char *c)
{
    for (int i = 0; c[i] != '\0'; i++) {
        if (s == c[i])
            return 1;
    }
    return 0;
}

int word_length(char *str, int j, char *c)
{
    int length = 0;

    while (opt_separators(str[j], c) == 0 && str[j] != '\0') {
        if (str[j] >= 32 && str[j] < 127)
            length++;
        j++;
    }
    return length;
}

int count_word(char *str, char *c)
{
    int words = 0;

    for (int i = 0; i != my_strlen(str); i++) {
        if (opt_separators(str[i], c) == 1 && str[i + 1] >= 32 &&
        str[i + 1] < 127 && str[i + 1] != '\0')
            words++;
    }
    return words;
}

char **my_str_to_word_array(char *str, char *c)
{
    int i = 0;
    int j = 0;
    int tmp = 0;
    int word_len = 0;
    int nbr_word = count_word(str, c) + 2;
    char **new_argv = malloc(sizeof(char *) * nbr_word);

    for (i; i != count_word(str, c) + 1; i++, j++, tmp = 0) {
        word_len = word_length(str, j, c);
        new_argv[i] = malloc(sizeof(char) * word_len + 1);
        while (tmp != word_len) {
            new_argv[i][tmp] = str[j];
            tmp++;
            j++;
        }
        new_argv[i][word_len] = '\0';
    }
    new_argv[i] = NULL;
    return new_argv;
}
