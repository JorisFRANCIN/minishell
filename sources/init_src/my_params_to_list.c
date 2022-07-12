/*
** EPITECH PROJECT, 2021
** my_params_to_list
** File description:
** Insert argv in linked list
*/

#include "minishell.h"

int my_put_in_list(struct linked_list_s **list, char *av)
{
    struct linked_list_s *element;

    element = malloc(sizeof(*element));
    element->env_data = av;
    element->next = *list;
    *list = element;
    return (0);
}

linked_list_t *my_params_to_list(int ac, char ** av)
{
    int i = 0;
    struct linked_list_s *list = NULL;

    while (i != ac) {
        my_put_in_list(&list, av[ac - 1]);
        ac--;
    }
    return (list);
}
