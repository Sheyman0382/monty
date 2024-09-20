#include "monty.h"

/**
 * swap - swaps the top two elements of the stack.
 * @stack: pointer to the memory allocated for stack
 * @line_number: line number of the bytecode to be executed
 *
 * Return: nothing
 */

void swap(stack_t **stack, unsigned int line_number)
{
	int a = 0;
	stack_t *temp = *stack;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		fclose(ready_made.file);
		free(ready_made.buffer);
		free_stack(stack);
		exit(EXIT_FAILURE);
	}
	temp = temp->next;
	a = (*stack)->n;
	(*stack)->n = temp->n;
	temp->n = a;
}

/**
 * nop - swaps the top two elements of the stack.
 * @stack: pointer to the memory allocated for stack
 * @line_number: line number of the bytecode to be executed
 *
 * Return: nothing
 */

void nop(stack_t **stack, unsigned int line_number)
{
	(void)line_number;
	(void)stack;
}
