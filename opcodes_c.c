#include "monty.h"

/**
 * mod - Computes the mod of first two nodes on the stack, removes first node
 * @h: Pointer to the top of the stack
 * @l_num: line count
 */
void mod(stack_t **h, unsigned int l_num)
{
	stack_t *temp = *h;

	if (*h == NULL || (*h)->next == NULL)
	{
		printf("L%d: can't mod, stack too short\n", l_num);
		exit(EXIT_FAILURE);
	}
	if (temp->n == 0)
	{
		printf("L%d: division by zero\n", l_num);
		exit(EXIT_FAILURE);
	}
	temp->next->n %= temp->n;
	temp->next->prev = NULL;
	*h = temp->next;
	free(temp);
}

/**
 * pchar - Prints char at the top of the stack
 * @h: Pointer to the top of the stack
 * @l_num: line count
 */
void pchar(stack_t **h, unsigned int l_num)
{
	stack_t *temp = *h;

	if (*h == NULL)
	{
		printf("L%d: can't pchar, stack empty\n", l_num);
		exit(EXIT_FAILURE);
	}
	if (temp->n < 0 || temp->n > 127)
	{
		printf("L%d: can't pchar, value out of range\n", l_num);
		exit(EXIT_FAILURE);
	}
	putchar(temp->n);
	putchar('\n');
}

/**
 * pstr - Prints string starting at the top of the stack
 * @h: Pointer to the top of the stack
 * @l_num: line count
 */
void pstr(stack_t **h, unsigned int l_num)
{
	stack_t *temp = *h;

	while (temp != NULL && !(temp->n <= 0 || temp->n > 127))
	{
		putchar(temp->n);
		temp = temp->next;
	}
	l_num = l_num;
	putchar('\n');
}
