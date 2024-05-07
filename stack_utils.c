/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nranna <nranna@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 05:48:04 by nranna            #+#    #+#             */
/*   Updated: 2024/05/07 06:54:40 by nranna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PushSwap.h"

int	stack_pushback(t_node *node, t_stack *stack)
{
	t_node	*itr;

	if (stack->head == NULL)
	{
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

void	print_stack(t_stack *stack)
{
	t_node	*itr;

	itr = stack->head;
	while (itr)
	{
		printf("---------\n");
		printf("valor de index: %ld\nValor de number %ld\n", itr->index, itr->number);
		itr = itr->next;
	}
	return ;
}

void	index_stack(t_stack *stack)
{
	unsigned int i;

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
