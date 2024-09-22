#include "monty.h"

/**
 * rotl - a function that prints all data in the stack
 * @stack: the stack that contains all data to be printed
 * @line_number: the line of the opcode to be executed
 *
 * Return: nothing
 */

void rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *temp, *tail;
	(void)line_number;

	if (*stack == NULL || (*stack)->next == NULL)
		return;

	temp = tail = *stack;

	while (tail->next != NULL)
		tail = tail->next;

	*stack = temp->next;
	(*stack)->prev = NULL;

	temp->next = NULL;
	tail->next = temp;
	temp->prev = tail;
}
