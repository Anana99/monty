#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include "monty.h"

bus_t bus = {NULL, NULL, NULL, 0};

/**
 * main - monty code interpreter
 * @argc: number of arguments
 * @argv: monty file location
 * Return: 0 on success
 */
int main(int argc, char *argv[])
{
    char *content;
    char buffer[256];  /* Declare a buffer with a size of 256 */
    FILE *file;
    /* size_t size = 0;  Remove the unused variable */
    ssize_t read_line = 1;
    stack_t *stack = NULL;
    unsigned int counter = 0;

    if (argc != 2)
    {
        fprintf(stderr, "USAGE: monty file\n");
        exit(EXIT_FAILURE);
    }

    file = fopen(argv[1], "r");
    bus.file = file;

    if (!file)
    {
        fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    while (read_line > 0)
    {
        content = NULL;

        if (fgets(buffer, sizeof(buffer), file) == NULL)
        {
            fprintf(stderr, "Error reading line %u\n", counter);
            free(content);
            break;
        }

        bus.content = content;
        counter++;
        execute(content, &stack, counter, file);
        free(content);
    }

    free_stack(stack);
    fclose(file);

    return (0);
}
