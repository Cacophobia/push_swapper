/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nranna <nranna@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 22:17:04 by nranna            #+#    #+#             */
/*   Updated: 2024/05/10 10:35:56 by nranna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "swap_push.h"

void	print_stack(t_stack *stack)
{
	t_node	*itr;

	itr = stack->head;
	while (itr)
	{
		printf("---------\n");
		printf("index: %ld\n NUMBER <%ld>\n", itr->index, itr->number);
		itr = itr->next;
	}
	return ;
}
