/*
** EPITECH PROJECT, 2022
** builtins
** File description:
** builtins command management
*/

#include "minishell.h"

void display_env(linked_list_t *new_env, minishell_t *content)
{
    while (new_env != NULL) {
        my_printf("%s\n", new_env->env_data);
        new_env = new_env->next;
    }
    content->return_val = 0;
}

int is_a_builtin(char *buff, minishell_t *content)
{
    char **command = my_str_to_word_array(buff, " ");
    for (int i = 0; content->builtins[i] != NULL; i++) {
        if (my_strcmp(command[0], content->builtins[i]) == 0) {
            free(command);
            return SUCCESS;
        }
    }
    free(command);
    return FAILURE;
}

int exec_builtin(char *buff, minishell_t *content)
{
    char **command = my_str_to_word_array(buff, " ");
    my_strcmp(command[0], "cd") == 0 ? cd_command(command, content) : 0;
    my_strcmp(command[0], "env") == 0 ?
    display_env(content->new_env, content) : 0;
    my_strcmp(command[0], "setenv") == 0 ?
    setenv_command(command, content) : 0;
    my_strcmp(command[0], "unsetenv") == 0 ?
    unsetenv_command(command, content) : 0;
    if (my_strcmp(command[0], "exit") == 0)
        command[1] == NULL ? exit_case_no_arg(content) : exit_case(command[1]);
    free(command);
    return 0;
}
