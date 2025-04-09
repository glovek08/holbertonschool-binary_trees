#include <stdlib.h>
#include "binary_trees.h"
/**
 * binary_tree_height - measures the height of a given b-tree.
 * @tree: pointer to the root node of the tree.
 *
 * Return: The height of @tree, 0 if @tree is NULL.
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t height = 0;
	const binary_tree_t **queue;
	const binary_tree_t *current;
	int front = 0, rear = 0, level_size;
	int max_queue_size = 1000;

	if (!tree)
		return (0);
	queue = malloc(sizeof(binary_tree_t) * max_queue_size);
	if (!queue)
		return (0);
	queue[rear++] = tree;
	while (front <= rear)
	{
		level_size = rear - front;
		if (level_size > 0)
			height++;
		while (level_size > 0)
		{
			current = queue[front++];
			if (current->left)
			{
				if ((max_queue_size - 1) <= rear)
				{
					free(queue);
					return (height);
				}
				queue[rear++] = current->left;
			}
			if (current->right)
			{
				if (rear >= max_queue_size - 1)
				{
					free(queue);
					return (height);
				}
				queue[rear++] = current->right;
			}

			level_size--;
		}
	}
	free(queue);
	return (height > 0 ? height - 1 : 0);
}
