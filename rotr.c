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
	stack_t *temp, *temp_2;
	(void)line_number;

	if (*stack != NULL || (*stack)->next == NULL)
	{
		temp = *stack;
		while (temp->next != NULL)
			temp = temp->next;
		*stack = temp;
		temp->next = temp->prev;
		temp->prev = NULL;
		temp = temp->next;

		while (temp->prev != NULL)
		{
			temp_2 = temp->next;
			temp->next = temp->prev;
			temp->prev = temp_2;
			temp = temp->next;
		}
		temp->prev = temp->next;
		temp->next = NULL;
	}
}
