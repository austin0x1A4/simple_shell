#include "shell.h"

/**
 * my_exit - Exits the shell.
 * @info: Pointer to the info_t struct. Used to maintain a constant
 * function prototype.
 *
 * Return: Exits with a given exit status (0) if info->argv[0] != "exit".
 *         If info->argv[1] is provided, it will be used as the exit status.
 *         Returns 1 and sets info->status to 2 if the argument is not a valid number.
 *         Otherwise, returns -2 and sets info->err_num to the exit status.
 */
int my_exit(info_t *info)
{
    int exit_status_check;

    if (info->argv[1]) /* If there is an exit argument */
    {
        exit_status_check = _erratoi(info->argv[1]);
        if (exit_status_check == -1)
        {
            info->status = 2;
            print_error(info, "Illegal number: ");
            _eputs(info->argv[1]);
            _eputchar('\n');
            return 1;
        }
        info->err_num = _erratoi(info->argv[1]);
        return -2;
    }
    info->err_num = -1;
    return -2;
}

/**
 * my_cd - Changes the current directory of the process.
 * @info: Pointer to the info_t struct. Used to maintain a constant
 * function prototype.
 *
 * Return: Always returns 0.
 */
int my_cd(info_t *info)
{
    char *current_dir, *dir, buffer[1024];
    int chdir_ret;

    current_dir = getcwd(buffer, 1024);
    if (!current_dir)
        _puts("TODO: >>getcwd failure emsg here<<\n");

    if (!info->argv[1])
    {
        dir = _getenv(info, "HOME=");
        if (!dir)
            chdir_ret = chdir((dir = _getenv(info, "PWD=")) ? dir : "/");
        else
            chdir_ret = chdir(dir);
    }
    else if (_strcmp(info->argv[1], "-") == 0)
    {
        if (!_getenv(info, "OLDPWD="))
        {
            _puts(current_dir);
            _putchar('\n');
            return 1;
        }
        _puts(_getenv(info, "OLDPWD="));
        _putchar('\n');
        chdir_ret = chdir((dir = _getenv(info, "OLDPWD=")) ? dir : "/");
    }
    else
        chdir_ret = chdir(info->argv[1]);

    if (chdir_ret == -1)
    {
        print_error(info, "can't cd to ");
        _eputs(info->argv[1]);
        _eputchar('\n');
    }
    else
    {
        _setenv(info, "OLDPWD", _getenv(info, "PWD="));
        _setenv(info, "PWD", getcwd(buffer, 1024));
    }

    return 0;
}

/**
 * my_help - Displays help information.
 * @info: Pointer to the info_t struct. Used to maintain a constant
 * function prototype.
 *
 * Return: Always returns 0.
 */
int my_help(info_t *info)
{
    char **arg_array;

    arg_array = info->argv;
    _puts("help call works. Function not yet implemented \n");
    if (0)
        _puts(*arg_array); /* temp att_unused workaround */

    return 0;
}
