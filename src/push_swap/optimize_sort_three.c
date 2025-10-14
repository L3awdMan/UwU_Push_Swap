/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimize_sort_three.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zotaj-di <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 16:39:11 by zotaj-di          #+#    #+#             */
/*   Updated: 2025/09/11 19:54:57 by zotaj-di         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*******************************************************************************
 * This file contains set of functions designed to solve one of the base cases *
 * of my recursive algorithm: sorting a chunk of exactly three elements. Unlike*
 * the simple sort_three_a from the beginning, these functions are optimized to*
 * work on a chunk located anywhere across the two stacks                      *
 * (TOP_A, BOTTOM_B, etc.).                                                    *
 * The core strategy is to reduce the problem. Instead of trying to sort all   *
 * three numbers at once, the logic focuses on identifying the single largest  *
 * number in the chunk and dealing with it first. Once the largest number is   *
 * handled, the problem is reduced to the even simpler sort_two case,          *
 * which we've already solved. This file is the final, optimized step before   *
 * the recursion stops.                                                        *
 *****************************************************************************/

/* `sort_three`(void) This is the main dispatcher for sorting a 3 element chunk
 *  It determines the chunk's location and calls the specialized helper function
 *  designed for that exact scenario. */

//----- Context & Purpose : ---------------------------
//  When rec_chunk_sort encounters a chunk of size 3, it calls this function.
//  This function acts as a switchboard. It doesn't perform any sorting logic
//  itself. Its only job is to look at the chunk's location (to_sort->loc)
//  and delegate the task to the correct, highly-optimized helper function
//  (sort_three_top_a, sort_three_bottom_b, etc.).

//--------- Params of the function : --------------------------
// data (t_ps *) -> The main push_swap structure.
// to_sort (t_chunk *) -> A pointer to the chunk of size 3 that needs to be
//                        sorted.

//--------- variables inside the function : --------------------------
// stack (t_stack *) -> A pointer to the stack (A or B) where the chunk
//                 currently resides. This is obtained by calling loc_to_stack.
// max (int) -> The largest indexed value among the three numbers in the chunk.
//              This is found by calling chunk_max_value.

//--------- Setup to follow for implementation : --------------------------
//
//    Preparation:
//
//        First, determine which stack the chunk is on by calling
//        stack = loc_to_stack(data, to_sort->loc);.
//
//        Second, find the largest of the three numbers by calling
//        max = chunk_max_value(data, to_sort);.
//        This max value is the key to all the sorting logic that follows.
//
//    Dispatching Logic:
//
//        Use an if-else if chain to check the value of to_sort->loc.
//
//        If to_sort->loc == TOP_A, call
//        sort_three_top_a(data, to_sort, stk, max);.
//
//        If to_sort->loc == BOTTOM_A,
//        call sort_three_bottom_a(...).
//
//        If to_sort->loc == TOP_B,
//        call sort_three_top_b(...).
//
//        If to_sort->loc == BOTTOM_B,
//        call sort_three_bottom_b(...).

/* `sort_three_top_a` (void) - Sorts a 3-element chunk located at the top of
 *  Stack A. The strategy is to sort the two smaller numbers while using
 *  the third spot on the stack as temporary storage for the largest number. */

//----- Context & Purpose : ---------------------------
//  This is one of the most common base cases. The function needs to sort three
//  numbers at the top of Stack A using the minimum number of moves.
//  The clever insight here is that we don't need Stack B. We can sort the two
//  smaller numbers by moving the largest one out of the way temporarily.

//--------- Params of the function : --------------------------
// data, to_sort, stack, max -> The values passed down from the main
//                             sort_three function.

