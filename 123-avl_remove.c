#include "binary_trees.h"

/**
 * set_parent_child - Sets a parent value to a child
 * @parent: Pointer to parent node
 * @node: Pointer to a node to compare
 * @val: Value to be setted
 */
void set_parent_child(avl_t *parent, avl_t *node, avl_t *val)
{
	if (parent && parent->left == node)
		parent->left = val;
	else if (parent && parent->right == node)
		parent->right = val;
}


/**
 * balance_avl_tree - Balances a tree
 * @node: Pointer to tress node
 *
 * Return: Pointer to root after rotation
*/
avl_t *balance_avl_tree(avl_t *node)
{
	int bf, bleft, bright; /* balance factor */
	avl_t *new_root = NULL;

	if (!node || (!node->left && !node->right))
		return (NULL);

	bf = binary_tree_balance(node);
	bleft = binary_tree_balance(node->left);
	bright = binary_tree_balance(node->right);

	if (bf > 1 && bright >= -1 && bright <= 1)
		new_root = binary_tree_rotate_right(node);
	else if (bf < -1 && bleft >= -1 && bleft <= 1)
		new_root = binary_tree_rotate_left(node);
	else if (bf > 1 && bleft < -1)
	{
		binary_tree_rotate_left(node->left);
		new_root = binary_tree_rotate_right(node);
	}
	else if (bf < -1 && bright > 1)
	{
		binary_tree_rotate_right(node->right);
		new_root = binary_tree_rotate_left(node);
	}

	if (new_root && new_root->parent == NULL)
		return (new_root);

	return (node);
}


/**
 * remove_node - Removes a node from an AVL tree
 * @root: Pointer to root node
 * @node: Pointer to tree's node
 *
 * Return: Pointer to the root
 */
avl_t *remove_node(avl_t *root, avl_t *node)
{
	avl_t *curr = NULL, *parent = NULL, *new_root = NULL;

	if (!root || !node)
		return (NULL);
	parent = node->parent;
	if (!node->left && !node->right)
	{
		set_parent_child(parent, node, NULL);
		free(node);
		if (!parent)
			return (NULL);
	}
	else if (!node->right)
	{
		curr = node->left;
		curr->parent = parent;
		set_parent_child(parent, node, curr);
		free(node);
		if (!parent)
			return (curr);
	}
	else
	{
		curr = node->right;
		while (curr->left)
			curr = curr->left;
		node->n = curr->n;
		set_parent_child(curr->parent, curr, NULL);
		parent = curr->parent;
		free(curr);
	}
	binary_tree_print(root);
	while (parent)
	{
		new_root = balance_avl_tree(parent);
		parent = parent->parent;
	}
	if (new_root && !new_root->parent)
		return (new_root);
	return (root);
}

/**
 * avl_remove - Removes node from an AVL tree
 * @root: Pointer to root node
 * @value: Value of the node to be removed
 *
 * Return: Pointer to the newly created node
 */
avl_t *avl_remove(avl_t *root, int value)
{
	avl_t *curr;

	if (!root)
		return (NULL);

	curr = root;
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
