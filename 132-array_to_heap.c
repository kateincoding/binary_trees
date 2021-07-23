#include "binary_trees.h"

/**
 * array_to_heap - Builds a MAx Heap from an array
 * @array: Array of integers
 * @size: Array's size
 *
 * Return: Pointer to the heap's root node
 */
heap_t *array_to_heap(int *array, size_t size)
{
	size_t i;
	heap_t *root = NULL;

	if (!array)
		return (NULL);

	root = heap_insert(&root, array[0]);
	for (i = 1; i < size; i++)
		heap_insert(&root, array[i]);

	return (root);
}
