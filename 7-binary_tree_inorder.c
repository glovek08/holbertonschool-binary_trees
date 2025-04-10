#include <stdlib.h>
#include "binary_trees.h"
/**
 * binary_tree_inorder - goes through a binary tree using in-order traversal.
 * @tree: pointer to the root node of the tree to traverse.
 * @func: function pointer to call for each node.
 *
 * Return: void.
 */
void binary_tree_inorder(const binary_tree_t *tree, void(*func)(int))
{
	const binary_tree_t **stack;
	const binary_tree_t *current;
	int top = -1;
	int max_size = 1000;

	if (!tree || !func)
		return;

	stack = malloc(sizeof(binary_tree_t *) * max_size); /* *stack = malloc(sizeof(binary_tree_t *)); stack++;*/
	if (!stack)
		return;
	current = tree; /*Podes usar el mismo puntero tree*/
	for (;;) /*Este bucle lo podes setear con el max_size y evitas el if, el return va afuera*/
	{
		while (current)
		{
			if (top > max_size - 1)
			{
				free(stack); /* STACK OVERFLOW!!!! :P */
				return;
			}
			stack[++top] = current;
			current = current->left;
		}
		if (top == -1)
		{
			free(stack);
			return;
		}
		current = stack[top--];
		func(current->n);
		current = current->right;
	}
}
