#include "monty.h"

/**
 * mod - adds the top two elements of the stack.
 * @stack: pointer to the memory allocated for stack
 * @line_number: line number of the bytecode to be executed
 *
 * Return: nothing
 */

void mod(stack_t **stack, unsigned int line_number)
{
	int result = 0;
	stack_t *temp = *stack;


	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
		fclose(ready_made.file);
		free(ready_made.buffer);
		free_stack(stack);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		fclose(ready_made.file);
		free(ready_made.buffer);
		free_stack(stack);
		exit(EXIT_FAILURE);
	}
	result = (temp->next->n % (*stack)->n);
	temp = temp->next;
	temp->n = result;
	free(*stack);
	*stack = temp;
	temp->prev = NULL;
}
