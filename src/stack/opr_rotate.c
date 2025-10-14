/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opr_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zotaj-di <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 18:24:45 by zotaj-di          #+#    #+#             */
/*   Updated: 2025/09/30 18:39:22 by zotaj-di         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

void	ft_rotate(t_stack *stack)
{
	if (!ft_is_full(stack))
	{
		(*stack).bottom = ft_next_down(stack, (*stack).bottom);
		(*stack).array[(*stack).bottom] = (*stack).array[(*stack).top];
		(*stack).array[(*stack).top] = 0;
		(*stack).top = ft_next_down(stack, (*stack).top);
	}
	else
	{
		(*stack).bottom = (*stack).top;
		(*stack).top = ft_next_down(stack, (*stack).top);
	}
}

void	rotate_a(t_ps *data)
{
	ft_rotate(&(*data).stack_a);
	if ((*data).record_opr)
		ft_save_opr(data, ra);
}

void	rotate_b(t_ps *data)
{
	ft_rotate(&(*data).stack_b);
	if ((*data).record_opr)
		ft_save_opr(data, rb);
}

void	rotate_a_and_b(t_ps *data)
{
	ft_rotate(&(*data).stack_a);
	ft_rotate(&(*data).stack_b);
	if ((*data).record_opr)
		ft_save_opr(data, rr);
}

/* rotate (void) Moves the top element of the stack to the bottom. */

// This function takes the element currently at the top and shifts it to become
// the new bottom element. All other elements shift up by one position.
// This is the "ra" or "rb" operation in push_swap.

//--------- Params : --------------------------
// stack -> (t_stack *) A pointer to the stack structure. This function will
//         modify the top and bottom pointers/indices of this stack,
//         and potentially move data within its stack array.

//--------- Variables inside the function: --------------------------
//      This function doesn't use any local variables like tmp.
//      It achieves the rotation by moving the top and bottom
//      pointers and only copying data when necessary.

//--------- Setup to follow for implementation: --------------------------
//      This function has two main scenarios based on whether the underlying
//      array holding the stack is completely full. Your implementation
//      uses a circular array, where the "end" of the array wraps around
//      to the "beginning".
//
//  Scenario 1: The stack is NOT full (is_full(stack) is false)
//
//    Move the bottom pointer down:
//
//        stack->bottom = next_down(stack, stack->bottom);
//
//        The bottom pointer, which marks the "end" of your stack, is moved
//        to the next available empty slot. In a circular array, "down" means
//        moving to the next index, wrapping around to 0 if it hits the end.
//        This new spot is where the old top element will go.
//
//    Copy the top element's value to the new bottom:
//
//        stack->array[stack->bottom] = stack->array[stack->top];
//
//        The value of the current top element is copied into the new bottom
//        position we just prepared.
//
//    Clear the old top position:
//
//        stack->array[stack->top] = 0;
//
//        The original top position is set to 0 to signify it's now "empty".
//        This is important for your logic to correctly identify stack elements.
//
//    Move the top pointer down:
//
//        stack->top = next_down(stack, stack->top);
//
//        The top pointer is moved down to the next element, which has now
//        become the new top of the stack.
//
//  Scenario 2: The stack IS full (is_full(stk) is true)
//
//  When the stack is full, you can't copy data into an empty slot
//  because there aren't any. The rotation is achieved simply by moving the top
//  and bottom pointers.
//
//    The old top becomes the new bottom:
//
//        stack->bottom = stack->top;
//
//        The bottom pointer is moved to where the top pointer currently is.
//        That element is now considered the "bottom" of the stack.
//
//    The element below the old top becomes the new top:
//
//        stack->top = next_down(stack, stack->top);
//
//        The top pointer is moved down to the next element, making it
//        the new official top. The rotation is complete without moving any data
//        just by changing what we consider the "top" and "bottom".
