/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_push.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nranna <nranna@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 22:30:59 by nranna            #+#    #+#             */
/*   Updated: 2024/05/09 22:33:37 by nranna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SWAP_PUSH_H
# define SWAP_PUSH_H

# include <ctype.h>
# include <limits.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stdio.h>
# include <stdbool.h>

# define NOT_INDEXED -1

typedef struct s_node
{
	long int		index;
	long int		number;
	struct s_node	*next;
}	t_node;

typedef struct s_stack
{
	t_node			*head;
	unsigned int	size;
}	t_stack;

typedef struct s_controller
{
	t_stack			stack_a;
	t_stack			stack_b;
	unsigned int	total_args;
}	t_controller;

// input validations
int		validate_args(int argc, char **argv);
bool	search_number(t_stack *stack, int find);

// node utils
t_node	*create_node(int index, long int nbr);

// stack utils
void	print_stack(t_stack *stack);
int		stack_pushback(t_node *node, t_stack *stack);
int		stack_pushfront(t_node *node, t_stack *stack);
void	index_lowest_n(unsigned int index, t_stack *stack);
void	index_stack(t_stack *stack);
bool	load_stack(t_stack *stack, char **argv);
void	clear_stack(t_stack *stack);

// controller utils
void	clear_controller(t_controller *controller);

// operations
int		swap_a(t_controller *controller);
int		swap_b(t_controller *controller);
int		swap_ab(t_controller *controller);
int		push_a(t_controller *controller);
int		push_b(t_controller *controller);
int		revrotate_a(t_controller *controller);
int		revrotate_b(t_controller *controller);
int		revrotate_ab(t_controller *controller);
int		rotate_a(t_controller *controller);
int		rotate_b(t_controller *controller);
int		rotate_ab(t_controller *controller);

// algo
void	radix(t_controller *controller);
bool	is_sorted(t_stack *stack);
void	sort_three(t_controller *controller, t_stack *stack);
void 	sort_five(t_controller *controller, t_stack *stack)
int		find_min_index(t_stack *stack)

#endif // !SWAP_PUSH_H
