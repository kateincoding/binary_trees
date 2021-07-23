#include "binary_trees.h"

/**
 * array_to_avl - Build an AVL tree from an array
 * @array: Pointer to an array of integers
 * @size: Array's size
 *
 * Return: Pointer to root
 */
avl_t *array_to_avl(int *array, size_t size)
{
	size_t i;
	avl_t *root = NULL;

	if (!array || size == 0)
		return (NULL);

	root = avl_insert(&root, array[0]);
	for (i = 1; i < size; i++)
		avl_insert(&root, array[i]);

	return (root);
}
