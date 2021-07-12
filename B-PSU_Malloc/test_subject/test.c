#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int main(void)
{
    char *test = malloc(sizeof(char) * 56);

    strcpy(test, "aaaaaaa\n");
    printf("%p\n", test);
    free(test);
}