#include "monty.h"

/**
 * free_m - free all nodes
 * @head: head node
 * Return: void
 */
void free_m(stack_t **head)
{
	stack_t *temp;

	temp = *head;

	while (temp)
	{
		temp = (*head)->next;
		free(*head);
		*head = temp;
	}
}
