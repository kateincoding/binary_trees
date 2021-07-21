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
	chd_left->right = tree;

	return (chd_left);
}
