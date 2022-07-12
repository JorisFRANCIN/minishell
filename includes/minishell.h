/*
** EPITECH PROJECT, 2022
** minishell.h
** File description:
** .h file
*/

#ifndef MINISHELL_H_
    #define MINISHELL_H_

    #include "my.h"
    #include "my_struct.h"
    #include "macro.h"

    #include <sys/types.h>
    #include <sys/stat.h>
    #include <fcntl.h>
    #include <unistd.h>
    #include <sys/wait.h>
    #include <stdio.h>
    #include <signal.h>

linked_list_t *my_params_to_list(int ac, char ** av);
int my_put_in_list(struct linked_list_s **list, char *av);
int count_arg(char **argv);
int count_adv_cmd(char *buff);
int is_clear(char *str);
linked_list_t *init_env(char **env);
minishell_t *init_minishell(char **env);

int minishell(minishell_t *content);
int exit_case(char *return_val);
int exit_case_no_arg(minishell_t *content);

int minishell_basic(char *buff, minishell_t *content);
int minishell_redirect(char *buff, minishell_t *content);

int is_a_builtin(char *buff, minishell_t *content);
int exec_builtin(char *buff, minishell_t *content);
int cd_command(char **command, minishell_t *content);
void display_env(linked_list_t *new_env, minishell_t *content);

void exec_bin_command(char *buff, minishell_t *content, int pid);
int setenv_command(char **command, minishell_t *content);
int unsetenv_command(char **command, minishell_t *content);

void free_all(minishell_t *content);

#endif /* !MINISHELL_H_ */
