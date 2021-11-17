#include "graphs.h"

/**
 * graph_add_v - adds a vertex to an existing graph
 * @graph: pointer to existing graph
 * @str: value for vertex
 * Return: pointer to n vertex or NULL upon failure
 */
vertex_t *graph_add_vertex(graph_t *graph, const char *str)
{
	vertex_t *n, *v;

	if (!graph || !str)
		return (NULL);
	v = graph->vertices;
	while (v)
	{
		if (!strcmp(v->content, str))
			return (NULL);
		if (!v->next)
			break;
		v = v->next;
	}
	n = calloc(1, sizeof(vertex_t));
	if (!n)
		return (NULL);
	n->content = strdup(str);
	if (!n->content)
	{
		free(n);
		return (NULL);
	}
	n->index = graph->nb_vertices++;
	if (v)
		v->next = n;
	else
		graph->vertices = n;
	return (n);
}
