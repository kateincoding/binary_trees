#include "binary_trees.h"

/**
 * bst_insert - Inserts a new node into a tree
 * @tree: Pointer to trees' root
 * @value: Value for the new node
 *
 * Return: Pointer to the newly created node
 */
bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *prev_parent, *parent, *new_node;

	if (!tree)
		return (NULL);

	prev_parent = NULL;
	parent = *tree;
	while (parent)
	{
		prev_parent = parent;
		if (value == parent->n)
			return (NULL);

		if (value < parent->n)
			parent = parent->left;
		else
			parent = parent->right;
	}

	new_node = binary_tree_node(prev_parent, value);

	if (!prev_parent)
		*tree = new_node;
	else if (value < prev_parent->n)
		prev_parent->left = new_node;
	else
		prev_parent->right = new_node;

	return (new_node);
}
