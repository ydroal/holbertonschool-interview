#include "binary_trees.h"

/**
 * heapify_up - if necessary, swap from the given node and moves upwards
 *              to the root to keep heap conditions (parent > child)
 * @node: pointer to the node of the Heap
 * Return: pointer to the newly positioned node, or NULL on failure
 */

heap_t *heapify_up(heap_t *node)
{
	int temp;

	if (node == NULL || node->parent == NULL)
	{
		return (node);
	}

	if (node->parent->n < node->n)
	{
		temp = node->n;
		node->n = node->parent->n;
		node->parent->n = temp;

		/* 新しい親ノードでheapify_upを再帰的に呼び出す */
		return (heapify_up(node->parent));
	}

	return (node);
}

/**
 * find_insert_node - finds the appropriate position for the new node
 * and inserts the node at that position
 * @root: double pointer to the root node of the Heap
 * @value: value to store in the node to be inserted
 * Return: pointer to the inserted node, or NULL on failure
 */

heap_t *find_insert_node(heap_t **root, int value)
{
	binary_tree_t *node = *root;

	/* 左の子がいない場合*/
	if (node->left == NULL)
	{
		node->left = binary_tree_node(node, value);
		return (node->left);
	}
	else if (node->right == NULL)
	{
		node->right = binary_tree_node(node, value);
		return (node->right);
	}
	else
	{
		binary_tree_t *new_node;

		new_node = find_insert_node(&(node->left), value);
		if (new_node == NULL)
		{
			new_node = find_insert_node(&(node->right), value);
		}
		return (new_node);
	}
}

/**
 * heap_insert - inserts a value into a Max Binary Heap
 * @root: double pointer to the root node of the Heap
 * @value: value to store in the node to be inserted
 * Return: pointer to the inserted node, or NULL on failure
 */

heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *new;

	if (root == NULL)
		return (NULL);

	if (*root == NULL)
	{
		*root = binary_tree_node(NULL, value);
		return (*root);
	}

	new = find_insert_node(root, value);
	if (new == NULL)
		return (NULL);

	return (heapify_up(new));
}

