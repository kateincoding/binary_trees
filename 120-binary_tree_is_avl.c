#include "binary_trees.h"

/**
 * binary_tree_height_auxx - Calculates the height of a tree
 * @tree: Pointer to tree's root
 *
 * Return: Trees' height
 */
size_t binary_tree_height_auxx(const binary_tree_t *tree)
{
	size_t hleft = 0, hright = 0;

	if (!tree)
		return (0);

	if (tree->left)
		hleft = 1 + binary_tree_height_auxx(tree->left);
	if (tree->right)
		hright = 1 + binary_tree_height_auxx(tree->right);

	if (hleft > hright)
		return (hleft);
	return (hright);
}

/**
 * is_balanced - recursive fx that check if it is balanced or not
 * @root: Pointer to tree's root
 * Return: 1 if it is balanced; otherwise 0
 */
int is_balanced(const binary_tree_t *root)
{
	int left_height;
	int right_height;

	/* If tree is empty then return true */
	if (!root)
		return (1);

	/* Get the height of left and right sub trees */
	left_height = binary_tree_height_auxx(root->left);
	right_height = binary_tree_height_auxx(root->right);

	if (abs(left_height - right_height) <= 1 && is_balanced(root->left)
		&& is_balanced(root->right))
		return (1);
	/* tree is not height-balanced */
	return (0);
}

/**
 * binary_tree_is_avl - function that checks if a
 * binary tree is a valid AVL Tree
 * @tree: Pointer to tree's root
 * Return: 1 if it is balanced; otherwise 0
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	return (is_balanced(tree));
}
