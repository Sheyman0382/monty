#include "monty.h"

/**
 * process_line - the function hadles how lines are tokenized
 * and functions called.
 * @line: the line to be executed
 * @stack: the stake in which data are pushed or modified
 * @line_number: the number line for bytecode
 * Return: return nothing
 */

void process_line(char *line, stack_t **stack, unsigned int line_number)
{
	int i;
	char *opcode;
	instruction_t instructions[] = {
		{"push", push_wrapper},
		{"pall", pall},
		{"pop", pop},
		{"pint", pint},
		{"swap", swap},
		{"add", add},
		{"nop", nop},
		{"sub", sub},
		{"div", _div},
		{"mod", mod},
		{"mul", mul},
		{NULL, NULL}
	};

	opcode = strtok(line, " \n\t");
	ready_made.argument = strtok(NULL, " \n\t");

	if (opcode[0] == '\0' || opcode[0] == '#' || opcode == NULL)
		return;

	i = 0;

	while (instructions[i].opcode != NULL)
	{
		if (strcmp(opcode, instructions[i].opcode) == 0)
		{
			instructions[i].f(stack, line_number);
			return;
		}
		i++;
	}

	fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
	free(ready_made.buffer);
	fclose(ready_made.file);
	exit(EXIT_FAILURE);
}
