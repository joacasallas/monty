#include "monty.h"

/**
 * push - creates a linked list which holds an integer data type
 * @head: head of linked list
 * @n: data type inside of node of type integer
 * Return: returns the newly created node and adds to list
 */
stack_t *push(stack_t **head, int n)
{
	stack_t *new_node = NULL;

	new_node = malloc(sizeof(stack_t));
	if (head == NULL || new_node == NULL)
	{
		printf("Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	new_node->n = n;
	new_node->next = *head;
	new_node->prev = NULL;
	if (*head != NULL)
	{
		(*head)->prev = new_node;
	}
	*head = new_node;
	return (new_node);
}

/**
 * pall - Prints all elements on the stack
 * @h: pointer to head of the stack list
 * @l_num: line number of .m file
 * Return: void
 */
void pall(stack_t **h, unsigned int l_num)
{
	stack_t *temp = *h;

	while (temp)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
	l_num = l_num;
}

/**
 * pint - Prints the value at the top of the stack
 * @h: pointer to head of the stack list
 * @l_num: line number of .m file
 * Return: void
 */
void pint(stack_t **h, unsigned int l_num)
{
	if ((*h) == NULL || h == NULL)
	{
		printf("L%d: can't pint, stack empty\n", l_num);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*h)->n);
	l_num++;
}


/**
 * pop - Removes th e top element of the stack
 * @h: pointer to head of the stack list
 * @l_num: line number of .m file
 * Return: void
 */
void pop(stack_t **h, unsigned int l_num)
{
	stack_t *top = *h;

	if (*h == NULL)
	{
		printf("L%d: can't pop an empty stack\n", l_num);
		exit(EXIT_FAILURE);
	}
	if (top->next)
		top->next->prev = NULL;
	*h = top->next;
	l_num++;
	free(top);
}

/**
 * nop - Does nothing
 * @h: pointer to top of stack
 * @l_num: line number
 * Return: void
 */
void nop(stack_t **h, unsigned int l_num)
{
	l_num = l_num;
	*h = *h;
}
