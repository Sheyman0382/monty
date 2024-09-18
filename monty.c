#include "monty.h"

char *argument = NULL;
/**
 * main - the main function for the monty interpreter
 * @argc: argument count
 * @argv: argument variable
 *
 * Return: 0 on success, or exit with failure if argument count is incorrect.
 */

int main(int argc, char **argv)
{
	FILE *file;
	char *buffer = NULL;
	size_t n = 0;
	unsigned int line_number = 0;
	stack_t *stack = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	file = fopen(argv[1], "r");
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	while (getline(&buffer, &n, file) != -1)
	{
		line_number++;
		process_line(buffer, &stack, line_number);

	}
	free(buffer);
	fclose(file);
	free_stack(&stack);

	return (0);
}
