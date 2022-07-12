/*
** EPITECH PROJECT, 2022
** main
** File description:
** Init program
*/

#include "minishell.h"

int main(int argc, __attribute__((unused)) char **argv,
            char **env)
{
    if (env == NULL)
        return ERROR_NO_ENV;
    minishell_t *content = init_minishell(env);
    if (argc != 1)
        return ERROR_ARG;
    minishell(content);
    return content->return_val;
}
