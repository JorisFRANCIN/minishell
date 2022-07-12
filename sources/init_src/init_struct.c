/*
** EPITECH PROJECT, 2022
** init_env
** File description:
** init the copy of env in a linked_list
*/

#include "minishell.h"

char **cmd_options(void)
{
    char **cmds = malloc(sizeof(char *) * 6);
    cmds[0] = "exit";
    cmds[1] = "cd";
    cmds[2] = "env";
    cmds[3] = "setenv";
    cmds[4] = "unsetenv";
    cmds[5] = NULL;
    return cmds;
}

linked_list_t *init_env(char **env)
{
    int i = 0;
    while (env[i] != NULL)
        i++;
    linked_list_t *new_env = my_params_to_list(i, env);

    return new_env;
}

minishell_t *init_minishell(char **env)
{
    minishell_t *content = malloc(sizeof(minishell_t));
    content->preview = "\0";
    content->builtins = cmd_options();
    content->new_env = init_env(env);
    content->env_cpy = env;
    return content;
}
