#include "graphs.h"

#define  SUCC 1
#define  FAIL 0

/**
 * get_vertices - A function that looks for a vertex in a graph
 * @graph: Pointer to graph
 * @str: Vertex string
 * Return: Node of vertex or NULL upon FAIL
 */

vertex_t *get_vertices(graph_t *graph, const char *str)
{
	vertex_t *nd;

	if (str == NULL)
		return (FAIL);

	nd = graph->vertices;
	if (nd == NULL)
		return (NULL);

	while (nd != NULL)
	{
		if (strcmp(nd->content, str) == 0)
		{
			return (nd);
		}
		nd = nd->next;
	}
	return (NULL);
}

/**
 * edge_creator - Creates an edge between two vertices
 * @src: Vertex to connect from
 * @dest: Vertex to connect to
 * Return: 1 or 0 upon FAIL
 */

int edge_creator(vertex_t *src, vertex_t *dest)
{
	edge_t *ed, *nd = NULL;

	ed = src->edges;
	while (ed && ed->next != NULL)
	{
		ed = ed->next;
	}

	nd = malloc(sizeof(edge_t));
	if (nd != NULL)
	{
		nd->dest = dest;
		nd->next = NULL;

		if (src->nb_edges == 0)
			src->edges = nd;
		else
			ed->next = nd;
		return (SUCC);
	}
	return (FAIL);
}

/**
 * edge_checker -  A function that checks if edge exists
 * @src: Vertex to connect from
 * @dest: Vertex to connect to
 * Return: 1 or 0 if it doesn't exists
 */

int edge_checker(vertex_t *src, vertex_t *dest)
{
	edge_t *ed = NULL;

	ed = src->edges;

	while (ed != NULL)
	{
		if (ed->dest == dest)
			return (SUCC);
		ed = ed->next;
	}
	return (FAIL);
}

/**
 * graph_add_edge -  Adds an edge between two vertices of an existing graph
 * @graph: Pointer to the graph to add the edge
 * @s: Vertex to connect from
 * @d: Vertex to connect to
 * @type: Type of edge
 * UNIDIRECTIONAL: Unidirectional edge
 * BIDIRECTIONAL: Bidirectional edge
 * Return: 1 or 0 upon FAIL
 */

int graph_add_edge(graph_t *graph, const char *s, const char *d,
		   edge_type_t type)
{
	vertex_t *start, *end;

	if (graph == NULL || (type != UNIDIRECTIONAL && type != BIDIRECTIONAL))
		return (FAIL);
	start = get_vertices(graph, s);
	end = get_vertices(graph, d);
	if (!start || !end)
		return (FAIL);

	if (type == UNIDIRECTIONAL || type == BIDIRECTIONAL)
	{
		if (edge_checker(start, end))
			return (SUCC);
		if (!edge_creator(start, end))
			return (FAIL);
		start->nb_edges += 1;
	}

	if (type == BIDIRECTIONAL)
	{
		if (edge_checker(end, start))
			return (SUCC);
		if (!edge_creator(end, start))
			return (FAIL);
		end->nb_edges += 1;
	}
	return (SUCC);
}
