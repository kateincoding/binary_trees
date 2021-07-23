#include "binary_trees.h"

/**
 * count_nodes - Counts the number of nodes inside a tree
 * @root: Pointer to tree's root node
 *
 * Return: Number of tree nodes
 */
int count_nodes(binary_tree_t *root)
{
	if (!root)
		return (0);

	return (1 + count_nodes(root->left) + count_nodes(root->right));
}

/**
 * is_max_heap - Checks if a tree is a max heap
 * @root: Pointer to tree's root
 * @index: Index of the node been evaluated
 * @n: number of trees nodes
 *
 * Return: 1 if the tree is a heap, 0 otherwise
 */
int is_max_heap(binary_tree_t *root, int index, int n)
{
	if (!root)
		return (0);

	if (index >= n)
		return (0);
	if (!root->left && !root->right)
		return (1);
	if (root->right && !root->left)
		return (0);
	if ((root->left && root->left->n > root->n) ||
	    (root->right && root->right->n > root->n))
		return (0);

	if (root->left && !root->right)
		return (is_max_heap(root->left, index * 2 + 1, n));

	return (is_max_heap(root->left, index * 2 + 1, n) &&
		is_max_heap(root->right, index * 2 + 2, n));
}

/**
 * binary_tree_is_heap - Checks if a binary tree is a valid Max Heap
 * @tree: Pointer to tree's node
 *
 * Return: 1 if the tree is a max heap, 0 otherwise
 */
int binary_tree_is_heap(const binary_tree_t *tree)
{
	int nodes;
	binary_tree_t *root;

	if (!tree)
		return (0);

	root = (binary_tree_t *)tree;
	nodes = count_nodes(root);
	return (is_max_heap(root, 0, nodes));
}
