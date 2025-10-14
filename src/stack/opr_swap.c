/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opr_swap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zotaj-di <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 21:43:01 by zotaj-di          #+#    #+#             */
/*   Updated: 2025/09/30 18:39:47 by zotaj-di         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

void	ft_swap(t_stack *stack)
{
	int	tmp;

	if ((*stack).array[ft_next_down(stack, (*stack).top)] == 0)
		return ;
	tmp = (*stack).array[ft_next_down(stack, (*stack).top)];
	(*stack).array[ft_next_down(stack,
			(*stack).top)] = (*stack).array[(*stack).top];
	(*stack).array[(*stack).top] = tmp;
}

void	swap_a(t_ps *data)
{
	ft_swap(&(*data).stack_a);
	if ((*data).record_opr)
		ft_save_opr(data, sa);
}

void	swap_b(t_ps *data)
{
	ft_swap(&(*data).stack_b);
	if ((*data).record_opr)
		ft_save_opr(data, sb);
}

void	swap_a_and_b(t_ps *data)
{
	ft_swap(&(*data).stack_a);
	ft_swap(&(*data).stack_b);
	if ((*data).record_opr)
		ft_save_opr(data, ss);
}

/* `ft_swap` (void) Swaps the top two elements of a stack. */

// This function's goal is to exchange the positions of the very top element
// and the one right below it. It doesn't return anything because it modifies
// the stack directly.

//--------- Params : ------------------------------
// stack -> (t_stack *) A pointer to the stack structure that needs to be
//         modified, it contains the array of numbers(stack) and the index
//         of the `top` element

//--------- Variables : --------------------------
// tmp -> (int) A temporary variable used as a placeholder to hold
//       one of the values during the swap. You need this so you don't lose
//       one of the numbers when you overwrite it.

//--------- Setup : ------------------------------
//
//    - Check for sufficient elements:
//
//        The first step is a safety check. A swap operation is only possible
//        if there are at least two elements on the stack.
//
//        The code if (stack->array[next_down(stack, stack->top)] == 0)
//        is a way to check this. It looks at the element just below the top.
//        If that element is 0, it assumes the stack is empty there
//        and that there aren't two elements to swap. If that's the case,
//        the function simply stops and does nothing (return).
//
//    - Store the second element:
//
//        We need to save the value of the second element before we overwrite it
//
//        tmp = stack->array[next_down(stk, stack->top)];
//
//        This line takes the value of the element below the top and stores it
//        in our temporary variable tmp.
//
//    - Move the top element down:
//
//        Now that the second element's value is safely stored,
//        we can overwrite it with the top element's value.
//
//        stack->array[next_down(stack, stack->top)] = stack->array[stack->top];
//
//        This line copies the value from the top position into the position
//        below it. At this point, both the top and second positions hold
//        the same value.
//
//    - Place the stored value on top:
//
//       Finally, we take the value we saved in tmp (which was the original
//        second element) and place it at the top of the stack.
//
//        stack->array[stack->top] = tmp;
