#include "binary_trees.h"

/**
 * binary_tree_height - measures the height of the binary tree
 * @tree: pointer to the root node of the tree
 *
 * Return: height of the tree
*/

size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t lh, rh;

	if (tree == NULL)
		return (0);

	lh = binary_tree_height(tree->left);
	rh = binary_tree_height(tree->right);
	return ((lh > rh ? lh : rh) + 1);
}
/**
  * is_bst - checks if a binary tree is a bst
  * @tree: a pointer to the root node of the tree to check
  * @min: a pointer to the parent node of the tree to check
  * @max: a pointer to the parent node of the tree to check
  *
  * Return: 1 if tree is a bst, and 0 otherwise
*/

int is_bst(const binary_tree_t *tree, const binary_tree_t *min,
	 const binary_tree_t *max)
{
	if (tree == NULL)
		return (1);

	if (min != NULL && tree->n <= min->n)
		return (0);
	if (max != NULL && tree->n >= max->n)
		return (0);

	return (is_bst(tree->left, min, tree) && is_bst(tree->right, tree, max));
}
/**
  * binary_tree_is_avl - checks if a binary tree is a valid AVL Tree
  * @tree: a pointer to the root node of the tree to check
  * Return: 1 if tree is a valid AVL Tree, and 0 otherwise
*/
int binary_tree_is_avl(const binary_tree_t *tree)
{
	size_t lh, rh;
	int balance_factor;

	if (tree == NULL)
		return (0);

	lh = binary_tree_height(tree->left);
	rh = binary_tree_height(tree->right);
	balance_factor = lh > rh ? (lh - rh) : (rh - lh);
	if (balance_factor > 1)
		return (0);

	if ((tree->left && !binary_tree_is_avl(tree->left)) ||
		(tree->right && !binary_tree_is_avl(tree->right)))
		return (0);

	return (is_bst(tree, NULL, NULL));
}
