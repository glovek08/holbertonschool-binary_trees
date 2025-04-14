#include "binary_trees.h"
#include "9-binary_tree_height.c"
#include <stdlib.h>
/**
 * binary_tree_balance - measures the balance factor of a binary tree
 * @tree: pointer to the root node of the tree to measure the balance factor.
 *
 * Return: balance factor of @tree, 0 otherwise.
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	int left_height = binary_tree_height(tree->left);
	int right_height = binary_tree_height(tree->right);

	if (!tree)
		return (0);
	return (left_height - right_height);

}
