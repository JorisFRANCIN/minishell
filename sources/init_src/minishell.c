/*
** EPITECH PROJECT, 2022
** minishell
** File description:
** minishell program
*/

#include "minishell.h"

void handler(__attribute__((unused)) int signum)
{
    write(0, "\n$> ", 4);
}

int minishell(minishell_t *content)
{
    size_t n = 0;
    struct stat id;
    fstat(0, &id);
    char *buff = malloc(sizeof(char) * id.st_size);
    signal(SIGINT, handler);

    my_printf("$> ");
    while(1) {
        getline(&buff, &n, stdin) == -1 ? exit_case_no_arg(content) : 0;
        minishell_basic(buff, content);
        my_printf("$> ");
    }
    free(buff);
    free_all(content);
    return SUCCESS;
}
