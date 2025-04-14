#include <stdlib.h>
#include "binary_trees.h"
/**
 * binary_tree_leaves - counts the leaf nodes in a binary tree.
 * @tree: pointer to the root node of the tree to count the number of leaves.
 *
 * Return: the number of leaf nodes in @tree, 0 otherwise.
 */
size_t binary_tree_leaves(const binary_tree_t *tree)
{
	size_t leaf_node_count = 0, front = 0, rear = 0;

	binary_tree_t **stack = malloc(sizeof(binary_tree_t *) * 1024);

	if (!tree || !stack)
		return (0);

	stack[rear++] = (binary_tree_t *)tree;
	while (front < rear)
	{
		binary_tree_t *current = stack[front++];

		if (!current->left && !current->right)
			leaf_node_count++;
		if (current->left)
			stack[rear++] = current->left;
		if (current->right)
			stack[rear++] = current->right;
	}
	free(stack);
	return (leaf_node_count);
}
