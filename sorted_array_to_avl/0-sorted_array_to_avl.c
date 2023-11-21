#include "binary_trees.h"

/**
 * create_node - Creates a new AVL tree node
 * @parent: parent node
 * @value: value to put in the new node
 *
 * Return: pointer to the new node, or NULL on failure
 */
binary_tree_t *create_node(binary_tree_t *parent, int value)
{
	binary_tree_t *node;

	node = malloc(sizeof(binary_tree_t));

	if (!node)
		return (NULL);

	node->n = value;
	node->parent = parent;
	node->left = NULL;
	node->right = NULL;

	return (node);
}

/**
 * insert_node - insert a node
 * @array: pointer to the first element of the array to be converted
 * @parent: parent node
 * @start: start index of the array
 * @end: end index of the array
 *
 * Return: pointer to the root node of the created AVL tree, or NULL on failure
 */
binary_tree_t *insert_node(int *array, binary_tree_t *parent,
	 int start, int end)
{
	int mid;
	binary_tree_t *root;

	if (start > end)
		return (NULL);

	mid = (start + end) / 2;
	root = create_node(parent, array[mid]);

	if (!root)
		return (NULL);

	root->left = insert_node(array, root, start, mid - 1);
	root->right = insert_node(array, root, mid + 1, end);

	return (root);
}

/**
 * sorted_array_to_avl - Builds an AVL tree from an array
 * @array: pointer to the first element of the array to be converted
 * @size: number of element in the array
 *
 * Return: pointer to the root node of the created AVL tree, or NULL on failure
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	if (!array || size == 0)
		return (NULL);

	return ((avl_t *)insert_node(array, NULL, 0, size - 1));
}
