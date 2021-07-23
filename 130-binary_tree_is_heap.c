#include "binary_trees.h"

/**
 * binary_tree_is_heap - Checks if a binary tree is a valid Max Heap
 * @tree: Pointer to tree's node
 *
 * Return: 1 if the tree is a max heap, 0 otherwise
 */
int binary_tree_is_heap(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	if (!tree->left && !tree->right)
		return (1);
	if (!tree->left || !tree->right)
		return (0);
	if (tree->left->n > tree->n || tree->right->n > tree->n)
		return (0);

	return (binary_tree_is_heap(tree->left) &&
		binary_tree_is_heap(tree->right));
}
