/*
** EPITECH PROJECT, 2022
** my_struct.h
** File description:
** .h file that contains the struct
*/

#ifndef MY_STRUCT_H_
    #define MY_STRUCT_H_

typedef struct linked_list_s {
    char *env_data;
    struct linked_list_s *next;
} linked_list_t;

typedef struct redirection_s {
    char redirect;
    struct redirection_s *next;
} redirection_t;

typedef struct minishell_s {
    linked_list_t *new_env;
    char **executables;
    redirection_t *redirects;
    char *preview;
    char **builtins;
    char **env_cpy;
    int return_val;
} minishell_t;

#endif /* !MY_STRUCT_H_ */
