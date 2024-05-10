/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nranna <nranna@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 18:01:20 by nranna            #+#    #+#             */
/*   Updated: 2024/05/09 22:13:48 by nranna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "swap_push.h"

// 6->5->8 vira 5->8->6

static int	rotate(t_stack *stack)
{
	t_node	*last;
	t_node	*old_head;

	if (!stack)
		return (1);
	else if (stack->size < 2)
		return (0);
	last = stack->head;
	while (last->next)
		last = last->next;
	old_head = stack->head;
	last->next = stack->head;
	stack->head = stack->head->next;
	old_head->next = NULL;
	return (0);
}

int	rotate_a(t_controller *controller)
{
	if (rotate(&controller->stack_a) == 1)
		return (1);
	write(1, "ra\n", 3);
	return (0);
}

int	rotate_b(t_controller *controller)
{
	if (rotate(&controller->stack_b) == 1)
		return (1);
	write(1, "rb\n", 3);
	return (0);
}

int	rotate_ab(t_controller *controller)
{
	if (rotate(&controller->stack_a) == 1)
		return (1);
	if (rotate(&controller->stack_b) == 1)
		return (1);
	write(1, "rr\n", 3);
	return (0);
}
