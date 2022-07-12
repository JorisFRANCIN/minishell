/*
** EPITECH PROJECT, 2022
** minishell_redirect
** File description:
** minishell2 : Handle redirections
*/

#include "minishell.h"

int minishell_basic(char *buff, minishell_t *content)
{
    if (my_strcmp(buff, "\n") == 0 || is_clear(buff) == 0)
        ;
    else if (is_a_builtin(buff, content) == SUCCESS)
        exec_builtin(buff, content);
    else {
        int pid = fork();
        exec_bin_command(buff, content, pid);
    }
    return 0;
}
