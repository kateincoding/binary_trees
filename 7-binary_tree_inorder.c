#include "binary_trees.h"

/**
 * binary_tree_inorder - Prints a tree using inorder traversal
 * @tree: Pointer to tree's root
 * @func: Pointer to function to apply to each node's value
 */
void binary_tree_inorder(const binary_tree_t *tree, void (*func)(int))
{
	if (!tree || !func)
		return;

	binary_tree_inorder(tree->left, func);
	func(tree->n);
	binary_tree_inorder(tree->right, func);
}
