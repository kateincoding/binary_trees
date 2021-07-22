#include "binary_trees.h"

/**
 * binary_tree_rotate_right - Performs a right rotation on a tree
 * @tree: Pointer to trees' root
 *
 * Return: Pointer to the new root
 */
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	binary_tree_t *child, *parent = tree;

	if (!tree)
		return (NULL);

	child = parent->left;
	if (!child)
		return (tree);

	if (child->right)
		child->right->parent = parent;

	parent->left = child->right;
	child->right = parent;
	child->parent = parent->parent;
	parent->parent = child;

	if (child->parent && child->parent->left == parent)
		child->parent->left = child;
	else if (child->parent)
		child->parent->right = child;

	return (child);
}
