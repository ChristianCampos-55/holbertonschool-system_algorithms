#include "huffman.h"

/**
 * huffman_tree - builds the Huffman tree
 * @data:  array of characters of size
 * @freq: contains the associated frequencies
 * @size: size of set of args
 * Return: genesis of huffman tree or NULL
 */

binary_tree_node_t *huffman_tree(char *data, size_t *freq, size_t size)
{
	heap_t *h = huffman_priority_queue(data, freq, size);
	binary_tree_node_t *root;

	setbuf(stdout, NULL);
	if (h == NULL)
		return (NULL);

	while (h->size > 1)
	{
		if (!huffman_extract_and_insert(h))
			return (NULL);
	}
	root = h->root->data;
	free(h->root);
	free(h);
	return (root);
}
