#include "graphing.h"

char	g_nodes[MAX_NODES][MAX_STRLEN];

int	get_choice(void)
{
	char	choice[MAX_STRLEN];

	while (true)
	{
		fprintf(stderr, YELLOW"1. Add node, 2. Delete node, 3. Done: "RESET);
		scanf("%s", choice);
		if (atoi(choice) == ADD_NODE || atoi(choice) == DELETE_NODE)
		{
			return (atoi(choice));
		}
		else if (atoi(choice) == DONE)
		{
			return (DONE);
		}
		else
		{
			fprintf(stderr, RED"Invalid choice\n"RESET);
		}
	}
}

unsigned int	get_from(void)
{
	char	choice[MAX_STRLEN];

	while (true)
	{
		fprintf(stderr, "Input the from_node number: ");
		scanf("%s", choice);
		if (isdigit(choice[0]))
		{
			return (atoi(choice));
		}
		else
		{
			fprintf(stderr, RED"Invalid choice\n"RESET);
		}
	}
}

unsigned int	get_to(void)
{
	char	choice[MAX_STRLEN];

	while (true)
	{
		fprintf(stderr, "Input the to_node number: ");
		scanf("%s", choice);
		if (isdigit(choice[0]))
		{
			return (atoi(choice));
		}
		else
		{
			fprintf(stderr, RED"Invalid choice\n"RESET);
		}
	}
}

void	create_graph(t_graph *graph, unsigned int num_nodes)
{
	printf("digraph {\n");
	for (unsigned int i = 0; i < num_nodes; i++)
	{
		for (unsigned int j = 0; j < num_nodes; j++)
		{
			if (graph->graph[i][j] == true)
			{
				printf("%s->%s;\n", g_nodes[i], g_nodes[j]);
			}
		}
	}
	printf("}\n");
}

int main(int ac, char **av)
{
	t_graph			*graph;
	char			user_input[MAX_STRLEN];
	int				choice;
	unsigned int	num_nodes;
	unsigned int	from;
	unsigned int	to;

	if (ac != 2)
	{
		fprintf(stderr, RED"Usage: ./graph (num_nodes)"RESET);
		return (1);
	}

	num_nodes = atoi(av[1]);
	// Check if the number of nodes is reasonable
	if (num_nodes <= 0)
	{
		fprintf(stderr, RED"Non numeric value or non-reasonable num_nodes, ");
		fprintf(stderr, "Please give a correct argument!\n"RESET);
		return (1);
	}

	graph = init_graph(num_nodes);

	for (unsigned int i = 0; i < num_nodes; i++)
	{
		fprintf(stderr, YELLOW"Give name for node %d: "RESET, i);
		scanf("%s", user_input);
		strcpy(g_nodes[i], user_input); 
	}

	while (true)
	{
		choice = get_choice();
		if (choice == ADD_NODE)
		{
			from = get_from();
			to = get_to();
			if (add_node(graph, from, to) == false)
			{
				fprintf(stderr, "The node already exist\n");
			}
		}
		else if (choice == DELETE_NODE)
		{
			from = get_from();
			to = get_to();
			if (delete_node(graph, from, to) == false)
			{
				fprintf(stderr, "Node does not exist\n");
			}
		}
		else if (choice == DONE)
		{
			create_graph(graph, num_nodes);
			for (unsigned int i = 0; i < num_nodes; i++)
			{
				free(graph->graph[i]);
			}
			free(graph->graph);
			free(graph);
			fprintf(stderr, CYAN"Graph generated!\n"RESET); 
			return (0);
		}
	}

	if (graph == NULL)
	{
		fprintf(stderr, "Some error occured while generating graph\n");
		return (1);
	}
}
