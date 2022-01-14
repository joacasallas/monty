#include "monty.h"

/**
 * check_argc - Checks arguments
 * @ac: argument count
 */
void check_argc(int ac)
{
	if (ac != 2)
	{
		printf("USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
}

/**
 * cleanup - frees memory and closes file
 * @ln: memory used by getline
 * @h: head of a stack_t list
 * @f: file that is open
 * Return: void
 */
void cleanup(char *ln, stack_t **h, FILE *f)
{
	free(ln);
	free_m(h);
	fclose(f);
}
/**
 * _isdigit - checks if string is a number
 * @s: string
 * Return: 0 on sucess, else -1
 */
int _isdigit(char *s)
{
	int i = 0;

	if (s == NULL)
		return (-1);
	for (i = 0; s[i] != '\0'; i++)
	{
		if (s[0] == '-')
			continue;
		if (s[i] < '0' || s[i] > '9')
			return (-1);
	}
	return (0);
}
