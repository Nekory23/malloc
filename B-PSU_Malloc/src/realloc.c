/*
** EPITECH PROJECT, 2021
** malloc
** File description:
** realloc
*/

#include <stdio.h>
#include <stdlib.h>
#include "my_malloc.h"

block_t *get_block(block_t *list, void *ptr)
{
    if (ptr == NULL)
        return (NULL);
    while (list != NULL) {
        if (list->ptr == ptr)
            return (list);
        list = list->next;
    }
    return (NULL);
}

void copy_block(block_t *new, block_t *old)
{
    size_t *old_b = (size_t *)old->ptr;
    size_t *new_b = (size_t *)new->ptr;
    unsigned int it = 0;

    while (it * sizeof(size_t) < old->size && it * sizeof(size_t) < new->size) {
        new_b[it] = old_b[it];
        it++;
    }
}