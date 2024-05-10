/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nranna <nranna@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 03:44:24 by nranna            #+#    #+#             */
/*   Updated: 2024/05/10 10:34:45 by nranna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "swap_push.h"

int	main(int argc, char **argv)
{
	t_controller	controller;

	memset(&controller, 0, sizeof(t_controller));
	if (validate_args(argc, argv) != EXIT_SUCCESS)
		return (EXIT_FAILURE);
	if (load_stack(&controller.stack_a, &argv[1]) == false)
	{
		clear_controller(&controller);
		return (EXIT_FAILURE);
	}
	controller.total_args = argc - 1;
	index_stack(&controller.stack_a);
	if (is_sorted(&controller.stack_a))
		;
	else if (argc == 3)
		swap_a(&controller);
	else if (argc == 4)
		sort_three(&controller, &controller.stack_a);
	else if (argc == 6)
		sort_five(&controller, &controller.stack_a);
	else
		radix(&controller);
	clear_controller(&controller);
	return (EXIT_SUCCESS);
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
