#include "binary_trees.h"

/**
 * recursion_sorted_array - Recursion fx that creates a
 * binary tree from a sorted array
 * @array: Pointer to the first element of the array to be converted
 * @first_idx: first index of the array or sub array
 * @last_idx: last index of the array or sub array
 * Return: root of the binary tree
 */
avl_t *recursion_sorted_array(int *array, int first_idx, int last_idx)
{
	avl_t *root;
	int middle;

	if (last_idx < first_idx)
		return (NULL);

	middle = (last_idx + first_idx) / 2;
	/* creation of binary tree with root = middle */
	root = binary_tree_node(NULL, array[middle]);
	if (!root)
		return (NULL);
	/* sort each branch */
	root->left = recursion_sorted_array(array, first_idx, middle - 1);
	root->right = recursion_sorted_array(array, middle + 1, last_idx);
	if (root->left)
		root->left->parent = root;
	if (root->right)
		root->right->parent = root;
	return (root);
}

/**
 * sorted_array_to_avl - Sets a parent value to a child
 * @array: Pointer to the first element of the array to be converted
 * @size: Number of element in the array
 * Return: redirection to fx that return root of the binary tree
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	if (!array || size < 1)
		return (NULL);
	return (recursion_sorted_array(array, 0, size - 1));
}
