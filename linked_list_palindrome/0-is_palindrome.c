#include "lists.h"

/**
 * is_palindrome - checks if a singly linked list is a palindrome
 * @head: pointer to list to check
 * Return: 0 if it is not a palindrome, 1 if it is a palindrome
 */

int is_palindrome(listint_t **head)
{
	listint_t *slow = *head;
	listint_t *fast = *head;
	listint_t *prev, *next, *second_half;

	if (!head || !*head || !(*head)->next)
		return (1);

	/* スタックのサイズを測定（リストの半分） */
	while (fast != NULL && fast->next != NULL)
	{
		fast = fast->next->next; /* 2ノードずつ(fastが末端時slowは中間)*/
		slow = slow->next; /* slowは1ノードずつ進める */
	}
	/* 偶数か奇数かで後半のノード探索スタート位置を決定 */
	if (fast != NULL) /* リストが奇数 */
		second_half = slow->next;
	else
		second_half = slow;

	/* 後半部分のリストを逆転させる */
	prev = NULL;
	while (second_half != NULL)
	{
		next = second_half->next;
		second_half->next = prev;
		prev = second_half;
		second_half = next;
	}
	second_half = prev; /* 逆転させたリストの先頭をささせる */
	next = *head; /* 元のリストの先頭をささせる */
	while (second_half != NULL)
	{
		if (next->n != second_half->n)
		{
			return (0);
		}
		next = next->next;
		second_half = second_half->next;
	}
	return (1);
}
