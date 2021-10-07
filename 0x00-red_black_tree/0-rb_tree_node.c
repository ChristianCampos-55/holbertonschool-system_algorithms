#include "rb_trees.h"
#include <stdlib.h>

/**
 * rb_tree_node - creates a new node on red-black tree
 * @parent: address of parent node
 * @value: value the new node
 * @color: color of new node
 * Return: Pointer to new node or NULL
 */
rb_tree_t *rb_tree_node(rb_tree_t *parent, int value, rb_color_t color)
{
	rb_tree_t *n = NULL;

	n = malloc(sizeof(rb_tree_t));

	if (n == NULL)
		return (NULL);

	n->parent = parent;
	n->n = value;
	n->color = color;
	n->left = NULL;
	n->right = NULL;
	return (n);
}
