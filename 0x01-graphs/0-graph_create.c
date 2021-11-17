#include "graphs.h"

/**
 * graph_create - A function that allocates memory to store a g structure
 * Return:  A pointer or NULL upon failure
 */
graph_t *graph_create(void)
{
	graph_t *g;

	g = malloc(sizeof(graph_t));

	if (g == NULL)
		return (NULL);
	g->nb_vertices = 0;
	g->vertices = NULL;
	return (g);
}
