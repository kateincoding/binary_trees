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
 * aux_recursion_bst - check if each node has in the
 * left a less value than himself
 * @root: node to check
 * @min_left: min value to check with the node at the left
 * @max_right: max value to check with the node at the right
 * Return: 1 if is a BST or 0 otherwise
 */
int aux_recursion_bst(const binary_tree_t *root,
	   const binary_tree_t *min_left, const binary_tree_t *max_right)
{
	if (root == NULL)
		return (1);

	if (min_left != NULL && root->n <= min_left->n)
		return (0);

	if (max_right != NULL && root->n >= max_right->n)
		return (0);

	return (aux_recursion_bst(root->left, min_left, root) &&
		aux_recursion_bst(root->right, root, max_right));
}

/**
 * aux_is_bst - checks if a binary tree is a valid Binary Search Tree
 * @tree: a pointer to the root node of the tree to checkgooo
 * Return: 1 if tree is a nid BST, and 0 otherwise
 * If tree is NULL, return 0
 */
int aux_is_bst(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (aux_recursion_bst(tree, NULL, NULL));
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

	if (!aux_is_bst(root))
		return (0);

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
