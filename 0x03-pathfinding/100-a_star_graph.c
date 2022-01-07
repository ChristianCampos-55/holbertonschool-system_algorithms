#include "pathfinding.h"

static int *l;
static int *checker;
static vertex_t **antipode;
static vertex_t **apex;

/**
 * a_star_graph - searches for the shortest and fastest path from a
 * starting point to a target point in a graph
 * @graph: pointer to the graph to go through
 * @start: pointer to the starting vertex
 * @target: pointer to the target vertex
 * Return: queue
 */

queue_t *a_star_graph(graph_t *graph, vertex_t const *start,
	vertex_t const *target)
{
	queue_t *path = queue_create();
	ssize_t i, d, j = -1;
	vertex_t *v;
	edge_t *e;
	char *str;

	if (!graph || !start || !target || !path)
		return (NULL);
	ALLOCATE_ALL;
	if (!l || !checker || !antipode || !apex || !path)
		return (NULL);
	for (v = graph->vertices; v; v = v->next)
		apex[v->index] = v, l[v->index] = checker[v->index] = INT_MAX;
	l[start->index] = 0, antipode[start->index] = NULL;
	checker[start->index] = H(start);
	while (j != (ssize_t)target->index)
	{
		for (d = INT_MAX, j = -1, i = 0; i < (ssize_t)graph->nb_vertices; i++)
			if (checker[i] >= 0 && checker[i] < d)
				d = checker[i], j = i;
		if (j == -1)
			break;
		printf("Checking %s, distance to %s is %d\n",
			apex[j]->content, target->content, H(apex[j]));
		for (e = apex[j]->edges; e; e = e->next)
			if (l[e->dest->index] >= 0 &&
				l[j] + e->weight < l[e->dest->index])
				l[e->dest->index] = l[j] + e->weight,
				antipode[e->dest->index] = apex[j],
				checker[e->dest->index] = l[e->dest->index] + H(e->dest);
		checker[j] = -1;
	}
	if (j != -1)
		for (queue_push_front(path, STRDUP(apex[j]->content));
			j != (ssize_t)start->index; j = antipode[j]->index)
			queue_push_front(path, STRDUP(antipode[j]->content));
	else
		path = (free(path), NULL);
	free(l), free(checker), free(antipode), free(apex);
	return (path);
}
