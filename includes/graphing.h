#ifndef GRAPHING_H_
# define GRAPHING_H_

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <stdbool.h>
# include <ctype.h>

# define MAX_NODES 100
# define MAX_STRLEN 100
# define ADD_NODE 1
# define DELETE_NODE 2
# define DONE 3

struct s_list {
	char			*node_name;
	struct s_list	*next;
};

typedef struct s_list t_list;

struct s_graph {
	unsigned int	num_nodes;
	bool			**graph;
};

typedef struct s_graph t_graph;

t_graph	*init_graph(unsigned int num_nodes);
bool	add_node(t_graph *graph, unsigned int from, unsigned int to);
bool	delete_node(t_graph *graph, unsigned int from, unsigned int to);

#endif /*graphing.h*/
