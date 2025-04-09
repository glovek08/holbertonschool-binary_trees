#include "binary_trees.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * binary_tree_insert_right - function that inserts a node as the right-child.
 * @parent: Pointer to the node to insert the right-child.
 * @value: Value to store in the new node.
 * Return: Pointer to new node, Otherwise - NULL.
 */

binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *righty;

	if (parent == NULL)
		return (NULL);

	righty = binary_tree_node(parent, value);
	if (righty == NULL)
		return (NULL);

	if (parent->right != NULL)
	{
		righty->right = parent->right;
		parent->right->parent = righty;
	}
	parent->right = righty;

	return (righty);
}
