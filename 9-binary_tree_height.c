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
size_t binary_tree_height(const binary_tree_t *tree)
{
    size_t left_height = 0;
    size_t right_height = 0;

    if (!tree)
	    return(0);

    left_height =  binary_tree_height(tree->left);
    right_height = binary_tree_height(tree->right);

    return (1 + (left_height > right_height ? left_height : right_height));
}
