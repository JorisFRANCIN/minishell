/*
** EPITECH PROJECT, 2022
** free_all
** File description:
** free all content
*/

#include "minishell.h"

void free_all(minishell_t *content)
{
    for (int i = 0; content->builtins[i]; i++)
        free(content->builtins[i]);
    for (int i = 0; content->env_cpy[i]; i++)
        free(content->env_cpy[i]);
    while (content->new_env != NULL) {
        free(content->new_env);
        content->new_env = content->new_env->next;
    }
    free(content->builtins);
    free(content->env_cpy);
    free(content);
}
