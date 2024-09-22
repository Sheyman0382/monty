#include "monty.h"

/**
 * _realloc - a function that reallocates a block pf memory
 * using malloc and free
 *
 * @ptr: pointer to the old memory block allocated
 * @old_size: old memory size formally allocated using malloc
 * @new_size: new size of the memory block to be allocated using realloc
 * Return: integer pointer
 */

void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	void *str;

	if (new_size == 0)
	{
		free(ptr);
		return (NULL);
	}
	if (ptr == NULL)
		return (malloc(new_size));

	str = malloc(new_size);

	if (str == NULL)
		return (NULL);

	memcpy(str, ptr, old_size < new_size ? old_size : new_size);
	free(ptr);

	return (str);
}
