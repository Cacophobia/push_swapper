/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nranna <nranna@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 16:42:35 by nranna            #+#    #+#             */
/*   Updated: 2024/05/09 17:12:10 by nranna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "swap_push.h"

static	int	rotate(t_stack *stack)
{
	t_node	*last;
	t_node	*second_to_last;

	if (!stack)
		return (1);
	else if (stack->size < 2)
		return (0);
	 last = stack->head;
	 second_to_last = stack->head;
	 last = last->next;
	 while (last->next != NULL)
	 {
		 last = last->next;
		 second_to_last = second_to_last->next;
	 }
	last->next = stack->head;
	stack->head = last;
	second_to_last->next = NULL;
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
