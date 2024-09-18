#include "monty.h"

/**
 * push_wrapper - a function that calls the push fucntion
 * @stack: the stake that holds data being pushed
 * @line_number: the line number of the opcode
 *
 * Return: return nothing.
 */


void push_wrapper(stack_t **stack, unsigned int line_number)
{
	int value;

	if (argument == NULL)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	value = atoi(argument);

	push(stack, line_number, value);
}

/**
 * push - a function that calls the push fucntion
 * @stack: the stake that holds data being pushed
 * @line_number: the line number of the opcode
 * @value: the value to be placed in the integer
 * Return: return nothing.
 */

void push(stack_t **stack, unsigned int line_number, int value)
{
	stack_t *newnode;
	(void)line_number;

	newnode = malloc(sizeof(stack_t));
	if (newnode == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	newnode->n = value;
	newnode->prev = NULL;
	newnode->next = NULL;

	if (*stack == NULL)
	{
		*stack = newnode;
	}
	else
	{
		newnode->next = *stack;
		(*stack)->prev = newnode;
		*stack = newnode;
	}
}
