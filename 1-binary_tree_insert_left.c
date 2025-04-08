#include "binary_trees.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * binary_tree_insert_left - Function that inserts a node as the left child.
 * @parent: Pointer to the node to insert the left child.
 * @value: Value to store in the new node.
 *
 * Return: Pointer to new node, otherwise - NULL
 */

binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *lefty;

	if (parent == NULL)
		return (NULL);

	lefty = binary_tree_node(parent, value);
	if (lefty == NULL)
		return (NULL);

	if (parent->left != NULL)
	{
		lefty->left = parent->left;
		parent->left->parent = lefty;
	}
	parent->left = lefty;

	return (lefty);
}
