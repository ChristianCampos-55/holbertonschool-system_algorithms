#include "nary_trees.h"

/**
* act_trav - function that goes through an N-ary tree, node by node.
* @root: pointer to the root node of the tree to traverse
* @action:  pointer to a function to execute for each node being traversed
* @depth: depth of the node being traversed
* Return: biggest depth of the tree
*/

size_t act_trav(nary_tree_t const *root, void
					  (*action)(nary_tree_t const *node, size_t depth),
					  size_t depth)
{
	nary_tree_t const *node;
	size_t countcula = 0, b;

	if (!root)
		return (0);
	node = root;
	while (node)
	{
		action(node, depth);
		b = act_trav(node->children, action, depth + 1);
		if (countcula < b)
			countcula = b;
		node = node->next;
	}
	return (1 + countcula);
}

/**
* act_trav - function that goes through an N-ary tree, node by node.
* @root: pointer to the root node of the tree to traverse
* @action:  pointer to a function to execute for each node being traversed
* Return: biggest depth of the tree
*/

size_t nary_tree_traverse(nary_tree_t const *root,
						  void (*action)(nary_tree_t const *node, size_t depth))
{
	size_t depth;

	if (!root || !action)
		return (0);
	depth = act_trav(root, action, 0);
	return (depth);
}
