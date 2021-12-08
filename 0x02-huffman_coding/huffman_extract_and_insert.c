#include "huffman.h"

/**
* huffman_extract_and_insert - extracts the two nodes of the priority queue
* and insert a new one
* @priority_queue:  pointer to the priority queue to extract from
* Return: 1, 0 otherwise
*/

int huffman_extract_and_insert(heap_t *priority_queue)
{
	void *point1, *point2;
	symbol_t *s, *symb1, *symb2;
	binary_tree_node_t *n, *node1, *node2;

	point1 = heap_extract(priority_queue);
	point2 = heap_extract(priority_queue);

	if (!point1)
		return (0);
	if (!point2)
		return (0);

	node1 = (binary_tree_node_t *)point1;
	node2 = (binary_tree_node_t *)point2;
	symb1 = (symbol_t *)node1->data;
	symb2 = (symbol_t *)node2->data;

	s = symbol_create(-1, symb1->freq + symb2->freq);

	if (!s)
		return (0);

	n = binary_tree_node(NULL, s);
	if (!n)
		return (0);

	n->left = node1;
	n->right = node2;
	node1->parent = n;
	node2->parent = n;

	if (!heap_insert(priority_queue, n))
		return (0);

	return (1);
}