//--------- Setup to follow for implementation : --------------------------
//
// The logic is based on the position of the max value within 3-element chunk.
//
//    Check if the max value is at the top (position 1):
//
//        Condition: if (stack->array[stack->top] == max)
//
//        Action: The largest number is at the top. We need to sort the other
//        two without it interfering. A known efficient sequence is:
//        sa, ra, sa, rra. This sorts the two smaller numbers while using
//        the bottom of the stack to hold the max value temporarily.
//
//    Check if the max value is in the middle (position 2):
//
//        Condition:
//         else if (stack->array[next_down(stack, stack->top)] == max)
//
//        Action: The largest number is in the second position.
//        The sequence ra, sa, rra will bring the other two numbers to the top,
//        swap them if needed, and return the max value to its correct position.
//
//    Handle the final case (max is at position 3):
//
//        Condition:
//               else (If the max is not at position 1 or 2, it must be at 3).
//
//        Action:
//          No initial moves are needed for the max value. We proceed directly
//          to the next step.
//
//    Reduce the Problem:
//
//        No matter which of the above cases was true, the largest of the three
//        numbers is now sorted relative to the other two. The problem is now
//        to sort the remaining two.
//
//        Update the chunk to reflect this:
//        to_sort->loc = TOP_A; and to_sort->size -= 1;.
//
//        Call sort_two(data, to_sort); to finish the job.

/* `sort_three_top_b` (void) - Sorts a 3-element chunk at the top of Stack B by
 *  moving them all to Stack A in the correct final order. */

//----- Context & Purpose : ---------------------------
//   This function's goal is to take the three numbers from the top of B and
//   place them correctly at the top of A. It uses the max value to decide
//   the most efficient order of pa and sb operations.

//--------- Setup to follow for implementation : --------------------------
//
// This implementation is a bit more complex as it involves moving all
// three elements.
//
//    Move one element to A: Start by unconditionally moving the top element of
//    B to A. push_a(data);. This clears space and gives us a reference point.
//
//    Check where the max value is now in Stack B:
//
//        Condition:
//        if (stack->array[stack->top] == max)
//        (Is the new top of B the max value?)
//
//        Action: If yes, push the next element, then swap them in A.
//        pa; sa;.
//
//        Condition:
//        else if (stack->array[next_down(stack, stack->top)] == max)
//        (Is the second element in B the max value?)
//
//        Action: If yes, swap B first to bring the max to the top,
//        then push, then swap in A.
//        sb; pa; sa;
//
//        Condition: else (The max must have been the first element we pushed)
//
//        Action: Just push the next element. pa;
//
//    Move the last element: No matter what, there is one element left in the B
//    chunk. Push it to A. push_to_a(data);
//
//    Reduce the Problem: The largest number is now sorted at the top of A.
//
//        Update the chunk: to_sort->loc = TOP_A; and to_sort->size -= 1;.
//
//        Call sort_two(data, to_sort); to sort the other two numbers that
//        are now also at the top of A.
//
// ----------------> Little Examples for Better Understanding <----------------
//
// Let's visualize sort_three_top_a. The goal is to sort a 3-element chunk at
// the top of Stack A. The numbers are [8, 6, 7].
//
//    Initial State: Stack A: [8, 6, 7, ...]. The chunk is (8, 6, 7).
//
//    Preparation: sort_three is called. It finds max = 8. It sees the location
//    is TOP_A and calls sort_three_top_a.
//
// Case 1: max is at the top.
//
//    The condition stk->stack[stk->top] == max (is 8 == 8?) is TRUE.
//
//    The function executes the prescribed sequence of moves:
//
//        sa -> A: [6, 8, 7, ...]
//
//        ra -> A: [8, 7, ..., 6]
//
//        sa -> A: [7, 8, ..., 6]
//
//        rra -> A: [6, 7, 8, ...]
//
//    The three numbers are now sorted!
//
//    The function then calls sort_two on the chunk (6, 7) which will do
//    nothing as they are already sorted.
//
// Case 2: max is in the middle.
//
//    Let's say the initial chunk was [6, 8, 7]. max is still 8.
//
//    The condition stk->stack[next_down(stk, stk->top)] == max
//    (is the 2nd element 8?) is TRUE.
//
//    The function executes its sequence:
//
//        ra -> A: [8, 7, ..., 6]
//
//        sa -> A: [7, 8, ..., 6]
//
//        rra -> A: [6, 7, 8, ...]
//
//    Again, the numbers are perfectly sorted.
//
// This "reduce the problem" approach is extremely powerful and efficient.

/* `sort_three_bottom_a` (void) - Sorts a 3-element chunk located at the bottom
 *  of Stack A. The primary challenge is to bring these elements to the top of
 *  the stack efficiently before sorting them. */

