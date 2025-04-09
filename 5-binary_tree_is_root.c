#include <stdio.h>
#include <stdlib.h>
#include "binary_trees.h"
/**
 * binary_tree_is_root - checks if a given node is a root.
 * @node: pointer to the node to check.
 *
 * Return: 1 if node is root, 0 otherwise.
 */
int binary_tree_is_root(const binary_tree_t *node)
{
	if (!node)
		return (0);
	else if (!node->parent)
		return (1);
	else
		return (0);
}
