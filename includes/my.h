/*
** EPITECH PROJECT, 2021
** my_h
** File description:
** Contains all the prototype of my library
*/

#include <stdlib.h>

#ifndef MY_H_
    #define MY_H_
void my_putchar(char c);
void my_putstr(char const *str);
int my_put_nbr(int nb);
int my_put_nbr2(unsigned int nb);
char *my_strdup(char const *str);
int my_put_nbr_base(unsigned int nb, int flag2);
int my_put_nbr_hex(unsigned int nb, char flag);
int my_putstr2(char const *tr, int flag2);
int my_put_nbr_binary(unsigned int nb);
void *my_printf(char const *format, ...);

int my_strlen(char const *str);
char **my_str_to_word_array(char *str, char *c);
int count_word(char *str, char *c);
int nbr_of_argv(char const *str);
char * my_getstr(char const *str, int i);
int mem_length(char const *str, int i);
char *my_strcat(char *dest, char *src);
int my_strcmp(char const *s1, char const *s2);
char *my_strcpy(char *dest, char const *src);
int my_atoi(char const *str);
char *my_clean_str(char *str);
int is_char(char c);

#endif  /* MY_H_ */
