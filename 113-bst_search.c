#include "binary_trees.h"

/**
 * bst_search - Search an element in a binary tree
 * @tree: Pointer to trees' root
 * @value: Value to search
 *
 * Return: Pointer to the node with the searched value
 */
bst_t *bst_search(const bst_t *tree, int value)
{

	if (!tree)
		return (NULL);

	while (tree)
	{
		if (value == tree->n)
			return ((bst_t *)tree);

		if (value < tree->n)
			tree = tree->left;
		else
			tree = tree->right;
	}

	return (NULL);
}
