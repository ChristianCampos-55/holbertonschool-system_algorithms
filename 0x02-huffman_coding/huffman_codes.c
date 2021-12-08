#include "huffman.h"

/**
 * huffman_codes -  build the Huffman tree and print the
 * resulting Huffman codes for each symbol
 * @data: array of characters
 * @freq: contains the associated frequencies
 * @size: size of arrays
 * Return: 1, or 0 upon failure
 */

int huffman_codes(char *data, size_t *freq, size_t size)
{
	binary_tree_node_t *h_tree = huffman_tree(data, freq, size);

	if (h_tree == NULL)
		return (0);

	print_h_c(h_tree, 1);
	return (1);
}

/**
 * print_h_c - prints the huffman codes recursively
 * @h_tree: pointer to current tree node
 * @coord: long int holding binary representation of coord
 */

void print_h_c(binary_tree_node_t *h_tree, unsigned long coord)
{
	symbol_t *s;

	if (!h_tree)
		return;
	s = h_tree->data;
	if (s->data != -1)
	{
		printf("%c: %s\n", s->data, swap(coord, 2) + 1);
	}
	else
	{
		print_h_c(h_tree->left, coord << 1);
		print_h_c(h_tree->right, (coord << 1) + 1);
	}
	free(s);
	free(h_tree);
}
