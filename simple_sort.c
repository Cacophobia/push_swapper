/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nranna <nranna@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 18:30:34 by nranna            #+#    #+#             */
/*   Updated: 2024/05/10 10:31:30 by nranna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "swap_push.h"

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

void	sort_five(t_controller *controller, t_stack *stack)
{
	while (stack->head->index != 3 && stack->head->index != 4)
		revrotate_a(controller);
	push_b(controller);
	while (stack->head->index != 3 && stack->head->index != 4)
		revrotate_a(controller);
	push_b(controller);
	sort_three(controller, &controller->stack_a);
	if (controller->stack_b.head->index == 4)
		push_a(controller);
	else
	{
		rotate_b(controller);
		push_a(controller);
	}
	push_a(controller);
	rotate_a(controller);
	rotate_a(controller);
}
