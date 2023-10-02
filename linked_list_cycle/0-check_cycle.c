#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * check_cycle - checks if a singly linked list has a cycle in it
 * @list: singly linked list
 * Return: 0 if there is no cycle, 1 if there is a cycle
 */
int check_cycle(listint_t *list)
{
	listint_t *slow = list;
	listint_t *fast = list;

	if (!list)
		return (0);

	while (fast != NULL && fast->next != NULL)
	{
		fast = fast->next->next; /* 2ノードずつ(fastが末端時slowは中間)*/
		slow = slow->next; /* slowは1ノードずつ進める */

		if (fast == slow)
			return (1);
	}
	return (0);
}
