#include "binary_trees.h"
#include "9-binary_tree_height.c"
#include <stdlib.h>
/**
 * binary_tree_is_perfect - checks whether or not a given tree is perfect.
 * @tree: pointer to the root node of the tree to check.
 *
 * Return: 1 if binary tree is perfect, 0 otherwise.
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	size_t left_height, right_height;

	if (!tree)
		return (0);
	left_height = binary_tree_height(tree->left);
	right_height = binary_tree_height(tree->right);
	if (left_height != right_height)
		return (0);
	if (!tree->left && !tree->right)
		return (1);
	if (!tree->left || !tree->right)
		return (0);
	return (binary_tree_is_perfect(tree->left) &&
			binary_tree_is_perfect(tree->right));
}