//----- Context & Purpose : ---------------------------
//  This function is called when the recursive split results in a small chunk
//  of three being left at the bottom of Stack A. The ultimate goal is to get
//  these three numbers sorted and positioned at the top of Stack A.
//  This function's logic is designed to use the minimum number of
//  reverse rotations (rra) to access the elements and then apply a specific
//  sorting pattern based on where the largest (max) number is located.

//--------- Params of the function : --------------------------
// data, to_sort, stk, max -> The values passed down from the main sort_three

//--------- Setup to follow for implementation : --------------------------
//
// The implementation is a two-phase process: Access the elements, then
// Sort them.
//
//    Access Phase: Bring the Chunk to the Top
//
//        I cannot work on the bottom of the stack. You must bring the three
//        elements to the top.
//
//        Execute rra;
//
//        Execute rra; a second time.
//
//        Result: After two rra's, two of the three numbers from the chunk
//        are now at the top of Stack A. The third number from the chunk is now
//        at the very bottom of the stack.
//
//    Sort Phase: Identify max and Execute Pattern
//
//        Now that the elements are accessible, check the position of the max
//        value.
//
//        Case 1: max is the new top element.
//
//            Condition: if (stack->array[stack->top] == max)
//
//            Action: The stack looks like [max, n2, n1, ...]. We need to sort
//            n1 and n2. The sequence sa;
//            followed by rra; achieves this. sa sorts the top two
//            and rra puts the max back in its correct final position below
//            the other two.
//
//        Case 2: max is the second element.
//
//            Condition:
//            else if (stack->array[next_down(stack, stack->top)] == max)
//
//            Action: The stack looks like [n2, max, n1, ...].
//            We just need to move n1 to the top and max will be in the correct
//            spot. A single rra; accomplishes this.
//
//        Case 3: max is the third element (now at the bottom).
//
//            Condition: else
//
//            Action: This is the most complex case. The two smaller numbers
//            are now at the top of Stack A. We can sort them using Stack B
//            as temporary help.
//
//                push_to_b(data); (Move the top number to B).
//
//                r_rotate_a(dta);
//                (Bring the third number from the bottom back to the top).
//
//                swap_a(data); (Sort the two numbers now at the top of A).
//
//                push_to_a(data); (Return the number from B).
//
//    Reduce the Problem:
//
//        Regardless of the case, the max value is now handled.
//        The remaining task is to sort the other two.
//
//        Update the chunk: to_sort->loc = TOP_A; and to_sort->size -= 1;.
//
//        Call sort_two(data, to_sort); to finish the job.

/* `sort_three_bottom_b` (void) - Sorts a 3-element chunk at the bottom of
 *  Stack B. The strategy is to bring the elements to the top of B and then
 *  efficiently push them to A in the correct order. */

//----- Context & Purpose : ---------------------------
//  This function handles the case where a chunk of three ends up at the bottom
//  of the temporary stack, B. The goal is to get these three numbers sorted at
//  the top of Stack A. This function combines reverse rotations on B (rrb)
//  with pushes to A (pa) to achieve the sort.

//--------- Params of the function : --------------------------
// data, to_sort, stk, max -> The values passed down from the main sort_three()

//--------- Setup to follow for implementation : --------------------------
//
// Similar to the previous function, this is a two-phase process.
//
//    Access Phase: Bring the Chunk to the Top of Stack B
//
//        Execute rrb;
//
//        Execute rrb; a second time.
//
//        Result: Two of the three numbers are now at the top of Stack B,
//        ready to be pushed to A.
//
//    Sort & Move Phase: Identify max and Push to A
//
//        The logic now focuses on pushing the numbers to A in a way that
//        minimizes sorting moves on Stack A.
//
//        Case 1: max is the new top element of B.
//
//            Condition: if (stack->array[stack->top] == max)
//
//            Action: The largest number is ready to be moved.
//
//                pa; (Move max to Stack A).
//
//                rrb; (Bring the third number from the bottom of B to the top)
//
//        Case 2: max is the second element of B.
//
//            Condition:
//            else if (stack->array[next_down(stack, stack->top)] == max)
//
//            Action: We want to move max last.
//
//                sb; (Bring the smaller number to the top of B).
//
//                pa; (Push the smaller number to A).
//
//                rrb; (Bring the third number to the top of B).
//
//        Case 3: max is the third element (at the bottom of B).
//
//            Condition: else
//
//            Action: The two smaller numbers are already at the top of B.
//
//                rrb; (Bring the third number to the top,
//                pushing the other two down).
//
//                pa; (Push this third number to A).
//
//    Reduce the Problem:
//
//        After the sequence, one number has been correctly placed in A,
//        and the other two are now at the top of B. The problem has been
//        reduced to sorting a chunk of two at the top of B.
//
//        Update the chunk: to_sort->loc = TOP_B; (The remaining two are now a
//        chunk at the top of B) and to_sort->size -= 1;
//
//        Call sort_two(data, to_sort); which will move the final two numbers
//        from TOP_B to TOP_A and sort them.

