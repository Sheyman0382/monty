#include "monty.h"

/**
 * sub - adds the top two elements of the stack.
 * @stack: pointer to the memory allocated for stack
 * @line_number: line number of the bytecode to be executed
 *
 * Return: nothing
 */

void sub(stack_t **stack, unsigned int line_number)
{
	int result = 0;
	stack_t *temp = *stack;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		fclose(ready_made.file);
		free(ready_made.buffer);
		free_stack(stack);
		exit(EXIT_FAILURE);
	}
	result = (*stack)->n - temp->next->n;
	if (result < 0)
		result *= -1;
	temp = temp->next;
	temp->n = result;
	free(*stack);
	*stack = temp;
	temp->prev = NULL;
}
