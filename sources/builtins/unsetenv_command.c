/*
** EPITECH PROJECT, 2022
** unsetenv_command
** File description:
** Apply unsetenv command
*/

#include "minishell.h"

int belong_to_env(char *var, char **command)
{
    for (int i = 0; command[i]; i++) {
        if (my_strcmp(var, command[i]) == 0)
            return 0;
    }
    return 1;
}

void delete_element(char **command, linked_list_t **env)
{
    char **tmp = NULL;
    linked_list_t *copy = *env;
    linked_list_t *node = NULL;
    while (copy->next != NULL) {
        tmp = my_str_to_word_array(copy->next->env_data, "=");
        if (belong_to_env(tmp[0], command) != 0)
            copy = copy->next;
        else {
            node = copy->next;
            copy->next = copy->next->next;
            free(node);
        }
    }
}

int unsetenv_command(char **command, minishell_t *content)
{
    content->return_val = 0;
    int count = count_arg(command);
    if (count == 1) {
        my_printf(MISSING_ARG, command[0]);
        content->return_val = 1;
    }
    content->new_env != NULL && count > 1 ?
    delete_element(command, &content->new_env) : 0;
    return 0;
}
