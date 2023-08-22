#include <stdlib.h>
#include "lists.h"

/**
 * insert_node - inserts a number into a sorted singly linked list
 * @head: pointer to head of list
 * @number: number to insert into a list
 * Return: the address of the new node, or NULL if it failed
 */
listint_t *insert_node(listint_t **head, int number)
{
	listint_t *new;
	listint_t *current;
	listint_t *prev;

	current = *head;
	prev = NULL;

	new = malloc(sizeof(listint_t));
	if (new == NULL)
		return (NULL);

	new->n = number;
	new->next = NULL;

	if (*head == NULL)
	{
		*head = new;
		return (new);
	}

	if ((*head)->n > number)
	{
		new->next = *head;
		*head = new;
		return (new);
	}

	while (current != NULL && current->n < number)
	{
		prev = current;
		current = current->next;
	}
	prev->next = new;
	new->next = current;

	return (new);
}

