#include "binary_trees.h"

/**
 * binary_tree_depth - function that measures the
 * depth of a node in a binary tree
 * @tree: pointer to the node to measure the depth
 * Return: depth_count
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
	size_t depth_count = 0;

	if (!tree)
		return (0);
	if (tree->parent)
		depth_count = 1 + binary_tree_depth(tree->parent);
	return (depth_count);
}
