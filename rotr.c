#include "monty.h"

/**
 * rotr - rotates the stack to the bottom.
 * @stack: pointer to the stack
 * @line_number: the current line number in the bytecode file
 *
 * Return: nothing
 */

void rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *temp, *tail;
	(void)line_number;

	if (*stack == NULL || (*stack)->next == NULL)
		return;

	temp = *stack;
	tail = *stack;

	while (tail->next != NULL)
		tail = tail->next;

	if (tail->prev != NULL)
		tail->prev->next = NULL;

	tail->prev = NULL;
	tail->next = temp;
	temp->prev = tail;

	*stack = tail;
}
