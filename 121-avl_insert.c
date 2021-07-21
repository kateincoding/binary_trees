#include "binary_trees.h"

/**
 * balance_tree - Balances a tree
 * @root: Pointer to tree's root node
 * @value: Integer to make the comparissons with
 */
void balance_tree(avl_t *root, int value)
{
	int bf; /* balance factor */

	if (!root)
		return;

	bf = binary_tree_balance(root);

	if (bf > 1 && value < root->left->n)
		binary_tree_rotate_right(root);
	else if (bf < -1 && value > root->right->n)
		binary_tree_rotate_left(root);
	else if (bf > 1 && value > root->left->n)
	{
		binary_tree_rotate_left(root->left);
		binary_tree_rotate_right(root);
	}
	else if (bf < -1 && value < root->right->n)
	{
		binary_tree_rotate_right(root->right);
		binary_tree_rotate_left(root);
	}
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
		parent = curr;
		if (value == curr->n)
			return (NULL);
		if (value < curr->n)
			curr = curr->left;
		else
			curr = curr->right;
	}

	new_node = binary_tree_node(parent, value);
	if (!parent)
		*tree = new_node;
	else if (value < parent->n)
		parent->left = new_node;
	else
		parent->right = new_node;

	while (parent)
	{
		balance_tree(parent, value);
		parent = parent->parent;
	}

	return (new_node);
}
