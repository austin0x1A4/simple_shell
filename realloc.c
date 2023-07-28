#include "shell.h"

/**
 * _memset - fills memory with a constant byte
 * @s: the pointer to the memory area
 * @b: the byte to fill *s with
 * @n: the amount of bytes to be filled
 * Return: (s) a pointer to the memory area s
 */
void *_memset(void *s, int b, size_t n)
{
	unsigned char *ptr = s;
	size_t i;

	for (i = 0; i < n; i++)
		ptr[i] = (unsigned char)b;
	return (s);
}

/**
 * ffree - frees a string array (array of pointers)
 * @arr: the string array to be freed
 */
void ffree(char **arr)
{
    int i;
    if (arr)
    {
        for (i = 0; arr[i]; i++)
            free(arr[i]);
        free(arr);
    }
}


/**
 * _realloc - reallocates a block of memory
 * @ptr: pointer to the previous allocated block
 * @old_size: size of the previous block
 * @new_size: size of the new block
 *
 * Return: pointer to the new block or NULL on failure
 */
void *_realloc(void *ptr, size_t old_size, size_t new_size)
{
	void *new_ptr;

	if (!ptr)
		return (malloc(new_size));

	if (new_size == 0)
	{
		free(ptr);
		return (NULL);
	}

	new_ptr = malloc(new_size);
	if (!new_ptr)
		return (NULL);

	memcpy(new_ptr, ptr, (old_size < new_size) ? old_size : new_size);
	free(ptr);
	return (new_ptr);
}
