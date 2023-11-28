#include "search.h"
#include <math.h>

/**
 * print_skiplist - Prints a skiplist
 * @list: pointer to the head of the skiplist
 *
 * Return: Nothing
 */

void print_skiplist(const skiplist_t *list)
{
	if (!list)
		return;

	const skiplist_t *head = list;
	size_t size = 0;

	printf("List :\n");
	while (head)
	{
		printf("Index[%lu] = [%d]\n", head->index, head->n);
		head = head->next;
		size++;
	}

	head = list;
	size_t step = sqrt(size);
	printf("Express lane :\n");
	while (head) {
		if (head->index % step == 0 || head->index == 0)
			printf("Index[%lu] = [%d]\n", head->index, head->n);
        	head = head->next;
    	}
}

/**
 * free_skiplist - Frees a skiplist
 * @list: pointer to the head of the skiplist to be freed
 *
 * Return: Nothing
 */

void free_skiplist(skiplist_t *list)
{
	skiplist_t *tmp = NULL;
	while (list)
	{
		tmp = list->next;
		free(list);
		list = tmp;
	}
}

/**
 * create_skiplist - Creates a new skiplist
 * @array: int array
 * @size: size of array
 *
 * Return: pointer to the new node, or NULL on failure
 */

skiplist_t *create_skiplist(int *array, size_t size)
{
	skiplist_t *list = NULL;
	skiplist_t *node;
	skiplist_t *next_node = NULL;

	for (; size > 0; size--)
	{
		node = malloc(sizeof(skiplist_t));
		if (!node)
		{
			free_skiplist(list);
			return (NULL);
		}

		node->n = array[size - 1];
		node->index = size - 1;
		node->next = next_node;
		node->express = NULL;
		next_node = node;
		list = node; // 新しいノードがリストの新しい先頭になる
	}
	return (list);
}

