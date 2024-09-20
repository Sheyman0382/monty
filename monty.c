#include "monty.h"

madeready_t ready_made = {NULL, NULL, NULL, NULL};
/**
 * main - the main function for the monty interpreter
 * @argc: argument count
 * @argv: argument variable
 *
 * Return: 0 on success, or exit with failure if argument count is incorrect.
 */

int main(int argc, char **argv)
{
	size_t n = 0;
	unsigned int line_number = 0;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	ready_made.file = fopen(argv[1], "r");
	if (ready_made.file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	while (getline(&ready_made.buffer, &n, ready_made.file) != -1)
	{
		line_number++;
		process_line(ready_made.buffer, &ready_made.stack, line_number);

	}
	free(ready_made.buffer);
	fclose(ready_made.file);
	free_stack(&ready_made.stack);

	return (0);
}
