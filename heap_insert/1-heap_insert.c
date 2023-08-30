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

/* 配列 (queue）を用いて幅優先探索（BFS）を行う */
heap_t *find_insert_node(heap_t **root, int value)
{
	heap_t *current = NULL;
	heap_t *queue[1024]; /* 構造体へのポインタの配列 */
	int start = 0; /* キューの先頭インデックス */
	int end = 0; /* キューの末尾インデックス */

	if (!root || !*root)
		return (NULL);

	/* rootをキューに追加 */
	queue[end++] = *root;

	while (start < end)
	{
		current = queue[start++];
		/* 左の子がいない場合はそこに挿入 */
		if (!current->left)
		{
			current->left = binary_tree_node(current, value);
			return (current->left);
		}
		else /* 探索キューに左の子ノードを追加 */
		{
			queue[end++] = current->left;
		}

		/* 右の子がいない場合はそこに挿入 */
		if (!current->right)
		{
			current->right = binary_tree_node(current, value);
			return (current->right);
		}
		else /* 探索キューに右の子ノードを追加 */
		{
			queue[end++] = current->right;
		}
	}

	return (NULL); /* ここに到達することはない*/
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

