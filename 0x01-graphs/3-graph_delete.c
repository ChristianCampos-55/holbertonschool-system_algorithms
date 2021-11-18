#include "graphs.h"

/**
 * graph_delete - A function that deletes a whole graph
 * @graph: A pointer to graph to be deleted
 */

void graph_delete(graph_t *graph)
{
	vertex_t *del_v = NULL;
	edge_t *del_e = NULL;

	if (graph == NULL)
		return;

	while (graph->vertices != NULL)
	{
		while (graph->vertices->edges != NULL)
		{
			del_e = graph->vertices->edges;
			graph->vertices->edges = graph->vertices->edges->next;
			free(del_e);
		}

		del_v = graph->vertices;
		graph->vertices = graph->vertices->next;
		free(del_v->content);
		free(del_v);
		graph->nb_vertices -= 1;

	}

	free(graph);
	graph = NULL;

}