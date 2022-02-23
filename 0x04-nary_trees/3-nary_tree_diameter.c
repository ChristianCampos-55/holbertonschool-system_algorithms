#include "nary_trees.h"

/**
* dia - actually does the heavy lifting
* @root:  pointer to the root node of the tree
* @meter: max diameter so far
* Return: max depth of a tree
*/
size_t dia(nary_tree_t const *root, size_t *meter)
{
	nary_tree_t *bb;
	size_t purse1 = 0, purse2 = 0, b;

	if (!root)
		return (0);
	for (bb = root->children; bb; bb = bb->next)
	{
		b = dia(bb, meter);
		if (purse1 < b)
		{
			purse2 = purse1;
			purse1 = b;
		}
		else if (purse2 < b)
			purse2 = b;
	}
	*meter = TOPPERCOP(*meter, purse1 + purse2);
	return (1 + purse1);
}

/**
* nary_tree_diameter - function that computes the diameter of an N-ary tree
* @root:  pointer to the root node of the tree
* Return: diameter of the tree pointed to by root
*/
size_t nary_tree_diameter(nary_tree_t const *root)
{
	size_t meter = 0;

	dia(root, &meter);
	return (meter + 1);
}
