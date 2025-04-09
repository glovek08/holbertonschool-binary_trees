#include <stdlib.h>
#include "binary_trees.h"

size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t height = 0;
	size_t current_level_nodes = 0;
	size_t next_level_nodes = 0;
	const binary_tree_t **queue;
	const binary_tree_t *current;
	size_t front = 0, rear = 0;
	size_t queue_size = 10000;

	if (!tree)
		return (0);
	queue = malloc(queue_size * sizeof(binary_tree_t *));
	if (!queue)
		return (0);
	queue[rear++] = tree;
	current_level_nodes = 1;
	while (current_level_nodes > 0)
	{
		height++;
		next_level_nodes = 0;
		while (current_level_nodes > 0)
		{
			current = queue[front++];
			current_level_nodes--;
			if (current->left)
			{
				if (rear >= queue_size)
				{
					free(queue);
					return (0);
				}
				queue[rear++] = current->left;
				next_level_nodes++;
			}
			if (current->right)
			{
				if (rear >= queue_size)
				{
					free(queue);
					return (0);
				}
				queue[rear++] = current->right;
				next_level_nodes++;
			}
		}
		current_level_nodes = next_level_nodes;
	}
	free(queue);
	return (height - 1);
}
