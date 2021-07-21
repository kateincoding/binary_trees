#include "binary_trees.h"

/**
 * binary_tree_size - Count the number of nodes in a tree
 * @tree: Pointer to tree's root
 *
 * Return: Trees' size
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	size_t count = 1;

	if (!tree)
		return (0);

	count += binary_tree_size(tree->left);
	count += binary_tree_size(tree->right);

	return (count);
}
