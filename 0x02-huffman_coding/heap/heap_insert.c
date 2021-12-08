#include "heap.h"

#define STRINGCONS(x) ((x) >= 0 ? (x) : (-x))

/**
 * heap_insert - inserts a value in a Min Binary Heap
 * @heap: heap structure
 * @data: data
 * Return: pointer to new node or NULL
 */

binary_tree_node_t *heap_insert(heap_t *heap, void *data)
{
	binary_tree_node_t *n;
	binary_tree_node_t *node;
	size_t a;
	char *str;
	void *holder;

	if (!heap)
		return (NULL);

	n = binary_tree_node(NULL, data);
	if (!n)
		return (NULL);

	heap->size++;
	if (!heap->root)
		return (heap->root = n);

	str = swap(heap->size, 2);
	for (node = heap->root, a = 1; a < strlen(str) - 1; a++)
		node = str[a] == '1' ? node->right : node->left;

	if (str[a] == '1')
		node->right = n;
	else
		node->left = n;

	n->parent = node;
	node = n;
	while (node->parent && heap->data_cmp(node->parent->data, node->data) > 0)
	{
		holder = node->data;
		node->data = node->parent->data;
		node->parent->data = holder;
		node = node->parent;
	}
	return (n);
}

/**
 * swap - swaps a number to a chosen base
 * @num: number to swap
 * @base: base to swap to
 * Return: swapped number
 */

char *swap(long n, long base)
{
	static char buf[66];
	short min = n < 0 ? 1 : 0;
	char *loc = "0123456789ABCDEFG";
	char *root;

	root = &buf[sizeof(buf)];
	*--root = 0;

	do {
		*--root = loc[STRINGCONS(n % base)];
		n /= base;
	} while (n);

	if (min)
		*--root = '-';
	return (root);
}
