#include "binary_trees.h"

/**
 * balance_tree - Balances a tree
 * @tree: Double pointer to tree's root
 * @node: Pointer to tress node
 * @value: Integer to make the comparissons with
 */
void balance_tree(avl_t **tree, avl_t *node, int value)
{
	int bf; /* balance factor */
	avl_t *new_root = NULL;

	if (!node || (!node->left && !node->right))
		return;

	bf = binary_tree_balance(node);

	if (bf > 1 && node->left && value < node->left->n)
		new_root = binary_tree_rotate_right(node);
	else if (bf < -1 && node->right && value > node->right->n)
		new_root = binary_tree_rotate_left(node);
	else if (bf > 1 && node->left && value > node->left->n)
	{
		binary_tree_rotate_left(node->left);
		new_root = binary_tree_rotate_right(node);
	}
	else if (bf < -1 && node->right && value < node->right->n)
	{
		binary_tree_rotate_right(node->right);
		new_root = binary_tree_rotate_left(node);
	}

	if (new_root && new_root->parent == NULL)
		*tree = new_root;
}

/**
 * avl_insert - Inserts a value in an AVL tree
 * @tree: Pointer to trees' root
 * @value: Value to insert
 *
 * Return: Pointer to the newly created node
 */
avl_t *avl_insert(avl_t **tree, int value)
{
	avl_t *parent = NULL, *curr, *new_node;

	if (!tree)
		return (NULL);

	curr = *tree;
	while (curr)
	{
		if (value == curr->n)
			return (curr);

		parent = curr;
		if (value < curr->n)
			curr = curr->left;
		else
			curr = curr->right;
	}

	new_node = binary_tree_node(parent, value);
	if (!(*tree))
		*tree = new_node;
	else if (value < parent->n)
		parent->left = new_node;
	else
		parent->right = new_node;

	while (parent)
	{
		balance_tree(tree, parent, value);
		parent = parent->parent;
	}

	return (new_node);
}
