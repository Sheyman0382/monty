#include "monty.h"

/**
 * pall - a function that prints all data in the stack
 * @stack: the stack that contains all data to be printed
 * @line_number: the line of the opcode to be executed
 *
 * Return: nothing
 */

void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;
	(void)line_number;

	if (*stack != NULL)
	{
		temp = *stack;
		while (temp != NULL)
		{
			printf("%d\n", temp->n);
			temp = temp->next;
		}
	}
}
