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
	unsigned int count = 0;
	char character;
	stack_t *temp = *stack;
	char *str = malloc(sizeof(char) * 2);
	(void)line_number;

	if (str == NULL)
		return;
	while (temp != NULL && temp->n > 0 && temp->n <= 127)
	{
		char *new_str = _realloc(str, count,  (count + 2));

		if (new_str == NULL)
		{
			free(str);
			return;
		}
		str = new_str;
		character = (char)temp->n;
		str[count] = character;
		count++;
		temp = temp->next;
	}
	str[count] = '\0';
	printf("%s\n", str);
	free(str);
}
