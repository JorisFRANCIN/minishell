/*
** EPITECH PROJECT, 2022
** minishell_redirect
** File description:
** minishell2 : Handle redirections
*/

#include "minishell.h"

int add_in_redirect(char redirect, redirection_t **list)
{
    redirection_t *executable = malloc(sizeof(*executable));
    redirection_t *tmp = NULL;

    executable->redirect = redirect;
    executable->next = NULL;

    if (*list == NULL)
        *list = executable;
    else {
        tmp = *list;
        while (tmp->next != NULL)
            tmp = tmp->next;
        tmp->next = executable;
    }
    return 0;
}

minishell_t * init_shell2(char *buff, minishell_t *content)
{
    char **parsing = my_str_to_word_array(buff, "<;|>");
    content->executables = parsing;

    for (int i = 0; buff[i] != '\0'; i++) {
        if (buff[i] == ';' || buff[i] == '<' ||
        buff[i] == '>' || buff[i] == '|') {
            add_in_redirect(buff[i], &content->redirects);
        }
    }
    return content;
}

int minishell_redirect(char *buff, minishell_t *content)
{
    content = init_shell2(buff, content);
    int pipefd[2];

    pipe(pipefd);
    for (int i = 0; content->executables[i]; i++) {
        if (is_a_builtin(content->executables[i], content) == SUCCESS)
            exec_builtin(content->executables[i], content);
        else {
            int pid = fork();
            exec_bin_command(content->executables[i], content, pid);
        }
    }
    return 0;
}
