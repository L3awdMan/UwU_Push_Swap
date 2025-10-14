/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimize_sort_asap.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zotaj-di <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 02:21:02 by zotaj-di          #+#    #+#             */
/*   Updated: 2025/09/03 02:22:27 by zotaj-di         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	split_max_reduction(t_ps *data, t_chunk *max)
{
	t_stack	*a;

	a = &(*data).stack_a;
	if ((*max).loc == TOP_A && (*max).size == 3 && is_consecutive(ft_value(a,
				1), ft_value(a, 2), ft_value(a, 3), ft_value(a, 4))
		&& a_partly_sort(data, 4))
	{
		sort_three(data, max);
		return ;
	}
	if ((*max).loc == TOP_A && ft_value(a, 1) == ft_value(a, 3) - 1
		&& a_partly_sort(data, 3))
	{
		swap_a(data);
		(*max).size--;
	}
	if ((*max).loc == TOP_A && a_partly_sort(data, 1))
		(*max).size--;
}

bool	a_partly_sort(t_ps *data, int from)
{
	int		i;
	t_stack	*a;
	int		value;

	a = &(*data).stack_a;
	i = (*a).top;
	while (--from)
		i = ft_next_down(a, i);
	while ((*a).array[i] != (*data).stack_a.size)
	{
		value = (*a).array[i];
		i = ft_next_down(a, i);
		if ((*a).array[i] != value + 1)
			return (false);
	}
	return (true);
}

bool	is_consecutive(int a, int b, int c, int d)
{
	sort_three_numbers(&a, &b, &c);
	return ((b - a == 1) && (c - b == 1) && (d - c == 1));
}

void	sort_three_numbers(int *a, int *b, int *c)
{
	int	temp;

	if (*a > *b)
	{
		temp = *a;
		*a = *b;
		*b = temp;
	}
	if (*a > *c)
	{
		temp = *a;
		*a = *c;
		*c = temp;
	}
	if (*b > *c)
	{
		temp = *b;
		*b = *c;
		*c = temp;
	}
}
