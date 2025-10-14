/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zotaj-di <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 16:02:44 by zotaj-di          #+#    #+#             */
/*   Updated: 2025/09/30 18:49:39 by zotaj-di         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*******************************************************************************
 * This file contains the main logic for sorting stacks with more than five    *
 * elements. It uses a recursive chunk-sorting algorithm. The basic idea is to *
 * take a chunk of numbers that needs to be sorted, split it into three smaller*
 * chunks (e.g., small, medium, and large numbers), and then recursively call  *
 * the same sorting function on each of those smaller chunks.                  *
 * This process continues until the chunks are so small (3 or fewer elements)  *
 * that they can be sorted with simple, direct methods. This is a highly       *
 * efficient way to handle large, unsorted lists.                              *
 *****************************************************************************/

/* chunk_sort (void) - This is the entry point for the main sorting algorithm.
 * Its only job is to initialize the very first chunk, which contains all
 * the elements in stack A, and then start the recursive sorting process. */

//----- Context & Purpose : ---------------------------
//  The purpose of this specific chunk_sort function is to prepare the initial
//  state for the recursive engine, rec_chunk_sort.

//--------- Params of the function : --------------------------
// data (t_ps *) -> A pointer to the main push_swap structure.
//               It's passed here because it holds the stack a that we need
//               to define as our first chunk.

//--------- variables inside the function : --------------------------
// chunk_all (t_chunk) -> This is a single t_chunk structure (It's not
//                     a pointer). It will hold the location and size of
//                     the entire set of numbers that need sorting.

//--------- Setup to follow for implementation : --------------------------
//
// The implementation is a straightforward two-step process:
// Define and Delegate.
//
//    Define the Initial Chunk:
//
//        First, you declare the chunk_all variable.
//
//        Next, you must define what this chunk represents.
//        The problem starts with all the unsorted numbers sitting in stack A.
//
//            chunk_all.loc = TOP_A;
//
//                We set the location to TOP_A. This tells the recursive
//                algorithm that the numbers it needs to sort are located
//                in stack A, starting from the top.
//
//            chunk_all.size = data->stack_a.size;
//
//                We set the size of the chunk to the current size of stack A.
//                This tells the algorithm that the "problem" encompasses every
//                single element currently in the stack.
//
//    Delegate to the Recursive Engine:
//
//        Now that the initial problem is perfectly defined in chunk_all,
//        we hand it over to the function that does the real work.
//
//        rec_chunk_sort(data, &chunk_all);
//
//            We call rec_chunk_sort. We pass data along, as it's needed
//            everywhere. Crucially, we pass a pointer to our
//            chunk_all structure (&chunk_all). The recursive function will now
//            take over, read the properties of this initial chunk, and begin
//           the process of splitting it.

/* `rec_chunk_sort` (void) - The recursive heart of the sorting algorithm.
 *  It sorts a given chunk by either solving it directly if it's small enough
 *  (the base case) or by splitting it into three smaller chunks and calling
 *  itself to sort them (the recursive step). */

//----- Context & Purpose : ---------------------------
//  This function implements the "divide and conquer" logic. It's designed
//  to sort any chunk, no matter where it's located (TOP_A, BOTTOM_B, etc.).
//  The recursion provides an elegant way to handle the progressively smaller
//  sub-problems created by the chunk_split function (which is not shown here
//  but is a key part of the process).

//--------- Params of the function : --------------------------
// data (t_ps *) -> The main push_swap structure.
// to_sort (t_chunk *) -> A pointer to the chunk that this function call is
//                     responsible for sorting.

//--------- variables inside the function : --------------------------
// dest (t_split) -> A structure that will hold the three new,
//                smaller chunks after to_sort is split.
//                It will likely contain dest.min, dest.mid, and dest.max

//--------- Setup to follow for implementation : --------------------------
//
//    //Preparation (Optional but good practice):
//
//        //The code calls chunk_to_the_top and easy_sort. These are likely
//        //optimization functions. chunk_to_the_top might move a chunk from
//        //the bottom to the top to make it easier to work with. easy_sort
//        //might handle some simple pre-sorting steps.
//
//    Base Case Check (The "Stop" condition):
//
//        The most important part of any recursive function is knowing when
//        to stop. Here, the condition is if (to_sort->size <= 3).
//
//        If the chunk has 3, 2, or 1 elements, the problem is simple enough
//        to be solved directly without further splitting.
//
//        It calls sort_three, sort_two, or sort_one based on the exact size.
//
//        After the small chunk is sorted, it returns, ending this
//        branch of the recursion.
//
//    Recursive Step (The "Divide" part):
//
//        When the chunk is larger than 3, it must be broken down.
//
//        Call chunk_split(data, to_sort, &dest). It will intelligently
//        partition the to_sort chunk into three new chunks
//        (dest.max, dest.mid, dest.min) and physically move the numbers
//        between stacks A and B to achieve this separation.
//
//        Example: If to_sort was at TOP_A, chunk_split might move the smallest
//        third of numbers to BOTTOM_B, the largest third to TOP_B, and leave
//        the middle third at TOP_A.
//
//    Recursive Calls (The "Conquer" part):
//
//        Now, call rec_chunk_sort on each of the three new, smaller chunks.
//
//        rec_chunk_sort(data, &dest.max);
//
//        rec_chunk_sort(data, &dest.mid);
//
//        rec_chunk_sort(data, &dest.min);
//
//        This creates a chain reaction where each chunk is progressively broken
//        down until all are small enough to be solved by the base cases.

