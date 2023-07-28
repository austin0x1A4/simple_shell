#include "shell.h"

/**
 * is_cmd - determines if a file is an executable command
 * @info: the info struct (not used in this implementation)
 * @path: path to the file
 *
 * Return: 1 if true, 0 otherwise
 */
int is_cmd(info_t *info __attribute__((unused)), char *path)
{
	struct stat st;

	if (!path || stat(path, &st) != 0)
		return 0;

	return S_ISREG(st.st_mode) && (st.st_mode & S_IXUSR);
}

/**
 * find_path - finds this cmd in the PATH string
 * @info: the info struct (not used in this implementation)
 * @pathstr: the PATH string
 * @cmd: the cmd to find
 *
 * Return: full path of cmd if found or NULL
 */
char *find_path(info_t *info __attribute__((unused)), char *pathstr, char *cmd)
{
	char *path = NULL;
	char *token = NULL;
	char *saveptr = NULL;

	if (!pathstr || !cmd)
		return NULL;

	token = _strtok_r(pathstr, ":", &saveptr);
	while (token != NULL)
	{
		size_t path_len = _strlen(token);
		size_t cmd_len = _strlen(cmd);
		path = malloc(path_len + cmd_len + 2); // 1 for '/' and 1 for null terminator

		if (path == NULL)
			return NULL;

		_strcpy(path, token);
		_strcat(path, "/");
		_strcat(path, cmd);

		if (is_cmd(info, path))
			return path;

		free(path);
		path = NULL;

		token = _strtok_r(NULL, ":", &saveptr);
	}

	return NULL;
}
