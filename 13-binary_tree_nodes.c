#include <stdlib.h>
#include "binary_trees.h"
/**
 * binary_tree_nodes - function that counts the nodes with at
 *		least 1 child in a binary tree.
 * @tree: pointer to root node of the tree to count the number of nodes.
 *
 * Return: count of parent nodes, 0 otherwise..
 */
size_t binary_tree_nodes(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	if (tree->left || tree->right)
		return (1 + binary_tree_nodes(tree->left) + binary_tree_nodes(tree->right));
	return (binary_tree_nodes(tree->left) + binary_tree_nodes(tree->right));
}
