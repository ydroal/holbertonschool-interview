#include "search.h"
#include <math.h>

/**
 * set_express_lanes - Set an express lanes
 * @list: pointer to the head of the skiplist
 * @size: pointer to the head of the skiplist
 *
 * Return: pointer on the first node where value is located
 */
void set_express_lanes(skiplist_t *list, size_t size)
{
	if (!list || size == 0)
		return;

	size_t step = sqrt(size);
	size_t index = 0;
	skiplist_t *node = list;
	skiplist_t *express_node = list;

	while (node)
	{
		if (index % step == 0)
		{
			express_node->express = node;
			express_node = node;
		}
		index++;
		node = node->next;
	}
}

/**
 * get_length - Get the number of node
 * @list: pointer to the head of the skiplist
 *
 * Return: The number of node in skiplist
 */

size_t get_length(skiplist_t *list)
{
	size_t size = 0;

	while (list)
	{
		size++;
		list = list->next;
	}
	return (size);
}

/**
 * linear_skip - Searches for a value in a sorted skip list of integers
 * @head: pointer to the head of the skiplist
 * @value: pointer to the head of the skiplist
 *
 * Return: pointer on the first node where value is located
 */
skiplist_t *linear_skip(skiplist_t *head, int value)
{
	if (!head)
		return (NULL);
	skiplist_t *list = head;
	size_t size = get_length(list);

	set_express_lanes(head, size);
	skiplist_t *node = head->express;
	skiplist_t *prev = head;

	while (node)
	{
		printf("Value checked at index [%lu] = [%d]\n", node->index, node->n);
		if (node->n == value)
			return (node);
		if (node->n > value)
			break;
		prev = node;
		if (node->express == NULL)
		{
			while (node->next)
				node = node->next;
			break;
		}
		node = node->express;
	}
	if (node)
		printf("Value found between indexes [%lu] and [%lu]\n",
		prev->index, node->index);
	node = prev;
	while (node)
	{
		printf("Value checked at index [%lu] = [%d]\n", node->index, node->n);
		if (node->n == value)
			return (node);
		node = node->next;
	}
	return (NULL);
}