void	sort_three(t_ps *data, t_chunk *to_sort)
{
	t_stack	*stack;
	int		max;

	stack = location_to_stack(data, (*to_sort).loc);
	max = chunk_max_value(data, to_sort);
	if ((*to_sort).loc == TOP_A)
		sort_three_top_a(data, to_sort, stack, max);
	else if ((*to_sort).loc == BOTTOM_A)
		sort_three_bottom_a(data, to_sort, stack, max);
	else if ((*to_sort).loc == TOP_B)
		sort_three_top_b(data, to_sort, stack, max);
	else if ((*to_sort).loc == BOTTOM_B)
		sort_three_bottom_b(data, to_sort, stack, max);
}

void	sort_three_top_a(t_ps *data, t_chunk *to_sort, t_stack *stack, int max)
{
	if ((*stack).array[(*stack).top] == max)
	{
		swap_a(data);
		rotate_a(data);
		swap_a(data);
		reverse_rotate_a(data);
	}
	else if ((*stack).array[ft_next_down(stack, (*stack).top)] == max)
	{
		rotate_a(data);
		swap_a(data);
		reverse_rotate_a(data);
	}
	(*to_sort).loc = TOP_A;
	(*to_sort).size -= 1;
	sort_two(data, to_sort);
}

void	sort_three_top_b(t_ps *data, t_chunk *to_sort, t_stack *stack, int max)
{
	push_to_a(data);
	if ((*stack).array[(*stack).top] == max)
	{
		push_to_a(data);
		swap_a(data);
	}
	else if ((*stack).array[ft_next_down(stack, (*stack).top)] == max)
	{
		swap_b(data);
		push_to_a(data);
		swap_a(data);
	}
	else
		push_to_a(data);
	push_to_a(data);
	(*to_sort).loc = TOP_A;
	(*to_sort).size -= 1;
	sort_two(data, to_sort);
}

void	sort_three_bottom_a(t_ps *data, t_chunk *to_sort, t_stack *stack,
		int max)
{
	reverse_rotate_a(data);
	reverse_rotate_a(data);
	if ((*stack).array[(*stack).top] == max)
	{
		swap_a(data);
		reverse_rotate_a(data);
	}
	else if ((*stack).array[ft_next_down(stack, (*stack).top)] == max)
		reverse_rotate_a(data);
	else
	{
		push_to_b(data);
		reverse_rotate_a(data);
		swap_a(data);
		push_to_a(data);
	}
	(*to_sort).loc = TOP_A;
	(*to_sort).size -= 1;
	sort_two(data, to_sort);
}

void	sort_three_bottom_b(t_ps *data, t_chunk *to_sort, t_stack *stack,
		int max)
{
	reverse_rotate_b(data);
	reverse_rotate_b(data);
	if ((*stack).array[(*stack).top] == max)
	{
		push_to_a(data);
		reverse_rotate_b(data);
	}
	else if ((*stack).array[ft_next_down(stack, (*stack).top)] == max)
	{
		swap_b(data);
		push_to_a(data);
		reverse_rotate_b(data);
	}
	else
	{
		reverse_rotate_b(data);
		push_to_a(data);
	}
	(*to_sort).loc = TOP_B;
	(*to_sort).size -= 1;
	sort_two(data, to_sort);
}
