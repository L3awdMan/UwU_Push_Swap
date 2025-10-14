/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimize_to_the_top.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zotaj-di <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 02:26:24 by zotaj-di          #+#    #+#             */
/*   Updated: 2025/09/03 02:30:43 by zotaj-di         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	chunk_to_the_top(t_ps *data, t_chunk *to_sort)
{
	if ((*to_sort).loc == BOTTOM_B
		&& ft_current_size(&(*data).stack_b) == (*to_sort).size)
		(*to_sort).loc = TOP_B;
	if ((*to_sort).loc == BOTTOM_A
		&& ft_current_size(&(*data).stack_a) == (*to_sort).size)
		(*to_sort).loc = TOP_A;
}
