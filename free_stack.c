#include "monty.h"

/**
 * free_stack - frees the memory allocated for stack
 * @stack: pointer to the stack memory.
 *
 * Return: nothing
 */

void free_stack(stack_t **stack)
{
	stack_t *temp;

	if (*stack == NULL)
		return;
	while (*stack != NULL)
	{
		temp = (*stack)->next;
		free(*stack);
		*stack = temp;
	}
}
