#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include <ctype.h>
# include <limits.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stdio.h>

# define NOT_INDEXED -1

typedef struct s_node
{
	long int	index;
	long int	number;
	struct s_node	*next;
}	t_node;

typedef struct s_stack
{
	t_node		*head;
	unsigned int	size;
}	t_stack;

typedef struct s_controller
{
	t_stack	stack_a;
	t_stack	stack_b;
}	t_controller;

int validate_args(int argc, char **argv);

// node utils
t_node	*create_node(int index, long int nbr);

// stack utils
void	print_stack(t_stack *stack);
int	stack_pushback(t_node *node, t_stack *stack);
void	index_lowest_n(unsigned int index, t_stack *stack);
void	index_stack(t_stack *stack);

#endif // !PUSHSWAP_H
