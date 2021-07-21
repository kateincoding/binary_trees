#include "binary_trees.h"

/**
 * binary_tree_height_balance - Calculates the height of a tree
 * @tree: Pointer to tree's root
 *
 * Return: Trees' height
 */
size_t binary_tree_height_balance(const binary_tree_t *tree)
{
	size_t hleft = 0, hright = 0;

	if (!tree)
		return (0);

	if (tree->left)
		hleft = 1 + binary_tree_height_balance(tree->left);
	if (tree->right)
		hright = 1 + binary_tree_height_balance(tree->right);

	if (hleft > hright)
		return (hleft);
	return (hright);
}

/**
 * binary_tree_balance - function that measures the
 * balance factor of a binary tree
 * @tree: pointer to the root node of the tree to
 * measure the balance factor
 * Return: balance factor
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	size_t hleft = 0, hright = 0;

	if (!tree)
		return (0);
	if (tree->left)
		hleft = 1 + binary_tree_height_balance(tree->left);
	if (tree->right)
		hright = 1 + binary_tree_height_balance(tree->right);
	return (hleft - hright);
}
