#include "../includes/graphing.h"

t_graph	*init_graph(unsigned int num_nodes)
{
	t_graph	*graph;

	graph = malloc(sizeof(t_graph));
	// Protection when malloc failed
	if (graph == NULL)
	{
		return (NULL);
	}

	graph->num_nodes = num_nodes;
	graph->graph = calloc(num_nodes, sizeof(bool *));
	// Protection when calloc failed
	if (graph->graph == NULL)
	{
		free(graph);
		return (NULL);
	}

	for (unsigned int i = 0; i < num_nodes; i++)
	{
		graph->graph[i] = calloc(num_nodes, sizeof(bool));
		// Protection when calloc for rows failed
		if (graph->graph[i] == NULL)
		{
			for (unsigned int j = 0; j < i; j++)
			{
				free(graph->graph[j]);
			}
			free(graph->graph);
			free(graph);
			return (NULL);
		}
	}

	return (graph);
}

bool	add_node(t_graph *graph, unsigned int from, unsigned int to)
{
	if (graph == NULL || graph->graph == NULL)
	{
		return (false);
	}

	if (graph->graph[from][to] == true)
	{
		return (false);
	}
	graph->graph[from][to] = true;
	return (true);
}

bool	delete_node(t_graph *graph, unsigned int from, unsigned int to)
{
	if (graph == NULL || graph->graph == NULL)
	{
		return (false);
	}

	if (graph->graph[from][to] == false)
	{
		return (false);
	}
	graph->graph[from][to] = false;
	return (true);
}
