/*
** EPITECH PROJECT, 2022
** exec_bin_command
** File description:
** execute command from the /bin/ folder
*/

#include "minishell.h"

int status_management(int status, minishell_t *content)
{
    if (WIFSIGNALED(status)) {
        my_printf("Segmentation fault");
        my_printf(WCOREDUMP(status) ? " (core dumped)\n" : "\n");
    }
    content->return_val = status;
    return status;
}

char *find_path(linked_list_t **env)
{
    linked_list_t *tmp = *env;
    char **var = NULL;

    while (tmp != NULL) {
        var = my_str_to_word_array(tmp->env_data, "=");
        if (my_strcmp(var[0], "PATH") == 0)
            return tmp->env_data;
        free(var);
        tmp = tmp->next;
    }
    return NULL;
}

void is_a_cmd(minishell_t *content, char **commands)
{
    if (execve(my_strcat("/bin/", commands[0]), commands,
        content->env_cpy) == -1
        && execve(commands[0], commands, content->env_cpy) == -1) {
        my_printf(CMD_NOT_FND, commands[0]);
        exit(1);
    }
}

void is_a_cmd_path(char *path, minishell_t *content, char **commands)
{
    char **paths = my_str_to_word_array(path, ":");

    for (int i = 0; paths[i]; i++)
        paths[i] = my_strcat(paths[i], "/");
    for (int i = 0; paths[i]; i++) {
        if (access(my_strcat(paths[i], commands[0]), F_OK) == 0)
            execve(my_strcat(paths[i], commands[0]), commands,
            content->env_cpy);
    }
    if (execve(commands[0], commands, content->env_cpy) == -1) {
        my_printf(CMD_NOT_FND, commands[0]);
        exit(1);
    }
}

void exec_bin_command(char *buff, minishell_t *content, int pid)
{
    buff = my_clean_str(buff);
    char **new_argv = my_str_to_word_array(buff, " ");
    char *path = find_path(&content->new_env);
    int status = 0;

    if (pid == 0) {
        path != NULL ? is_a_cmd_path(path, content, new_argv) :
        is_a_cmd(content, new_argv);
    } else {
        wait(&status);
        status = status_management(status, content);
    }
}
