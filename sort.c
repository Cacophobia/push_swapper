/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nranna <nranna@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 18:30:34 by nranna            #+#    #+#             */
/*   Updated: 2024/05/09 22:15:49 by nranna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "swap_push.h"

static int	highest_bit_stack(t_stack *stack)
{
	int	highest_bit;

	if (!stack)
		return (-1);
	highest_bit = (8 * sizeof(stack->size)) - 1;
	while (highest_bit >= 0)
	{
		if (stack->size & (1 << highest_bit))
			break ;
		highest_bit--;
	}
	return (highest_bit);
}
/*
void	radix(t_controller *controller)
{
	int	ref_bit;
	int	highest_bit;
	unsigned int	i;

	ref_bit = 0;
	highest_bit = highest_bit_stack(&controller->stack_a);
	while (ref_bit <= highest_bit)
	{
		i = 0;
		while (i < controller->total_args)
		{
			if (controller->stack_a.head->index & (1 << ref_bit))
				rotate_a(controller);
			else
				push_b(controller);
			i++;
		}
		while (controller->stack_b.head != NULL)
			push_a(controller);
		ref_bit++;
		if (is_sorted(&controller->stack_a))
			break ;
	}
}*/

bool	is_sorted(t_stack *stack)
{
	t_node			*itr;
	unsigned int	i;

	itr = stack->head;
	i = 0;
	while (itr)
	{
		if (itr->index != i)
			return (false);
		itr = itr->next;
		i++;
	}
	return (true);
}

void	sort_three(t_controller *controller, t_stack *stack)
{
	if (stack->head->index == 0 && stack->head->next->next->index == 1)
	{
		revrotate_a(controller);
		swap_a(controller);
	}
	else if (stack->head->index == 1)
	{
		if (stack->head->next->next->index == 0)
			revrotate_a(controller);
		else
			swap_a(controller);
	}
	else if (stack->head->index == 2)
	{
		if (stack->head->next->next->index == 0)
		{
			rotate_a(controller);
			swap_a(controller);
		}
		else
			rotate_a(controller);
	}
}

//void sort_five(t_controller *controller, t_stack *stack)
