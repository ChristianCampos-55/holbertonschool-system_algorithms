#include "heap.h"

/**
 * binary_tree_node - creates a binary tree node to insert
 * @parent: pointer to parent node
 * @data: data to add to node
 * Return: pointer to new node or NULL on error
 */

binary_tree_node_t *binary_tree_node(binary_tree_node_t *parent, void *data)
{
	binary_tree_node_t *n;

	n = malloc(sizeof(binary_tree_node_t));

	if (!n)
		return (NULL);

	n->parent = parent;
	n->data = data;
	n->left = NULL;
	n->right = NULL;
	return (n);
}
