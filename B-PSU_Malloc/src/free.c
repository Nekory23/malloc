/*
** EPITECH PROJECT, 2021
** malloc
** File description:
** free
*/

#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include "my_malloc.h"

static block_t *free_last(block_t *temp, block_t *ret)
{
    if (temp->prev != NULL)
        temp->prev->next = NULL;
    else
        ret = NULL;
    sbrk(get_page(temp->size) * -1);
    return (ret);
}

static void fusion_b(block_t *temp)
{
    temp->prev->size += temp->size;
    temp->prev->next = temp->next;
    if (temp->next != NULL)
        temp->next->prev = temp->prev;
}

static void fusion_f(block_t *temp)
{
    temp->size += temp->next->size;
    temp->next->next->prev = temp;
}

block_t *free_this(block_t *temp)
{
    block_t *ret = temp;

    temp->free = FREE;
    while (temp->prev != NULL && temp->prev->free == FREE) {
        fusion_b(temp);
        temp = temp->prev;
    }
    while (temp->next != NULL && temp->next->free == FREE) {
        fusion_f(temp);
        temp->next = temp->next->next;
    }
    if (temp->next == NULL)
        ret = free_last(temp, ret);
    return (ret);
}

block_t *search_for_ptr(block_t *list, void *ptr)
{
    while (list != NULL) {
        if (list->ptr == ptr)
            return (list);
        list = list->next;
    }
    return (NULL);
}