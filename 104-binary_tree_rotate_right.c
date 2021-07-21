#include "binary_trees.h"

/**
 * binary_tree_rotate_right - Performs a right rotation on a tree
 * @tree: Pointer to trees' root
 *
 * Return: Pointer to the new root
 */
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	binary_tree_t *chd_left;

	if (!tree)
		return (NULL);

	if (!tree->left)
		return (tree);

	chd_left = tree->left;

	tree->left = chd_left->right;
	if (tree->left)
		tree->left->parent = tree;

	chd_left->right = tree;
	chd_left->parent = tree->parent;
	tree->parent = chd_left;

	return (chd_left);
}
