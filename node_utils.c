/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nranna <nranna@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 05:32:55 by nranna            #+#    #+#             */
/*   Updated: 2024/05/09 17:36:13 by nranna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "swap_push.h"

t_node	*create_node(int index, long int nbr)
{
	t_node	*new_node;

	new_node = malloc(sizeof(t_node));
	if (!new_node)
		return (NULL);
	new_node->index = index;
	new_node->number = nbr;
	new_node->next = NULL;
	return (new_node);
}
