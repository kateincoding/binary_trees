#include "binary_trees.h"

/**
 * binary_tree_rotate_right - Performs a right rotation on a tree
 * @tree: Pointer to trees' root
 *
 * Return: Pointer to the new root
 */
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	binary_tree_t *chd_left, *pnode;

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

	pnode = tree->parent;
	tree->parent = chd_left;

	if (pnode && pnode->left == tree)
		pnode->left = chd_left;
	else if (pnode && pnode->right == tree)
		pnode->right = chd_left;

	return (chd_left);
}
