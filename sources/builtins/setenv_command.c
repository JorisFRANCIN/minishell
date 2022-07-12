/*
** EPITECH PROJECT, 2022
** setenv_command
** File description:
** Apply setenv command
*/

#include "minishell.h"

char *var_content(char **command)
{
    if (command[2] != NULL) {
        char *tmp = my_strcat(command[1], "=");
        return my_strcat(tmp, command[2]);
    }
    return my_strcat(command[1], "=");
}

void add_element(char **command, linked_list_t *env)
{
    while (env->next != NULL) {
        char **tmp = my_str_to_word_array(env->next->env_data, "=");
        if (my_strcmp(tmp[0], command[1]) != 0) {
            env = env->next;
            free(tmp);
        } else
            break;
    }
    if (env->next == NULL)
        env->next = malloc(sizeof(*env));
    env->next->env_data = var_content(command);
    env->next->next = NULL;
}

int is_correct(char *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (is_char(str[i]) != 0)
            return 1;
    }
    return 0;
}

int setenv_command(char **command, minishell_t *content)
{
    int count = count_arg(command);
    content->return_val = 0;
    if (count == 1) {
        display_env(content->new_env, content);
        return 0;
    }
    if (count > 3) {
        my_printf(TOO_MANY_ARG, command[0]);
        content->return_val = 1;
        return 0;
    }
    if ((command[1] != NULL && is_correct(command[1]) != 0) ||
    (command[2] != NULL && is_correct(command[2]) != 0)) {
        my_printf(ENV_UNCORRECT_FORMAT, command[0]);
        return 0;
    }
    add_element(command, content->new_env);
    return 0;
}
