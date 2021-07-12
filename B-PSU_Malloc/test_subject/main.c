#include <stdio.h>
#include <string.h>
#include "../include/my_malloc.h"

/*
int main(void)
{
    char *test = malloc(sizeof(char) * 67);
    char *test2 = malloc(sizeof(char) * 10);
    char *test3;

    if (test == NULL)
        printf("eh.. expected\n");
    else {
        strcpy(test, "aaaaaaa\n");
        printf("%s", test);
        printf("%p\n", test);
    }
    if (test2 == NULL)
        printf("eh.. expected\n");
    else {
        strcpy(test2, "bbbbbbb\n");
        printf("%s", test2);
        printf("%p\n", test2);
    }
    //test3 = realloc(test, 30);
    //strcat(test3, " hello\n");
    //printf("%p\n %shey\n", test3, test3);
    //printf("%p\n %s hey\n", test2, test2);
    free(test)
    if (test == NULL)
        printf("null\n");
    return (0);
}
*/

int main(void)
{
    char *test = malloc(sizeof(char) * 67);
    char *test2 = malloc(56);
    char *test_calloc = calloc(3, sizeof(int));

    printf("test calloc %s\n", test_calloc);
    if (test_calloc[0] == 0)
        printf("ok\n");
    if (test == NULL)
        printf("eh.. expected\n");
    else {
        strcpy(test, "aaaaaaa\n");
        printf("%s", test);
        printf("%p\n", test);
    }
    if (test2 == NULL)
        printf("eh.. expected\n");
    else {
        strcpy(test2, "bbbbbbb\n");
        printf("%s", test2);
        printf("%p\n", test2);
    }
    free(test);
    printf("%s", test);
    if (test == NULL)
        printf("null\n");
    return (0);
}