#include "huffman.h"

/**
* huffman_priority_queue - creates a priority queue for the Huffman algorithm
* @data: array of characters
* @freq:  array containing the associated frequenciesv
* @size: size of the data
* Return: prioritized array
*/

heap_t *huffman_priority_queue(char *data, size_t *freq, size_t size)
{
	size_t a;
	heap_t *h;
	symbol_t *s;
	binary_tree_node_t *n;

	h = heap_create(freq_cmp);
	for (a = 0; a < size; a++)
	{
		s = symbol_create(data[a], freq[a]);
		n = binary_tree_node(NULL, s);
		n = heap_insert(h, n);
	}
	return (h);
}

/**
* freq_cmp - compare stored data
* @data1: pointer 1
* @data2: pointer 2
* Return: difference between both sets of data
*/

int freq_cmp(void *data1, void *data2)
{
	binary_tree_node_t *node1, *node2;
	symbol_t *symbol1, *symbol2;

	node1 = (binary_tree_node_t *)data1;
	node2 = (binary_tree_node_t *)data2;
	symbol1 = (symbol_t *)node1->data;
	symbol2 = (symbol_t *)node2->data;
	return (symbol1->freq - symbol2->freq);
}
