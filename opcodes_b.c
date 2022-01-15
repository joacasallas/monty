#include "monty.h"

/**
 * swap - swaps the data in the first two nodes
 * @h: Pointer to the top of the stack
 * @l_num: line number
 * Return: line number
 */
void swap(stack_t **h, unsigned int l_num)
{
	int temp;

	if (*h == NULL || (*h)->next == NULL)
	{
		printf("L%d: can't swap, stack too short\n", l_num);
		exit(EXIT_FAILURE);
	}
	temp = (*h)->n;
	(*h)->n = (*h)->next->n;
	(*h)->next->n = temp;
}

/**
 * add - Adds the first two nodes on the stack, removes first node
 * @h: Pointer to the top of the stack
 * @l_num: line count
 */
void add(stack_t **h, unsigned int l_num)
{
	stack_t *temp = *h;

	if (*h == NULL || (*h)->next == NULL)
	{
		printf("L%d: can't add, stack too short\n", l_num);
		exit(EXIT_FAILURE);
	}
	temp->next->n += temp->n;
	temp->next->prev = NULL;
	*h = temp->next;
	free(temp);
}

/**
 * sub - Subtracts the first two nodes on the stack, removes first node
 * @h: Pointer to the top of the stack
 * @l_num: line count
 */
void sub(stack_t **h, unsigned int l_num)
{
	stack_t *temp = *h;

	if (*h == NULL || (*h)->next == NULL)
	{
		printf("L%d: can't sub, stack too short\n", l_num);
		exit(EXIT_FAILURE);
	}
	temp->next->n -= temp->n;
	temp->next->prev = NULL;
	*h = temp->next;
	free(temp);
}

/**
 * div_m - Divides the first two nodes on the stack, removes first node
 * @h: Pointer to the top of the stack
 * @l_num: line count
 */
void div_m(stack_t **h, unsigned int l_num)
{
	stack_t *temp = *h;

	if (*h == NULL || (*h)->next == NULL)
	{
		printf("L%d: can't div, stack too short\n", l_num);
		exit(EXIT_FAILURE);
	}
	if (temp->n == 0)
	{
		printf("L%d: division by zero\n", l_num);
		exit(EXIT_FAILURE);
	}
	temp->next->n /= temp->n;
	temp->next->prev = NULL;
	*h = temp->next;
	free(temp);
}

/**
 * mul - Multiplies the first two nodes on the stack, removes first node
 * @h: Pointer to the top of the stack
 * @l_num: line count
 */
void mul(stack_t **h, unsigned int l_num)
{
	stack_t *temp = *h;

	if (*h == NULL || (*h)->next == NULL)
	{
		printf("L%d: can't mul, stack too short\n", l_num);
		exit(EXIT_FAILURE);
	}
	temp->next->n *= temp->n;
	temp->next->prev = NULL;
	*h = temp->next;
	free(temp);
}
