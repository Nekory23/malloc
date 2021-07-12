/*
** EPITECH PROJECT, 2021
** malloc
** File description:
** create blocks to allocate memory
*/

#include <sys/types.h>
#include <stdlib.h>
#include <unistd.h>
#include "my_malloc.h"

block_t *best_fit(size_t size, block_t *tmp)
{
    block_t *best = tmp;
    size_t best_s = 0;

    if (tmp == NULL)
        return (NULL);
    while (tmp->next != NULL) {
        if (tmp->free == FREE && (tmp->size >= size && best_s >= tmp->size))
            best_s = tmp->size;
        tmp = tmp->next;
    }
    if (best_s == 0)
        return (NULL);
    while (best->size != best_s)
        best = best->next;
    best->free = NOT_FREE;
    return (best);
}

static void fill_block(block_t *to_fill, size_t size, void *address)
{
    to_fill->prev = NULL;
    to_fill->next = NULL;
    to_fill->free = NOT_FREE;
    to_fill->size = size;
    to_fill->ptr = address + sizeof(block_t);
}

void *create_block(size_t size, size_t pages, block_t *tmp)
{
    block_t *new_block;
    void *address;

    if (((address = sbrk(pages))) == (void*)-1)
        return (NULL);
    if (tmp != NULL) {
        while (tmp->next != NULL)
            tmp = tmp->next;
        tmp->next = address;
        fill_block(tmp->next, size, address);
        tmp->next->prev = tmp;
        return (tmp->next);
    }
    new_block = address;
    fill_block(new_block, size, address);
    return (new_block);
}

size_t new_size(size_t size)
{
    size_t n_size = 1;

    while (n_size < size)
        n_size *= 2;
    return (n_size);
}

size_t get_page(size_t size)
{
    size_t page = getpagesize() * 2;

    if (size > page)
        for (int i = 0; size > page; i++)
            page = (getpagesize() * 2) * i;
    return (page);
}