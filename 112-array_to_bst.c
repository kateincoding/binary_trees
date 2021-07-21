#include "binary_trees.h"

/**
 * array_to_bst - Build a BST from an array
 * @array: Pointer to an array of integers
 * @size: Array's size
 *
 * Return: Pointer to the node with the searched value
 */
bst_t *array_to_bst(int *array, size_t size)
{
	size_t i;
	bst_t *bst = NULL;

	if (!array || size == 0)
		return (NULL);

	bst = bst_insert(&bst, array[0]);
	for (i = 1; i < size; i++)
		bst_insert(&bst, array[i]);

	return (bst);
}
