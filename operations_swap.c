/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_swap.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nranna <nranna@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 13:02:15 by nranna            #+#    #+#             */
/*   Updated: 2024/05/09 15:47:40 by nranna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "swap_push.h"

static int	swap(t_stack stack)
{
	t_node	*head;
	t_node	*next;
	int	tmp_number;
	int	tmp_index;

	if (stack.size < 2)
		return (EXIT_FAILURE);
	head = stack.head;
	next = stack.head->next;
	if (!head && !next)
	{
		write(1, "Error\n", 6);
		return (EXIT_FAILURE);
	}
	tmp_number = head->number;
	tmp_index = head->index;
	head->number = next->number;
	head->index = next->index;
	next->number = tmp_number;
	next->index = tmp_index;
	return (EXIT_SUCCESS);
}

int	swap_a(t_controller *controller)
{
	if (swap(controller->stack_a) != EXIT_SUCCESS)
		return (EXIT_FAILURE);
	write(STDOUT_FILENO, "sa\n", 3);
	return (EXIT_SUCCESS);
}

int	swap_b(t_controller *controller)
{
	if (swap(controller->stack_b) != EXIT_SUCCESS)
		return (EXIT_FAILURE);
	write(STDOUT_FILENO, "sb\n", 3);
	return (EXIT_SUCCESS);
}

int	swap_ab(t_controller *controller)
{
	if (swap(controller->stack_a) != EXIT_SUCCESS)
		return (EXIT_FAILURE);
	if (swap(controller->stack_b) != EXIT_SUCCESS)
		return (EXIT_FAILURE);
	write(STDOUT_FILENO, "ss\n", 3);
	return (EXIT_SUCCESS);
}
