#include "heap.h"

/**
 * heap_extract - extracts the root value of a Min Binary Heap
 * @heap: heap
 * Return: extracted info
 */
void *heap_extract(heap_t *heap)
{
	binary_tree_node_t *node;
	void *inf;
	size_t b;


	if (!heap)
		return (NULL);

	if (!heap->root)
		return (NULL);

	inf = heap->root->inf;

	if (heap->size == 1)
	{
		free(heap->root);
		heap->root = NULL;
		heap->size--;
		return (inf);
	}

	for (b = 1; b <= heap->size; b <<= 1)
		;
	b >>= 2;

	for (node = heap->root; b > 0; b >>= 1)
		node = heap->size & b ? node->right : node->left;

	heap->root->inf = node->inf;

	if (node->parent->left == node)
		node->parent->left = NULL;
	else
		node->parent->right = NULL;
	heap->size--;

	free(node);
	restore_heap(heap);
	return (inf);
}

/**
 * restore_heap - restores heap
 * @h: pointer to heap
 */

void restore_heap(heap_t *h)
{
	void *cont;
	binary_tree_node_t *node = h->root, *c;

	while (1)
	{
		if (!node->left)
			break;
		if (!node->right)
			c = node->left;
		else
			c = h->data_cmp(node->left->data, node->right->data) <= 0 ?
				node->left : node->right;

		if (h->data_cmp(node->data, c->data) < 0)
			break;

		cont = node->data;
		node->data = c->data;
		c->data = cont;
		node = c;

	}
}
