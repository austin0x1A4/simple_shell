#include "shell.h"

/**
 * print_history - Displays the history list, one command per line, preceded
 *                 with line numbers, starting at 0.
 * @info: Pointer to the info_t struct. Used to maintain a constant function prototype.
 *
 * Return: Always returns 0.
 */
int print_history(info_t *info)
{
    print_list_str(info->history);
    return 0;
}

/**
 * unset_alias - Unsets an alias by removing it from the alias list.
 * @info: Pointer to the info_t struct.
 * @alias: The alias string to be unset.
 *
 * Return: Always returns 0 on success, 1 on error.
 */
int unset_alias(info_t *info, char *alias)
{
    char *p, c;
    int ret;

    p = _strchr(alias, '=');
    if (!p)
        return 1;

    c = *p;
    *p = 0;
    ret = delete_node_at_index(&(info->alias),
        get_node_index(info->alias, node_starts_with(info->alias, alias, -1)));
    *p = c;

    return ret;
}

/**
 * set_alias - Sets an alias to the given string.
 * @info: Pointer to the info_t struct.
 * @alias: The alias string to be set.
 *
 * Return: Always returns 0 on success, 1 on error.
 */
int set_alias(info_t *info, char *alias)
{
    char *p;

    p = _strchr(alias, '=');
    if (!p)
        return 1;

    if (!*++p)
        return unset_alias(info, alias);

    unset_alias(info, alias);
    return (add_node_end(&(info->alias), alias, 0) == NULL);
}

/**
 * print_alias - Prints an alias string.
 * @node: Pointer to the alias node.
 *
 * Return: Always returns 0 on success, 1 on error.
 */
int print_alias(list_t *node)
{
    char *p = NULL, *a = NULL;

    if (node)
    {
        p = _strchr(node->str, '=');
        for (a = node->str; a <= p; a++)
            _putchar(*a);

        _putchar('\'');
        _puts(p + 1);
        _puts("'\n");
        return 0;
    }

    return 1;
}

/**
 * my_alias - Mimics the alias builtin (man alias).
 * @info: Pointer to the info_t struct.
 *
 * Return: Always returns 0.
 */
int my_alias(info_t *info)
{
    int i = 0;
    char *p = NULL;
    list_t *node = NULL;

    if (info->argc == 1)
    {
        node = info->alias;
        while (node)
        {
            print_alias(node);
            node = node->next;
        }
        return 0;
    }

    for (i = 1; info->argv[i]; i++)
    {
        p = _strchr(info->argv[i], '=');
        if (p)
            set_alias(info, info->argv[i]);
        else
            print_alias(node_starts_with(info->alias, info->argv[i], '='));
    }

    return 0;
}

