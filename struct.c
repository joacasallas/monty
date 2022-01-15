#include "monty.h"

/**
 * _struct - loop through array of structs and call matching string/function
 * @str: input string grabbed from .m file, string checked if match occurs
 * @head: head node of the linked list which represents the stack
 * @l_num: line number
 * Return: 1 on successful function call, -1 if no function is called
 */
int _struct(char *str, stack_t **head, unsigned int l_num)
{
	instruction_t inst[] = {
		{"pall", pall}, {"pint", pint},
		{"pop", pop}, {"swap", swap},
		{"add", add}, {"sub", sub},
		{"mul", mul}, {"div", div_m},
		{"mod", mod}, {"nop", nop},
		{"pchar", pchar}, {"pstr", pstr},
		{NULL, NULL}
	};

	int i = 0;

	while (inst[i].opcode != NULL)
	{
		if (strcmp(str, inst[i].opcode) == 0)
		{
			(inst[i].f)(head, l_num);
			return (EXIT_SUCCESS);
		}
		i++;
	}
	printf("L%d: unknown instruction %s\n", l_num, str);
	exit(EXIT_FAILURE);
}
