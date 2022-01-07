#include "pfinding.h"

static int *ider;
static vertex_t **antipode;
static vertex_t **apex;
#define STRDUP(x) ((str = strdup(x)) ? str : (exit(1), NULL))

/**
 * dijkstra_graph - searches for the shortest path from a starting
 * point to a target point in a graph
 * @graph: pointer to the graph to go through
 * @start: pointer to the starting vertex
 * @target: pointer to the target vertex
 * Return: queue
 */

queue_t *dijkstra_graph(graph_t *graph, vertex_t const *start,
	vertex_t const *target)
{
	queue_t *p = queue_create();
	ssize_t i, j = -1;
	ssize_t d = -1;
	vertex_t *ap;
	edge_t *ed;
    char *str;

	if (!graph || !start || !target || !p)
		return (NULL);
	ider = calloc(graph->nb_vertices, sizeof(*ider));
	antipode = calloc(graph->nb_vertices, sizeof(*antipode));
	apex = calloc(graph->nb_vertices, sizeof(*apex));
	if (!ider || !antipode || !apex || !p)
		return (NULL);
	for (ap = graph->vertices; ap; ap = ap->next)
		apex[ap->index] = ap, ider[ap->index] = INT_MAX;
	ider[start->index] = 0, antipode[start->index] = NULL;
	while (j != (ssize_t)target->index)
	{
		for (d = INT_MAX, j = -1, i = 0; i < (ssize_t)graph->nb_vertices; i++)
			if (ider[i] >= 0 && ider[i] < d)
				d = ider[i], j = i;
		if (j == -1)
			break;
		printf("Checking %s, distance from %s is %d\n",
			apex[j]->content, start->content, ider[j]);
		for (ed = apex[j]->edges; ed; ed = ed->next)
			if (ider[ed->dest->index] >= 0 &&
				ider[j] + ed->weight < ider[ed->dest->index])
				ider[ed->dest->index] = ider[j] + ed->weight,
					antipode[ed->dest->index] = apex[j];
		ider[j] = -1;
	}
	if (j != -1)
		for (queue_push_front(p, STRDUP(apex[j]->content));
			j != (ssize_t)start->index; j = antipode[j]->index)
			queue_push_front(p, STRDUP(antipode[j]->content));
	else
		p = (free(p), NULL);
	free(ider), free(antipode), free(apex);
	return (p);
}
