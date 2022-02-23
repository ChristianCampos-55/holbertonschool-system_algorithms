#include "nary_trees.h"

/**
 * nary_tree_insert - inserts a node in a N-ary tree.
 * @parent: a pointer to the parent node.
 * @str: string to be stored in the created node.
 * Return:  pointer to the created node, or NULL
*/
nary_tree_t *nary_tree_insert(nary_tree_t *parent, char const *str)
{
	nary_tree_t *c;

	c = malloc(sizeof(*c));
	if (!c)
		return (NULL);

	c->content = strdup(str);
	c->children = NULL;
	c->nb_children = 0;

	if (parent)
	{
		c->parent = parent;
		++parent->nb_children;
		c->next = parent->children;
		parent->children = c;
	}

	else
		c->next = c->parent = NULL;

	return (c);
}
