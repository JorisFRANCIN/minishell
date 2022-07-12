/*
** EPITECH PROJECT, 2022
** cd_command
** File description:
** apply the cd command
*/

#include "minishell.h"

void my_home(linked_list_t *new_env)
{
    while (new_env != NULL) {
        char **tmp = my_str_to_word_array(new_env->env_data, "=");
        if (my_strcmp("HOME", tmp[0]) == 0) {
            chdir(tmp[1]);
            free(tmp);
            break;
        }
        free(tmp);
        new_env = new_env->next;
    }
}

void cd_arg_case(char **command, minishell_t *content)
{
    char *buff = NULL;
    buff = getcwd(buff, 0);
    int fd = open(command[1], O_RDONLY);
    if (my_strcmp(command[1], "-") == 0)
        command[1] = content->preview;
    if (chdir(command[1]) == -1) {
        if (fd != -1)
            my_printf(CD_NOT_DIR, command[1]);
        else
            my_printf(CD_NOT_FOUND, command[1]);
    } else {
        content->return_val = 0;
        content->preview = buff;
    }
    close(fd);
}

int cd_command(char **command, minishell_t *content)
{
    int i = count_arg(command);
    if (i > 2)
        my_printf(TOO_MANY_ARG, command[0]);
    i == 1 ? my_home(content->new_env) : 0;
    i == 2 ? cd_arg_case(command, content) : 0;
    return 0;
}
