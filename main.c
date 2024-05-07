/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nranna <nranna@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 03:44:24 by nranna            #+#    #+#             */
/*   Updated: 2024/05/07 08:29:11 by nranna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//TODO: extrair o while 14-24 p funcao;
//TODO: cleanup clear_stack;
//TODO: operacoes;
//TODO: radix bubble sort o caralha4

#include "swap_push.h"

int main(int argc, char **argv)
{
	t_controller	controller;
	int	i;
	t_node	*aux;

	i = 1;
	memset(&controller, 0, sizeof(t_controller));
	if (validate_args(argc, argv) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	//TODO: transformar os argv em long long
	while (argv[i])
	{
		aux = create_node(NOT_INDEXED, atol(argv[i]));
		if (!aux)
		{
			// TODO: CLEANUP FUNCTION
			return (EXIT_FAILURE);
		}
		stack_pushback(aux, &controller.stack_a);
		i++;
	}
	index_stack(&controller.stack_a);
	print_stack(&controller.stack_a);
	return (EXIT_SUCCESS);
}
