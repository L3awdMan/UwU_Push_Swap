/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zotaj-di <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 23:45:26 by zotaj-di          #+#    #+#             */
/*   Updated: 2025/09/30 18:49:41 by zotaj-di         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/****************************************************************************
 * This file introduces a powerful new concept for our sorting algorithm:   *
 * the "chunk." A chunk is a virtual, movable segment of a stack.           *
 * Instead of thinking about the entire stack A or B, we can now focus      *
 * on a specific group of elements at the top or bottom.                    *
 *                                                                          *
 * The purpose of this file is to provide tools to inspect these chunks.    *
 * These functions will allow our main chunk_sort algorithm to ask important*
 * questions like, What is the 3rd value in the chunk at the top of Stack A?*
 * or What is the largest number in the chunk at the bottom of Stack B?.    *
 * These utilities are the eyes and ears of the sorting algorithm.          *
 ****************************************************************************/

/* `loc_to_stack` (t_stack *) - A simple but crucial helper function that takes
 *  a location enum (t_location) and returns a pointer to the corresponding
 *  stack (either stack A or stack B). */

//--------- Context & Purpose : --------------------------
//   In our move.c file, we defined locations like TOP_A, BOTTOM_A, TOP_B,
//   and BOTTOM_B. Many of our new chunk functions will need to know whether
//   they should operate on stack A or stack B. This function prevents us from
//   writing the same if/else logic over and over again.

//--------- Params of the function : --------------------------
// data (t_ps *) -> The main push_swap structure, which contains both stacks.
// loc (t_location) -> The location enum (TOP_A, BOTTOM_A, etc.).

//--------- Setup to follow for implementation : --------------------------
//
//    Check if the loc is either TOP_A or BOTTOM_A.
//
//    If it is, return a pointer to data->stack_a.
//
//    Otherwise (meaning it must be TOP_B or BOTTOM_B)
//      return a pointer to data->b.

/* ft_chunk_value (int) - Gets the value of the Nth element within a specific
 * chunk, reading from either the top-down or the bottom-up. */

//--------- Context & Purpose : --------------------------
//   This is an advanced version of the ft_value function from my `stack_utils`
//   While `ft_value` always reads from the top of a stack, chunk_value is more
//   flexible. It reads from a chunk, which can be located at the top or
//   the bottom of a stack.

//--------- Params of the function : --------------------------------
// data (t_ps *) -> The main push_swap structure.
// chunk (t_chunk *) -> A pointer to a chunk structure. This tells
//                      the function where the chunk is (chunk->loc)
//                      and how big it is (chunk->size)
// n (int) -> The position of the element you want to read
//           (e.g., n=1 is the first element, n=2 is the second).

//--------- variables inside the function : --------------------------
// loc (t_location) -> A copy of the chunk's location for easier access.
// stack (t_stack *) -> A pointer to the correct stack (A or B)
//                      determined by calling loc_to_stack.
// i (int) -> The index that will travel through the circular array
//            to find the Nth element.

//--------- Setup to follow for implementation : --------------------------
//
// Get the correct stack: First, call loc_to_stack(data, chunk->loc)
// to get a pointer to either stack A or B.
//
//    Find the starting point:
//
//        If the chunk's location is TOP_A OR TOP_B, the starting index i
//        is the stack's top (i = stack->top).
//
//        If the chunk's location is BOTTOM_A or BOTTOM_B, the starting index i
//        is the stack's bottom (i = stack->bottom).
//
//    Iterate to the Nth element:
//
//        If starting from TOP_A OR TOP_B, we need to move down the stack.
//        Loop n-1 times, updating the index with i = ft_next_down(stack, i).
//
//        If starting from BOTTOM_A OR BOTTOM_B, we need to move up the stack.
//        Loop n-1 times, updating the index with i = ft_next_up(stack, i).
//
//    Return the value: Once the loop is finished, i will be at the correct
//    position. Return the value from the array: stack->array[i].

