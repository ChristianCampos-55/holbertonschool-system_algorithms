#include "nary_trees.h"

/**
 * nary_tree_delete - deletes a tree
 * @tree: tree to delete
*/

void nary_tree_delete(nary_tree_t *tree)
{
	nary_tree_t *holder;

	while (tree)
	{
		holder = tree;
		tree = tree->next;
		free(holder->content);
		nary_tree_delete(holder->children);
		free(holder);
	}
}
