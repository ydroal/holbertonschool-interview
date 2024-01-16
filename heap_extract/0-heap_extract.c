#include "binary_trees.h"

/**
 * find_last_node_at_depth - Finds the last node at a given depth recursively
 * @node: Current node to be checked
 * @depth: The depth to search
 * @current_depth: The current depth
 * Return: Pointer to the last node at the each depth
 */
heap_t *find_last_node_at_depth(heap_t *node, int depth, int current_depth)
{
	heap_t *right;

	if (node == NULL || current_depth == depth)
	return (node);

	right = find_last_node_at_depth(node->right, depth, current_depth + 1);
	if (right != NULL)
	return (right);

	return (find_last_node_at_depth(node->left, depth, current_depth + 1));
}

/**
 * find_last_node - find the last level-order node of the heap
 * @root: Pointer to the root node of the heap
 * Return: Pointer to the last level-order node in the heap
 */
heap_t *find_last_node(heap_t *root)
{
	heap_t *node = root;
	int depth = 0;

	if (root == NULL)
		return (NULL);

	while (node->left != NULL)
	{
		depth++;
		node = node->left;
	}

	return (find_last_node_at_depth(root, depth, 0));
}

/**
 * heapify_down - if necessary, swap from the given node and moves downwards
 *              to the root to keep heap conditions (parent > child)
 * @node: Pointer to the node to start heapifying from
 * Return: Nothing
 */

void heapify_down(heap_t *node)
{
	if (node == NULL)
	return;

	while (node->left != NULL)
	{
		heap_t *largest_child = node->left;

		if (node->right != NULL && node->right->n > node->left->n)
			largest_child = node->right;
	}

	if (largest_child->n > node->n)
	{
		int temp = node->n;

		node->n = largest_child->n;
		largest_child->n = temp;
		node = largest_child;
	} else
	{
		break;
	}
}

/**
 * heap_extract - extracts the root node of a Max Binary Heap
 *
 * @root: double pointer to the root node of the heap
 *
 * Return: the value stored in the root node, if the function fails, return 0
 */
int heap_extract(heap_t **root)
{
	int extract;
	heap_t *heap_r, *last;

	if (root == NULL || *root == NULL)
		return (0);

	heap_r = *root;
	extract = heap_r->n;

	if (heap_r->left == NULL && heap_r->right == NULL)
	{
		*root = NULL;
		free(heap_r);
		return (extract);
	}

	last = find_last_node(heap_r);
	if (last == NULL)
		return (0);

	heap_r->n = last->n;

	if (last->parent != NULL)
	{
		if (last->parent->left == last)
			last->parent->left = NULL;
		else
			last->parent->right = NULL;
	}

	free(last);

	heapify_down(heap_r);

	return (extract);
}
