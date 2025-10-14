/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opr_reverse_rotate.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zotaj-di <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 23:21:36 by zotaj-di          #+#    #+#             */
/*   Updated: 2025/09/30 18:38:57 by zotaj-di         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

void	ft_reverse_rotate(t_stack *stack)
{
	if (!ft_is_full(stack))
	{
		(*stack).top = ft_next_up(stack, (*stack).top);
		(*stack).array[(*stack).top] = (*stack).array[(*stack).bottom];
		(*stack).array[(*stack).bottom] = 0;
		(*stack).bottom = ft_next_up(stack, (*stack).bottom);
	}
	else
	{
		(*stack).top = (*stack).bottom;
		(*stack).bottom = ft_next_up(stack, (*stack).bottom);
	}
}

void	reverse_rotate_a(t_ps *data)
{
	ft_reverse_rotate(&(*data).stack_a);
	if ((*data).record_opr)
		ft_save_opr(data, rra);
}

void	reverse_rotate_b(t_ps *data)
{
	ft_reverse_rotate(&(*data).stack_b);
	if ((*data).record_opr)
		ft_save_opr(data, rrb);
}

void	reverse_rotate_a_and_b(t_ps *data)
{
	ft_reverse_rotate(&(*data).stack_a);
	ft_reverse_rotate(&(*data).stack_b);
	if ((*data).record_opr)
		ft_save_opr(data, rrr);
}

/* reverse_rotate (void) Moves the bottom element of the stack to the top. */

// This function takes the element currently at the bottom and shifts it
// to become the new top element. All other elements shift down by one position.
// This corresponds to the "rra" or "rrb" operation in push_swap.

//--------- Params of the function: --------------------------
// stack -> (t_stack *) A pointer to the stack structure that will be modified.
//         The function will change the top and bottom indices and potentially
//         move data within the stack array.

//--------- Variables inside the function: --------------------------
//      Just like rotate, this function is efficient and doesn't require any
//      local variables, it works by manipulating the top and bottom pointers.

//--------- Setup to follow for implementation: --------------------------
//      The logic splits into two cases depending on whether the stack's
//      underlying array is full, the key difference here is the use of next_up
//      instead of next_down .
//
//
//  Scenario 1: The stack is NOT full (is_full(stack) is false)
//
//    Move the top pointer up:
//
//       stack->top = next_up(stk, stack->top);
//
//        The top pointer is moved to the empty slot "above"
//        its current position. In a circular array, "up" means moving
//        to the previous index, wrapping around to the end if it's at index 0.
//        This newly designated top is where the bottom element will be placed.
//
//    Copy the bottom element's value to the new top:
//
//        stack->array[stk->top] = stack->array[stack->bottom];
//
//        The value of the current bottom element is copied into
//        the new top position we just prepared.
//
//    Clear the old bottom position:
//
//        stack-array[stack->bottom] = 0;
//
//        The original bottom position is cleared by setting it to 0,
//        marking it as empty.
//
//    Move the bottom pointer up:
//
//        stk->bottom = next_up(stk, stk->bottom);
//
//        The bottom pointer is moved up to the element that was previously
//        second-to-last, making it the new official bottom of the stack.
//
//  Scenario 2: The stack IS full (is_full(stk) is true)
//
//  When the stack is full, there are no empty slots to move data into.
//  The reverse rotation is done "virtually" just by moving the pointers.
//
//    The old bottom becomes the new top:
//
//        stack->top = stack->bottom;
//
//        The top pointer is moved to where the bottom pointer currently is.
//        That element is now instantly the new top.
//
//    The element above the old bottom becomes the new bottom:
//
//        stack->bottom = next_up(stack, stack->bottom);
//
//        The bottom pointer is moved up to the previous element,
//        which becomes the new bottom of the stack. The rotation is finished
//        without copying any values.
