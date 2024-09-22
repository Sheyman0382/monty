 #include "monty.h"

/**
 * pstr - removes the top element of the stack.
 * @stack: pointer to the memory allocated for stack
 * @line_number: line number of the bytecode to be executed
 *
 * Return: nothing
 */

void pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;
	(void)line_number;

	temp = *stack;
	while (temp)
	{
		if (temp->n > 127 || temp->n <= 0)
		{
			break;
		}
		printf("%c", temp->n);
		temp = temp->next;
	}
	printf("\n");
}
