#include "heap.h"

/**
 * heap_delete - deallocates a heap
 * @heap: heap to deallocate
 * @free_data: pointer to function that will be used to free content of node
 */

void heap_delete(heap_t *heap, void (*free_data)(void *))
{
	if (heap->root)
		rec_free(heap->root, free_data);
	free(heap);
}

/**
 * rec_free - deletes a binary tree
 * @node: node to delete
 * @free_data: pointer to function that will be used to free content of node
 */

void rec_free(binary_tree_node_t *node, void (*free_data)(void *))
{
	if (node->right)
		rec_free(node->right, free_data);
	if (node->left)
		rec_free(node->left, free_data);
	if (free_data)
		free_data(node->data);
	free(node);
}
