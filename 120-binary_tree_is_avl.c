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

int is_balanced(const binary_tree_t *root)
{
	int lh;/* for height of left subtree */
	int rh;/* for height of right subtree */
 
	/* If tree is empty then return true */
	if (root == NULL)
		return (1);
 
	/* Get the height of left and right sub trees */
	lh = binary_tree_height_auxx(root->left);
	rh = binary_tree_height_auxx(root->right);
 
	if (abs(lh - rh) <= 1 && is_balanced(root->left) && is_balanced(root->right))
		return (1);
	/* If we reach here then tree is not height-balanced */
	return (0);
}

int binary_tree_is_avl(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	return (is_balanced(tree));
}
