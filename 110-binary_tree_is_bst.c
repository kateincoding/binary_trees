#include "binary_trees.h"
/**
 * recursion_bst - check if each node has in the left a less value than himself
 * @root: node to check
 * @min_left: min value to check with the node at the left
 * @max_right: max value to check with the node at the right
 * Return: 1 if is a BST or 0 otherwise
 */
int recursion_bst(const binary_tree_t *root,
	   const binary_tree_t *min_left, const binary_tree_t *max_right)
{
	if (root == NULL)
		return (1);

	if (min_left != NULL && root->n <= min_left->n)
		return (0);

	if (max_right != NULL && root->n >= max_right->n)
		return (0);

	return (recursion_bst(root->left, min_left, root) &&
		recursion_bst(root->right, root, max_right));
}
/**
 * binary_tree_is_bst - checks if a binary tree is a valid Binary Search Tree
 * @tree: a pointer to the root node of the tree to checkgooo
 * Return: 1 if tree is a nid BST, and 0 otherwise
 * If tree is NULL, return 0
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (recursion_bst(tree, NULL, NULL));
}
