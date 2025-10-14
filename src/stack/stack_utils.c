/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zotaj-di <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 21:27:02 by zotaj-di          #+#    #+#             */
/*   Updated: 2025/09/30 18:49:35 by zotaj-di         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

int	ft_next_up(t_stack *stack, int i)
{
	if (ft_current_size(stack) == 0)
		return (i);
	if (i == 0)
		return ((*stack).size - 1);
	else
		return (i - 1);
}

int	ft_next_down(t_stack *stack, int i)
{
	if (ft_current_size(stack) == 0)
		return (i);
	if (i == (*stack).size - 1)
		return (0);
	else
		return (i + 1);
}

int	ft_value(t_stack *stack, int n)
{
	int	i;

	i = (*stack).top;
	while (--n > 0)
		i = ft_next_down(stack, i);
	return ((*stack).array[i]);
}

int	ft_current_size(t_stack *stack)
{
	if (((*stack).top == (*stack).bottom) && (*stack).array[(*stack).top] == 0)
		return (0);
	if ((*stack).top > (*stack).bottom)
		return (((*stack).size - (*stack).top) + ((*stack).bottom + 1));
	else
		return ((*stack).bottom - (*stack).top + 1);
}

bool	ft_is_full(t_stack *stack)
{
	return ((*stack).size == ft_current_size(stack));
}
