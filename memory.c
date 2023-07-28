/**
 * bfree - frees a pointer and sets it to NULL
 * @ptr: address of the pointer to free
 *
 * Return: None
 */
void bfree(void *ptr)
{
	if (ptr)
	{
		free(ptr);
		ptr = NULL;
	}
}
