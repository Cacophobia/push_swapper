/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_push.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nranna <nranna@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 15:48:29 by nranna            #+#    #+#             */
/*   Updated: 2024/05/09 16:23:27 by nranna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "swap_push.h"

static int	push(t_stack *stack_src, t_stack *stack_dest)
{
	t_node	*tmp;

	if (!stack_src || !stack_dest)
		return (1);
	if (stack_src->size == 0)
		return (0);
	tmp = stack_src->head;
	stack_src->head = stack_src->head->next;
	stack_src->size--;
	stack_pushfront(tmp, stack_dest);
	return (0);
}

int	push_a(t_controller *controller)
{
	if (!controller)
		return (1);
	if (push(&controller->stack_b, &controller->stack_a) == 1)
		return (1);
	write(1, "pa\n", 3);
	return (0);
}

int	push_b(t_controller *controller)
{
	if (!controller)
		return (1);
	if (push(&controller->stack_a, &controller->stack_b) == 1)
		return (1);
	write(1, "pb\n", 3);
	return (0);
}
