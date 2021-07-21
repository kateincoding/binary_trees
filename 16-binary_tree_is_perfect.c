#include "binary_trees.h"

/**
 * find_left_depth - function that measures the
 * depth of a node in a binary tree
 * @tree: pointer to the node to measure the depth
 * Return: depth_count
 */
size_t find_left_depth(const binary_tree_t *tree)
{
	size_t depth_count = 1;

	if (!tree)
		return (0);
	if (tree->left)
		depth_count = 1 + find_left_depth(tree->left);
	return (depth_count);
}

/**
 * is_perfect - checks if a binary tree is perfect with recursion
 * @tree: pointer to the root node of the tree to check
 * @d: depth of the left size
 * @level: level of tree, it starts with 0
 * Return: If tree is NULL, your function must return 0
 */
int is_perfect(const binary_tree_t *tree, int d, int level)
{
	if (!tree)
		return (0);
	if (tree->left == NULL && tree->right == NULL)
		return (d == level + 1);
	/* If internal node and one child is empty */
	if (tree->left == NULL || tree->right == NULL)
		return (0);
	/* Left and right subtrees must be perfect */
	return (is_perfect(tree->left, d, level + 1)
			&& is_perfect(tree->right, d, level + 1));
}

/**
 * binary_tree_is_perfect - checks if a binary tree is perfect
 * 1) All leaves are at same level
 * 2) All internal nodes have two childre
 * @tree: pointer to the root node of the tree to check
 * Return: If tree is NULL, your function must return 0
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	int d = find_left_depth(tree);

	return (is_perfect(tree, d, 0));
}
