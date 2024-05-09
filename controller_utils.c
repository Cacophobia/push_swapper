/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controller_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nranna <nranna@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 15:26:37 by nranna            #+#    #+#             */
/*   Updated: 2024/05/09 15:32:57 by nranna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "swap_push.h"

void	clear_controller(t_controller *controller)
{
	clear_stack(&controller->stack_a);
	clear_stack(&controller->stack_b);
	return ;
}
