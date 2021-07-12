/*
** EPITECH PROJECT, 2021
** malloc
** File description:
** free
*/

#ifndef _LIB_MALLOC_
#define _LIB_MALLOC_

#include <stddef.h>

/**** structure ****/
typedef struct block_s block_t;

typedef struct block_s {
    struct block_s *next;
    struct block_s *prev;
    size_t size;
    int free;
    void *ptr;
} block_s;

/**** prototypes ****/
// malloc
void *malloc(size_t);
size_t new_size(size_t);
size_t get_page(size_t);
void *create_block(size_t, size_t, block_t *);
block_t *best_fit(size_t, block_t *);
// free
void free(void *);
block_t *search_for_ptr(block_t *list, void *ptr);
block_t *free_this(block_t *tmp);
// calloc
void *calloc(size_t, size_t);
// realloc
void *realloc(void *, size_t);
block_t *get_block(block_t *, void *);
void copy_block(block_t *, block_t *);
// reallocarray
void *reallocarray(void *, size_t, size_t);

/*** constant values ****/
static const int FREE = 1;
static const int NOT_FREE = 0;

#endif