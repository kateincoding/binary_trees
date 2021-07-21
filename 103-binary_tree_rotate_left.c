#include "binary_trees.h"

/**
 * binary_tree_rotate_left - Performs a left rotation on a tree
 * @tree: Pointer to trees' root
 *
 * Return: Pointer to the new root
 */
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *chd_right, *pnode;

	if (!tree)
		return (NULL);

	if (!tree->right)
		return (tree);

	chd_right = tree->right;

	tree->right = chd_right->left;
	if (tree->right)
		tree->right->parent = tree;

	chd_right->left = tree;
	chd_right->parent = tree->parent;

	pnode = tree->parent;
	tree->parent = chd_right;

	if (pnode && pnode->left == tree)
		pnode->left = chd_right;
	else if (pnode && pnode->right == tree)
		pnode->right = chd_right;

	return (chd_right);
}
