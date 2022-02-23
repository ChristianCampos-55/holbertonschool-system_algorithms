#include "nary_trees.h"

/**
* path_exists - checks if a path exists in an N-ary tree
* @root: pointer to the root n of the tree
* @path: NULL terminated array of strings
* Return: 1 if all the elements of path are present in the tree
*/
int path_exists(nary_tree_t const *root, char const * const *path)
{
	int port = 0;
	nary_tree_t const *n;

	if (!root || !path || !path[port])
		return (0);

	n = root;
	while (n)
	{
		while (n && strcmp(path[port], n->content))
			n = n->next;

		if (!n)
			return (0);
		n = n->children;
		++port;

		if (!path[port])
			break;
	}

	return (!path[port]);
}
