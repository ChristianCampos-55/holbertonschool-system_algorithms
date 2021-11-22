#include "graphs.h"

#define  UNCHECKED 0
#define  CHECKED 1

/**
 * index_getter - Looks for a vertex in a graph
 * @graph: Pointer to graph to search
 * @index: Index of vertex to search
 * Return: Vertex or NULL upon failure
 */

vertex_t *index_getter(const graph_t *graph, size_t index)
{
	vertex_t *n;

	if (index > graph->nb_vertices)
		return (NULL);

	n = graph->vertices;

	if (n == NULL)
		return (NULL);

	while (n != NULL)
	{
		if (n->index == index)
		{
			return (n);
		}
		n = n->next;
	}
	return (NULL);
}

/**
 * depth_traverser - A function that traverses a graph depth first
 * @vertex: Vertex to find
 * @checked: Nodes to check
 * @curr_depth: Depth of current node
 * @depth: Max graph depth
 * @graph: Graph to traverse
 * @action: Function to call each check.
 * Return: Depth of current vertex or 0 upon failure
 */

void depth_traverser(int vertex, size_t *checked, size_t curr_depth,
		size_t *depth, const graph_t *graph, void (*action) (const vertex_t *v,
						     size_t curr_depth))
{
	vertex_t *d, *current;
	edge_t *edge;

	current = index_getter(graph, vertex);

	if (current != NULL && checked[vertex] != CHECKED)
	{
		action(current, curr_depth);
		if (curr_depth > *depth)
			*depth = curr_depth;
		checked[vertex] = CHECKED;
		edge = current->edges;
		while (edge != NULL)
		{
			d = edge->dest;
			if (checked[d->index] != CHECKED)
			{
				depth_traverser(d->index, checked, curr_depth + 1,
					 depth, graph, action);
			}

			edge = edge->next;

		}
	}
}

/**
 * depth_first_traverse - Function that traverses a graph
 * @graph: Graph to traverse
 * @action: Function to call on traverse
 * Return: Depth of current vertex or 0 upon failure
 */
size_t depth_first_traverse(const graph_t *graph,
			    void (*action)(const vertex_t *v, size_t depth))
{
	size_t *checked;
	vertex_t *current;

	size_t depth = 0;

	if (graph != NULL)
	{
		checked = calloc(graph->nb_vertices, sizeof(size_t));
		current = graph->vertices;

		if (current)
		{
			if (checked[current->index] == UNCHECKED)
				depth_traverser(current->index, checked, 0, &depth,
					 graph, action);
			current = current->next;
		}
		free(checked);
	}
	return (depth);
}
