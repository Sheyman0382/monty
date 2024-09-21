#include "monty.h"

/**
 * pchar - removes the top element of the stack.
 * @stack: pointer to the memory allocated for stack
 * @line_number: line number of the bytecode to be executed
 *
 * Return: nothing
 */

void pchar(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
		fclose(ready_made.file);
		free(ready_made.buffer);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n < 0 || (*stack)->n > 127)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
		fclose(ready_made.file);
		free(ready_made.buffer);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", (char)(*stack)->n);
}
