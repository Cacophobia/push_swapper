/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nranna <nranna@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 05:48:04 by nranna            #+#    #+#             */
/*   Updated: 2024/05/09 22:24:00 by nranna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "swap_push.h"

int	stack_pushback(t_node *node, t_stack *stack)
{
	t_node	*itr;

	if (stack->head == NULL)
	{
		node->next = NULL;
		stack->head = node;
		stack->size++;
		return (0);
	}
	itr = stack->head;
	while (itr->next != NULL)
		itr = itr->next;
	itr->next = node;
	stack->size++;
	return (0);
}

int	stack_pushfront(t_node *node, t_stack *stack)
{
	t_node	*tmp;

	if (!node)
		return (1);
	if (stack->head == NULL)
	{
		node->next = NULL;
		stack->head = node;
		stack->size++;
		return (0);
	}
	tmp = stack->head;
	stack->head = node;
	node->next = tmp;
	stack->size++;
	return (0);
}

void	index_stack(t_stack *stack)
{
	unsigned int	i;

	i = 0;
	while (i < stack->size)
	{
		index_lowest_n(i, stack);
		i++;
	}
	return ;
}

void	index_lowest_n(unsigned int index, t_stack *stack)
{
	t_node		*itr;
	t_node		*lil_reff;
	long int	min;

	min = LONG_MAX;
	itr = stack->head;
	lil_reff = stack->head;
	while (itr)
	{
		if (itr->index == NOT_INDEXED && itr->number < min)
		{
			lil_reff = itr;
			min = itr->number;
		}
		itr = itr->next;
	}
	lil_reff->index = index;
}

bool	load_stack(t_stack *stack, char **argv)
{
	int		i;
	int		ref;
	t_node	*aux;

	if (!stack)
		return (false);
	i = 0;
	while (argv[i])
	{
		ref = atol(argv[i]);
		if (search_number(stack, ref) == true)
		{
			write(1, "Error! Equal numbers detected\n", 31);
			return (false);
		}
		aux = create_node(NOT_INDEXED, atol(argv[i]));
		if (!aux)
			return (false);
		stack_pushback(aux, stack);
		i++;
	}
	return (true);
}

void	clear_stack(t_stack *stack)
{
	t_node	*curr;
	t_node	*next;

	if (!stack || !stack->head)
		return ;
	curr = stack->head;
	while (curr)
	{
		next = curr->next;
		free(curr);
		curr = next;
	}
	stack->size = 0;
	stack->head = NULL;
	return ;
}
