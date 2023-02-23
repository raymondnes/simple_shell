#include "shell.h"


/**
* shell_unsetenv - removes an environment variable
* @args: array of strings
*
* Description: looks through the environ arraym
* finds the variable and removes it by pushing
* successive entries back one element
*
* Return: 0 on success, -1 on error
*/

int shell_unsetenv(char **args)
{
	char *name = args[1], **ep, **sp;
	size_t len = strlen(name), args_len = 0;

	for (args_len = 0; args[args_len]; args_len++)
		;
	if (args_len != 2)
	{
		errno = EINVAL;
		perror("Usage: unsetenv [variable]\n");
		return (-1);
	}

	for (ep = environ; *ep; ep++)
	{
		if (strncmp(*ep, name, len) == 0 && (*ep)[len] == '=')
			for (sp = ep; *sp; sp++)
				*sp = *(sp + 1);
	}
	return (0);
}



/**
* shell_setenv - creates a new environment var
* or modifies a new one.
* @args: array of strings
*
* Description: creates a string 72Gin the format 'name=value'
* and passes that string to putenv
* Return: 0 if successful. -1 on error
*/

int shell_setenv(char **args)
{
	char *name = args[1], *value = args[2], *new_entry;
	int ret, args_len;

	for (args_len = 0; args[args_len]; args_len++)
		;
	if (args_len != 3)
	{

