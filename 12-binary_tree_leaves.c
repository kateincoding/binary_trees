#include "binary_trees.h"

/**
 * binary_tree_leaves - function that counts the leaves in a binary tree
 * @tree: pointer to the root node of the tree to count the number of leaves
 * Return: count_leaves
 */
size_t binary_tree_leaves(const binary_tree_t *tree)
{
	size_t count_leaves = 0;

	if (!tree)
		return (0);
	if (!(tree->left) && !(tree->right))
		return (1);

	count_leaves += binary_tree_leaves(tree->left);
	count_leaves += binary_tree_leaves(tree->right);

	return (count_leaves);
}
