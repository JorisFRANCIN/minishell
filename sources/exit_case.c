/*
** EPITECH PROJECT, 2022
** exit_case
** File description:
** exit protocol applied
*/

#include "minishell.h"

int exit_case_no_arg(minishell_t *content)
{
    my_printf("exit\n");
    exit(content->return_val);
}

int exit_case(char *return_val)
{
    my_printf("exit\n");
    exit(my_atoi(return_val));
}
