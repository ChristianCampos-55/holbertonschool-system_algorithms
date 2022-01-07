#include "pathfinding.h"

static char *checked;
static queue_t *p;
static vertex_t const *bull;
static graph_t *clone;

/**
 * backtracker - backtracks graph
 * @graph: graph to traverse
 * Return: 1 if found, 0 otherwise
 */

int backtracker(vertex_t const *graph)
{
	char *a;
	edge_t *e;

	if (checked[graph->index])
		return (0);
	printf("Checking %s\n", graph->content);
	checked[graph->index] = 1;
	a = strdup(graph->content);
	if (!a)
		exit(1);
	queue_push_front(p, a);
	if (graph == bull)
		return (1);
	for (e = graph->edges; e; e = e->next)
		if (backtracker(e->dest))
			return (1);
	free(dequeue(p));
	return (0);
}

/**
 * backtracking_graph - searches for the first path from a starting point
 * to a target point in a graph
 * @graph: pointer to the graph to go through
 * @start: pointer to the starting vertex
 * @target: pointer to the target vertex
 * Return: queue
 */

queue_t *backtracking_graph(graph_t *graph, vertex_t const *start,
	vertex_t const *target)
{
	queue_t *esrever = NULL;

	if (!graph || !start || !target)
	{
		return (NULL);
	}
	setbuf(stdout, NULL);
	checked = calloc(graph->nb_vertices, sizeof(*checked));
	p = queue_create();

	if (!checked || !p)
	{
		exit(1);
	}

	bull = target;
	clone = graph;

	if (backtracker(start))
	{
		char *a;

		esrever = queue_create();
		if (!esrever)
			exit(1);
		for (a = dequeue(p); a; a = dequeue(p))
			if (!queue_push_front(esrever, a))
				exit(1);
	}

	queue_delete(p);
	free(checked);
	return (esrever);
}