/* `sort_one` (void) - This is a base case for the recursion. It handles a
 *  chunk containing a single element. Its job is to move this one element to
 *  its final sorted position at the top of Stack A. */

//----- Context & Purpose : ---------------------------
//  After many splits, a chunk might be left with just one number. By the logic
//  of the algorithm, this single number is now considered "sorted" relative to
//  the other numbers that were in its original larger chunk. The purpose
//  of this function is to perform the final step: place this sorted number
//  at the top of Stack A, which is where we are building our final,
//  fully sorted list.

//--------- Params of the function : --------------------------
// data (t_ps *) -> The main push_swap structure, needed to perform moves.
// to_sort (t_chunk *) -> A pointer to the chunk we are processing.
//                        We know to_sort->size is 1.

//--------- Setup to follow for implementation : --------------------------
//
//    Check if a Move is Necessary: The number might have ended up anywhere
//    (TOP_B, BOTTOM_A, etc.). The only place it doesn't need to move from is
//    TOP_A. So, check if the chunk's location is not TOP_A.
//
//        if (to_sort->loc == BOTTOM_A || to_sort->loc == BOTTOM_B ||
//        to_sort->loc == TOP_B)
//
//    Move the Element: If the condition is true, the element is not
//    in its final home.
//
//        Call move_from_to function to handle the move.
//
//        move_from_to(data, to_sort->loc, TOP_A);
//
//        This will execute the correct sequence of operations (rra, pa, etc.)
//        to get the single element from its current location to the top of
//        Stack A.
//
//    Update the Chunk: Signal that this chunk has been dealt with.
//
//        to_sort->size -= 1;
//
//        This sets the chunk's size to 0, indicating it's now empty and fully
//        processed.

/* `sort_two` (void) - Another base case for the recursion. It handles a chunk
 *  with two elements. It moves both elements to the top of Stack A and ensures
 *  they are in the correct sorted order (smallest on top). */

//----- Context & Purpose : ---------------------------
//  This function is very similar to sort_one, but with an extra step. It's
//  the final sorting step for a pair of numbers. The goal is to get these
//  two numbers to the top of Stack A and then perform a single check-and-swap
//  to guarantee they are correctly ordered.

//--------- Params of the function : --------------------------
// data (t_ps *) -> The main push_swap structure.
// to_sort (t_chunk *) -> A pointer to the chunk we are processing,
//                      where to_sort->size is 2.

//--------- Setup to follow for implementation : --------------------------
//
//    Check if a Move is Necessary: Just like in sort_one, check if
//    the chunk is located anywhere other than TOP_A.
//
//        if (to_sort->loc == BOTTOM_A || to_sort->loc == BOTTOM_B ||
//        to_sort->loc == TOP_B)
//
//    Move Both Elements: If the chunk is not at TOP_A, you need to move both
//    of its elements.
//
//        Call move_from_to(data, to_sort->loc, TOP_A);
//
//        Call move_from_to(data, to_sort->loc, TOP_A); a second time.
//
//        This will bring both numbers to the top of Stack A.
//
//    Order the Pair: Now that the two numbers are at TOP_A, they might be
//    in the wrong order (e.g., [5, 2, ...]).
//
//        Check if the top element is greater than the second element.
//
//        if (value(&data->a, 1) > value(&data->a, 2))
//
//        If the condition is true, they are unsorted.
//        Call swap_a(data); to fix them.
//
//    Update the Chunk: Signal that this chunk is now empty and its elements
//    are sorted.
//
//        to_sort->size -= 2;

void	chunk_sort(t_ps *data)
{
	t_chunk	chunk_all;

	chunk_all.loc = TOP_A;
	chunk_all.size = (*data).stack_a.size;
	rec_chunk_sort(data, &chunk_all);
}

void	rec_chunk_sort(t_ps *data, t_chunk *to_sort)
{
	t_split	dest;

	chunk_to_the_top(data, to_sort);
	easy_sort(data, to_sort);
	if ((*to_sort).size <= 3)
	{
		if ((*to_sort).size == 3)
			sort_three(data, to_sort);
		else if ((*to_sort).size == 2)
			sort_two(data, to_sort);
		else if ((*to_sort).size == 1)
			sort_one(data, to_sort);
		return ;
	}
	chunk_split(data, to_sort, &dest);
	rec_chunk_sort(data, &dest.max);
	rec_chunk_sort(data, &dest.mid);
	rec_chunk_sort(data, &dest.min);
}

void	sort_one(t_ps *data, t_chunk *to_sort)
{
	if ((*to_sort).loc == BOTTOM_A || (*to_sort).loc == BOTTOM_B
		|| (*to_sort).loc == TOP_B)
		move_from_to(data, (*to_sort).loc, TOP_A);
	(*to_sort).size -= 1;
}

void	sort_two(t_ps *data, t_chunk *to_sort)
{
	if ((*to_sort).loc == BOTTOM_B || (*to_sort).loc == BOTTOM_A
		|| (*to_sort).loc == TOP_B)
	{
		move_from_to(data, (*to_sort).loc, TOP_A);
		move_from_to(data, (*to_sort).loc, TOP_A);
	}
	if (ft_value(&(*data).stack_a, 1) > ft_value(&(*data).stack_a, 2))
		swap_a(data);
	(*to_sort).size -= 2;
}
