#include "monty.h"

/**
 * main - main function
 * @argc: number of arguments
 * @argv: arguments
 * Return: 0 on success
 */
int main(int argc, char **argv)
{
	FILE *fp; size_t file_size; unsigned int l_num = 1;
	char *opc = NULL, *ins = NULL, *line = NULL; stack_t *head;

	head = NULL;
	check_argc(argc);
	fp = fopen(argv[1], "r");
	if (fp == NULL)
	{
		printf("Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while ((getline(&line, &file_size, fp)) != -1)
	{
		opc = strtok(line, "\n\t\r ");
		if (opc != NULL)
		{
			ins = strtok(NULL, "\n\t\r ");
			if (_isdigit(ins) == 0 && strcmp("push", opc) == 0 && opc[0] != '#')
				push(&head, atoi(ins));
			else if (strcmp("push", opc) != 0 && opc[0] != '#')
				_struct(opc, &head, l_num);
			else if (opc[0] != '#')
			{
				printf("L%d: usage: push integer\n", l_num);
				exit(EXIT_FAILURE);
			}
		}
		l_num++;
	}
	cleanup(line, &head, fp);
	return (0);
}
