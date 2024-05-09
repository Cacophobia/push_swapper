/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nranna <nranna@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 08:30:29 by nranna            #+#    #+#             */
/*   Updated: 2024/05/09 19:55:26 by nranna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "swap_push.h"

static int is_valid_number(char const *str);

int validate_args(int argc, char **argv)
{
	int	i;

	if (argc < 3)
	{
		write(2, "Error! Invalid ammount of arguments\n", 36);
		return (EXIT_FAILURE);
	}
	i = 1;
	while (argv[i])
	{
		if (is_valid_number(argv[i]) != EXIT_SUCCESS)
			return (EXIT_FAILURE);
		i++;
	}
	return (EXIT_SUCCESS);
}

static int is_valid_number(char const *str)
{
	int	i;

	i = 0;
	if (str[0] == '+' || str[0] == '-')
		i++;
	while (str[i])
	{
		if (isdigit(str[i]) == 0)
		{
			write(2, "Error! nondigit char found\n", 28);
			return (EXIT_FAILURE);
		}
		i++;
	}
	return (EXIT_SUCCESS);
}

bool	search_number(t_stack *stack, int find)
{
	t_node	*itr;
	
	if (!stack || !stack->head)
		return (false);
	itr = stack->head;
	while (itr)
	{
		if (itr->number == find)
			return (true);
		itr = itr->next;
	}
	return (false);
}
