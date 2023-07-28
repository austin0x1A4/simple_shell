#include "shell.h"

/**
 * list_length - determines the length of a linked list
 * @head: pointer to the first node
 *
 * Return: The size of the list.
 */
size_t list_length(const list_t *head)
{
	size_t i = 0;

	while (head)
	{
		head = head->next;
		i++;
	}

	return (i);
}

/**
 * list_to_strings - returns an array of strings from the list->str field
 * @head: pointer to the first node
 *
 * Return: Array of strings or NULL on failure.
 */
char **list_to_strings(list_t *head)
{
	list_t *node = head;
	size_t i = list_length(head), j;
	char **strs;
	char *str;

	if (!head || !i)
		return (NULL);

	strs = malloc(sizeof(char *) * (i + 1));
	if (!strs)
		return (NULL);

	for (i = 0; node; node = node->next, i++)
	{
		str = malloc(_strlen(node->str) + 1);
		if (!str)
		{
			for (j = 0; j < i; j++)
				free(strs[j]);
			free(strs);
			return (NULL);
		}

		str = _strcpy(str, node->str);
		strs[i] = str;
	}

	strs[i] = NULL;
	return (strs);
}

/**
 * print_list - prints all elements of a list_t linked list
 * @head: pointer to the first node
 *
 * Return: The size of the list.
 */
size_t print_list(const list_t *head)
{
	size_t i = 0;

	while (head)
	{
		_puts(convert_number(head->num, 10, 0));
		_putchar(':');
		_putchar(' ');
		_puts(head->str ? head->str : "(nil)");
		_puts("\n");
		head = head->next;
		i++;
	}

	return (i);
}

/**
 * find_node_starts_with - returns the node whose string starts with prefix
 * @head: pointer to the list head
 * @prefix: string to match
 * @c: the next character after the prefix to match
 *
 * Return: The matching node or NULL.
 */
list_t *find_node_starts_with(list_t *head, char *prefix, char c)
{
	char *p = NULL;

	while (head)
	{
		p = starts_with(head->str, prefix);
		if (p && ((c == -1) || (*p == c)))
			return (head);
		head = head->next;
	}

	return (NULL);
}

/**
 * get_node_index - gets the index of a node in the list
 * @head: pointer to the list head
 * @node: pointer to the node
 *
 * Return: The index of the node or -1 if not found.
 */
ssize_t get_node_index(list_t *head, list_t *node)
{
	size_t i = 0;

	while (head)
	{
		if (head == node)
			return (i);
		head = head->next;
		i++;
	}

	return (-1);
}
