/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nranna <nranna@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 03:44:24 by nranna            #+#    #+#             */
/*   Updated: 2024/05/09 16:01:56 by nranna           ###   ########.fr       */
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
	if (load_stack(&controller.stack_a, argv) == false)
	{
		clear_controller(&controller);
		return (EXIT_FAILURE);
	}
	stack_pushfront(create_node(NOT_INDEXED, 999), &controller.stack_a);
	index_stack(&controller.stack_a);
	print_stack(&controller.stack_a);
	clear_controller(&controller);
	return (EXIT_SUCCESS);
}
