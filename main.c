/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nranna <nranna@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 03:44:24 by nranna            #+#    #+#             */
/*   Updated: 2024/05/09 16:21:47 by nranna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//TODO: operacoes;
//TODO: radix bubble sort, vc decide

#include "swap_push.h"

int main(int argc, char **argv)
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
	index_stack(&controller.stack_a);
	push_b(&controller);
	print_stack(&controller.stack_a);
	printf("\n stack b now\n");
	print_stack(&controller.stack_b);
	clear_controller(&controller);
	return (EXIT_SUCCESS);
}
