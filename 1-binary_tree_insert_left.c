#include "binary_trees.h"

/**
 * binary_tree_insert_left - Inserts a node on the parent's left side
 * @parent: Pointer to parent node
 * @value: New node's data
 *
 * Return: Pointer to the newly created node
 */
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *pleft, *new_node = NULL;

	if (!parent)
		return (NULL);

	new_node = malloc(sizeof(*new_node));
	if (!new_node)
		return (NULL);

	new_node->parent = parent;
	new_node->left = NULL;
	new_node->right = NULL;
	new_node->n = value;

	pleft = parent->left;
	parent->left = new_node;

	if (pleft)
	{
		pleft->parent = new_node;
		new_node->left = pleft;
	}

	return (new_node);
}
