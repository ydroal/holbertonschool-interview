#include "lists.h"

/**
 * is_palindrome - checks if a singly linked list is a palindrome
 * @head: pointer to list to check
 * Return: 0 if it is not a palindrome, 1 if it is a palindrome
 */


int is_palindrome(listint_t **head)
{
	listint_t *current = *head;
	int *stack;
	int length = 0; /* ノードの数 */
	int push_limit = length / 2;
	int i;

	if (!head || !*head || !(*head)->next)
		return (1);

	while (current != NULL)
	{
		current = current->next;
		length++;
	}

	stack = (int *)malloc(length * sizeof(int));  /* メモリ領域の確保 */
	if (stack == NULL)
		return (0);

	for (i = 0; i < push_limit; i++)
	{
		stack[i] = current->n;
		current = current->next;
	}

	if (length % 2 != 0)
		current = current->next;

	for (i = push_limit - 1; i >= 0; i--)
	{
		if (stack[i] != current->n)
		{
			free(stack);
			return (0);
		}
		current = current->next;
	}
	free(stack);
	return (1);
}

