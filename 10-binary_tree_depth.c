#include "binary_trees.h"

/**
 * binary_tree_depth - measures the depth of a node in a binary tree.
 *
 * @tree: Pointer to the node to measure depth.
 * Return: If tree is NULL, function must return 0.
 *			Otherwise, return node's depth.
 */

size_t binary_tree_depth(const binary_tree_t *tree)
{
	size_t depth = 0;

	while (tree && tree->parent)
	{
		depth++;
		tree = tree->parent;
	}

	return (depth);
}
