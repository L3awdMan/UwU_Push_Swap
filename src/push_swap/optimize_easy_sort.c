/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimize_easy_sort.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zotaj-di <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 19:54:43 by zotaj-di          #+#    #+#             */
/*   Updated: 2025/09/02 20:08:25 by zotaj-di         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	easy_sort(t_ps *data, t_chunk *to_sort)
{
	while ((*to_sort).loc != TOP_A && (*to_sort).size)
	{
		if (ft_value(&(*data).stack_a, 1) == ft_chunk_value(data, to_sort, 1)
			+ 1 && (*to_sort).size > 0)
			sort_one(data, to_sort);
		else if (ft_value(&(*data).stack_a, 1) == ft_chunk_value(data, to_sort,
				2) + 1 && (*to_sort).size > 1)
			easy_sort_second(data, to_sort);
		else
			break ;
	}
}

void	easy_sort_second(t_ps *data, t_chunk *to_sort)
{
	if ((*to_sort).loc == TOP_B)
		handle_top_b(data, to_sort);
	else if ((*to_sort).loc == BOTTOM_A)
		handle_bottom_a(data, to_sort);
	else if ((*to_sort).loc == BOTTOM_B)
		handle_bottom_b(data, to_sort);
	(*to_sort).size--;
}

void	handle_top_b(t_ps *data, t_chunk *to_sort)
{
	swap_b(data);
	push_to_a(data);
	if (ft_value(&(*data).stack_b, 1) == ft_value(&(*data).stack_a, 1) - 1)
	{
		push_to_a(data);
		(*to_sort).size--;
	}
}

void	handle_bottom_a(t_ps *data, t_chunk *to_sort)
{
	reverse_rotate_a(data);
	reverse_rotate_a(data);
	swap_a(data);
	if (ft_value(&(*data).stack_a, 1) == ft_value(&(*data).stack_a, 2) - 1)
		(*to_sort).size--;
	else
		rotate_a(data);
}

void	handle_bottom_b(t_ps *data, t_chunk *to_sort)
{
	reverse_rotate_b(data);
	reverse_rotate_b(data);
	push_to_a(data);
	if (ft_value(&(*data).stack_b, 1) == ft_value(&(*data).stack_a, 1) - 1)
	{
		push_to_a(data);
		(*to_sort).size--;
	}
	else
		rotate_b(data);
}
