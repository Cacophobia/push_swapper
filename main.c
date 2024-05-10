/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nranna <nranna@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 03:44:24 by nranna            #+#    #+#             */
/*   Updated: 2024/05/09 22:26:49 by nranna           ###   ########.fr       */
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

void	radix(t_controller *controller)
{
	int				ref_bit;
	int				highest_bit;
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
}