/* `chunk_max_value` (int) Finds and returns the largest (maximum) value within
 *  a given chunk.  */

//--------- Context & Purpose : ---------------------------------------
//  This is a critical function for the second phase of chunk_sort.
//  After pushing a range of numbers from A to B, stack B will be unsorted.
//  To sort it efficiently, we need to push the numbers back to A in descending
//  order (largest first). This function will allow the algorithm to identify
//  the largest number currently in B so it can be moved to the top
//  and pushed back to A.

//--------- Params of the function : --------------------------
// data (t_ps *) -> The main push_swap structure.
// chunk (t_chunk *) -> A pointer to the chunk we want to analyze.

//--------- variables inside the function : --------------------------
// stack (t_stack *) -> Pointer to the correct stack (A or B).
// size (int) -> A copy of the chunk's size to use as a loop counter.
// max_value (int) -> A variable to keep track of the largest value found so far
// i (int) -> The index used to iterate through the chunk's elements.

//--------- Setup to follow for implementation : --------------------------
//
// Initialization :
//
//    Get the correct stack using loc_to_stack.
//
//    Get the size based on chunk->size
//
//    Initialize max_value = 0. (This assumes you are working with positive
//    indexed numbers. If you could have negative numbers, you should
//    initialize it to the first value of the chunk instead).
//
//    Get the starting index i based on chunk->loc
//    (either stack->top or stack->bottom), just like in chunk_value.
//
// Iterate through the chunk:
//
//    Start a loop that runs chunk->size times.
//
//    Inside the loop:
//
//    Compare the value at the current index i (stack->array[i]) with
//    max_value. If it's greater, update max_value.
//
//    Move to the next element in the chunk by updating i with either
//    ft_next_down(stack, i) or ft_next_up(stk, i), depending on
//    the chunk's location.
//
//    Return the result: After the loop has checked every element in the chunk,
//
//    return the final max_value.

// POINT :
//     i need to get another function plan specially for chunk_max_value

t_stack	*location_to_stack(t_ps *data, t_location loc)
{
	if (loc == TOP_A || loc == BOTTOM_A)
		return (&(*data).stack_a);
	else
		return (&(*data).stack_b);
}

int	ft_chunk_value(t_ps *data, t_chunk *chunk, int n)
{
	t_location	loc;
	t_stack		*stack;
	int			i;

	loc = (*chunk).loc;
	stack = location_to_stack(data, loc);
	if (loc == TOP_A || loc == TOP_B)
		i = (*stack).top;
	else if (loc == BOTTOM_A || loc == BOTTOM_B)
		i = (*stack).bottom;
	if (loc == TOP_A || loc == TOP_B)
	{
		while (--n > 0)
			i = ft_next_down(stack, i);
	}
	else if (loc == BOTTOM_A || loc == BOTTOM_B)
	{
		while (--n > 0)
			i = ft_next_up(stack, i);
	}
	return ((*stack).array[i]);
}

int	chunk_max_value(t_ps *data, t_chunk *chunk)
{
	t_stack	*stack;
	int		size;
	int		max_value;
	int		i;

	stack = location_to_stack(data, (*chunk).loc);
	max_value = 0;
	size = (*chunk).size;
	if ((*chunk).loc == TOP_A || (*chunk).loc == TOP_B)
		i = (*stack).top;
	else if ((*chunk).loc == BOTTOM_A || (*chunk).loc == BOTTOM_B)
		i = (*stack).bottom;
	while (size--)
	{
		if ((*stack).array[i] > max_value)
			max_value = (*stack).array[i];
		if ((*chunk).loc == TOP_A || (*chunk).loc == TOP_B)
			i = ft_next_down(stack, i);
		else if ((*chunk).loc == BOTTOM_A || (*chunk).loc == BOTTOM_B)
			i = ft_next_up(stack, i);
	}
	return (max_value);
}
