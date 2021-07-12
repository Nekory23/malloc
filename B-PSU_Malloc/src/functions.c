/*
** EPITECH PROJECT, 2021
** malloc
** File description:
** malloc
*/

#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>
#include "my_malloc.h"

block_t *start = NULL;

void free(void *ptr)
{
    block_t *temp = start;

    if (ptr == NULL)
        return;
    temp = search_for_ptr(temp, ptr);
    if (free_this(temp) == NULL)
        start = NULL;
}

void *calloc(size_t nmemb, size_t size)
{
    size_t total = nmemb * size;
    void *ptr;

    ptr = malloc(total);
    if (ptr == NULL)
        return (NULL);
    memset(ptr, 0, total);
    return (ptr);
}

void *reallocarray(void *ptr, size_t nmemb, size_t size)
{
    void *new_ptr;

    if (nmemb > (INT_MAX / size))
        return (NULL);
    new_ptr = realloc(ptr, (nmemb * size));
    if (new_ptr == NULL)
        return (NULL);
    return (new_ptr);
}

void *realloc(void *ptr, size_t size)
{
    void *new_ptr = malloc(size);
    block_t *old;
    block_t *new;

    if (new_ptr == NULL) {
        free(ptr);
        return (NULL);
    }
    if ((old = get_block(start, ptr)) == NULL)
        return (new_ptr);
    if ((new = get_block(start, new_ptr)) == NULL)
        return (new_ptr);
    copy_block(new, old);
    free(ptr);
    return (new_ptr);
}

void *malloc(size_t size)
{
    block_t *block;
    size_t n_size = new_size(size + sizeof(block_t));
    size_t pages = get_page(n_size);

    if (start == NULL) {
        start = create_block(n_size, pages, start);
        if (start == NULL)
            return (NULL);
        return (start->ptr);
    }
    else if ((block = best_fit(n_size, start)) != NULL)
        return (block->ptr);
    else {
        block = create_block(n_size, pages, start);
        if (block == NULL)
            return (NULL);
        return (block->ptr);
    }
}