#include <stdlib.h>
#include "binary_trees.h"

/**
 * enqueue_child - helper function to enqueue a child node
 * @queue: queue array to store nodes
 * @rear: pointer to the rear index of queue
 * @node: node to enqueue
 * @queue_size: maximum size of queue
 * @next_nodes: pointer to counter for next level nodes
 *
 * Return: 1 on success, 0 on queue overflow
 */
int enqueue_child(const binary_tree_t **queue, size_t *rear,
		const binary_tree_t *node, size_t queue_size, size_t *next_nodes)
{
	if (*rear >= queue_size)
		return (0);
	queue[(*rear)++] = node;
	(*next_nodes)++;
	return (1);
}

/**
 * binary_tree_height - measures the height of a binary tree.
 * @tree: pointer to the root node of the b-tree.
 *
 * Return: height of @tree, 0 if @tree is 'NULL'.
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t height = 0, current_nodes = 0, next_nodes = 0;
	const binary_tree_t **queue, *current;
	size_t front = 0, rear = 0, queue_size = 1000;

	if (!tree)
		return (0);
	queue = malloc(queue_size * sizeof(binary_tree_t *));
	if (!queue)
		return (0);
	queue[rear++] = tree;
	current_nodes = 1;
	while (current_nodes > 0)
	{
		height++;
		next_nodes = 0;
		while (current_nodes > 0)
		{
			current = queue[front++];
			current_nodes--;
			if (current->left && !enqueue_child(queue, &rear, current->left,
						queue_size, &next_nodes))
			{
				free(queue);
				return (0);
			}
			if (current->right && !enqueue_child(queue, &rear, current->right,
						queue_size, &next_nodes))
			{
				free(queue);
				return (0);
			}
		}
		current_nodes = next_nodes;
	}
	free(queue);
	return (height - 1);
}
