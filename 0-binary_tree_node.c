#include "binary_trees.h"
#include <stdlib.h>

/**
 * binary_tree_node - Function that creates a binary tree node.
 * @parent: Pointer to the parent node.
 * @value: Value for new node.
 *
 * Return: New node, Otherwise - NULL.
 */

binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *new;

	new = malloc(sizeof(binary_tree_t));
	if (new == NULL)
		return (NULL);

	new->n = value;
	new->parent = parent;
	new->left = NULL;
	new->right = NULL;

	return (new);
}
