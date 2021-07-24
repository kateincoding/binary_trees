#include "binary_trees.h"

/**
 * remove_child - Removes a node from a tree
 * @parent: Pointer to child's parent
 * @child: Pointer to node to be removed from the tree
 * @val: Pointer to node used to replace child
 *
 * Return: Pointer to new root, or NULL if root remains the same
 */
bst_t *remove_child(bst_t *parent, bst_t *child, bst_t *val)
{
	if (val)
		val->parent = parent;

	if (parent && parent->left == child)
		parent->left = val;
	else if (parent && parent->right == child)
		parent->right = val;

	free(child);

	if (!parent)
		return (val);

	return (NULL);
}

/**
 * remove_node - Removes a node from the tree
 * @root: Pointer to tree's root
 * @node: Pointer to node to be removed
 *
 * Return: Pointer to tree's root node
 */
bst_t *remove_node(bst_t *root, bst_t *node)
{
	bst_t *parent, *ch_left, *ch_right, *curr, *new_root = NULL;

	if (!node)
		return (NULL);

	parent = node->parent;
	ch_left = node->left;
	ch_right = node->right;

	if (!ch_left && !ch_right)
		new_root = remove_child(parent, node, NULL);
	else if (!ch_right)
		new_root = remove_child(parent, node, ch_left);
	else
	{
		curr = ch_right;
		while (curr->left)
			curr = curr->left;

		node->n = curr->n;
		new_root = remove_child(curr->parent, curr, curr->right);
	}

	if (new_root)
		return (new_root);

	if (!parent && !ch_left && !ch_right)
		return (NULL);

	return (root);
}

/**
 * bst_remove - Removes a node from the tree
 * @root: Pointer to tree's node
 * @value: Value to search
 *
 * Return: Pointer to tree's root
 */
bst_t *bst_remove(bst_t *root, int value)
{
	bst_t *curr = root;

	if (!root)
		return (NULL);

	while (curr)
	{
		if (value == curr->n)
			return (remove_node(root, curr));

		if (value < curr->n)
			curr = curr->left;
		else
			curr = curr->right;
	}

	return (root);
}
