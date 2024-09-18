#include "monty.h"

/**
 * process_line - the function hadles how lines are tokenized
 * and functions called.
 * @line: the line to be executed
 * @stake: the stake in which data are pushed or modified
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
		{NULL, NULL}
	};

	opcode = strtok(line, " \n\t");
	argument = strtok(NULL, " \n\t");

	if (opcode == NULL || opcode[0] == '#')
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
	exit(EXIT_FAILURE);
}
