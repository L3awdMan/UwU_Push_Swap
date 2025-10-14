/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_split.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zotaj-di <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 15:59:56 by zotaj-di          #+#    #+#             */
/*   Updated: 2025/09/30 18:49:40 by zotaj-di         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*******************************************************************************
 * This file is the implementation of the "divide" step in your                *
 * "divide and conquer" algorithm. Its sole responsibility is to take one      *
 * large, unsorted chunk and intelligently partition it into three smaller,    *
 * more manageable chunks: one for the smallest numbers (min), one for         *
 * the middle numbers (mid), and one for the largest numbers (max).            *
 * To do this, it calculates pivot points to define the boundaries of these    *
 * groups and then physically moves the numbers to different locations across  *
 * both stacks to separate them. This strategic separation is what makes       *
 * the recursive sorting possible.                                             *
 * ***************************************************************************/

/* `innit_size` (void) - A simple initialization helper function that sets
 *  the starting size of the three new destination chunks to zero before
 *  the splitting process begins. */

//----- Context & Purpose : ---------------------------
//  Before we start sorting numbers from the to_split chunk into our new
//  min, mid, and max chunks, we need to make sure their counters are clean.
//  This function is a "reset" button. It ensures that we are starting
//  our count from a clean slate of 0 for each new chunk, preventing any
//  garbage values from a previous operation from causing errors.

//--------- Params of the function : --------------------------
// min (t_chunk *) -> A pointer to the chunk that will hold the small numbers.
// mid (t_chunk *) -> A pointer to the chunk that will hold the middle numbers.
// max (t_chunk *) -> A pointer to the chunk that will hold the largest numbers.

//--------- Setup to follow for implementation : --------------------------
//
//  Access the size member of the min chunk through its pointer and set it
//  to 0 (min->size = 0;).
//
//  Do the same for the mid chunk (mid->size = 0;).
//
//  Do the same for the max chunk (max->size = 0;).

/* `set_split_loc` (void) - This function determines the destination locations
 *  for the three new chunks based on the location of the original chunk
 *  being split. */

// ----- Context & Purpose : ---------------------------
//  This function contains the strategic "rules" of the algorithm.
//  When i split a chunk, i can't just leave the new chunks anywhere.
//  i need a plan. This function decides, for example, "If I'm splitting a chunk
//  at the Top of A, I will send the small numbers to the Bottom of B,
//  the medium numbers to the Top of B, and keep the large numbers at the Bottom
//  of A." This strategic placement is designed to be efficient for the next
//  recursive steps.

//--------- Params of the function : --------------------------
// loc (t_location) -> The location of the original chunk that is being split
//                (to_split->loc).
// min, mid, max (t_chunk *) -> Pointers to the three new chunks whose loc
//                property needs to be set.

//--------- Setup to follow for implementation : --------------------------
//
// The function is a series of if-else if statements that check the original
// location and assign destinations accordingly.
//
//    Case 1: Splitting from TOP_A
//
//        min->loc = BOTTOM_B;
//        (Smallest numbers go far away to the bottom of the other stack).
//
//        mid->loc = TOP_B; (Medium numbers go to the top of the other stack,
//        ready to be split next).
//
//        max->loc = BOTTOM_A; (Largest numbers stay on the current stack,
//        but are moved to the bottom to get them out of the way).
//
//    Case 2: Splitting from BOTTOM_A
//
//        The logic is very similar to TOP_A, showing a consistent strategy
//        for splitting chunks on stack A beside max->loc is in TOP_A
//
//    Case 3 & 4: Splitting from TOP_B or BOTTOM_B
//
//        The destinations change. For example, when splitting from TOP_B,
//        the largest numbers (max) are sent to TOP_A. This is because
//        the ultimate goal is to get everything sorted back into stack A.

/* `set_third_pivots` (void) - This function calculates two integer thresholds
 *  (*pivot_1 and *pivot_2) that define the boundaries for slicing a chunk into
 *  three groups: small, medium, and large. It starts with a default three-way
 *  split and then applies special, optimized rules for certain small
 *  or strategically located chunks.*/

//----- Context & Purpose : ---------------------------
//  This is the mathematical core of the split. To separate numbers into
//  "small," "medium," and "large," we need to define what those words mean.
//  This function calculates the thresholds. It doesn't pick actual numbers
//  from the stack as pivots (like in classic Quicksort). Instead, it uses
//  the indexed values and the size of the chunk to calculate boundary points.
//  For example, in a chunk of 30 numbers, it might define "small" as
//  the 10 smallest-indexed numbers, "medium" as the next 10,
//  and "large" as the 10 largest-indexed numbers. The function also contains
//  special logic to adjust these pivot points for smaller chunks to optimize
//  the sorting.

//--------- Params of the function : --------------------------
// loc (t_loc) -> The location of the chunk being split. The pivot strategy
//                   changes slightly depending on where the chunk is.
// current_size (int) -> The current size of the chunk being split.
// pivot_1, pivot_2 (int *) -> Pointers to two integer variables that will
//                   store the calculated pivot thresholds.

//--------- Setup to follow for implementation : --------------------------
//
// Step 1: Calculate the Default Three-Way Split
//
//  First, assume you are splitting the chunk into three perfectly equal thirds.
//  This is your baseline.
//
//    Calculate pivot_2: This value represents the size of the "large"
//                       number group.
//
//        *pivot_2 = crt_size / 3;
//
//    Calculate pivot_1 for Stack A: This value represents the combined size
//                   of the "medium" and "large" groups. The default strategy
//                   is different for Stack A and B.
//
//        if (loc == TOP_A || loc == BOTTOM_A)
//
//        *pivot_1 = 2 * crt_size / 3;
//
// Step 2: Apply Overrides for Chunks on Stack B
//
//  Now, check if the chunk you are splitting is on Stack B. If it is,
//  i will use a different strategy for pivot_1, overwriting the default.
//  ( This is an optimization. )
//
//    Adjust pivot_1 for Stack B:
//
//        if (loc == TOP_B || loc == BOTTOM_B)
//
//        *pivot_1 = crt_size / 2;
//
//        (This changes the split from 1/3, 1/3, 1/3 to a 1/3, 1/6, 1/2 ratio,
//        which is more efficient for moving numbers back to A later).
//
// Step 3: Apply Overrides for Small Chunks
//
//  Finally, check for special cases involving small chunks. These rules
//  are designed to be more efficient than a three-way split when the number
//  of elements is low. These rules will override any previously set values.
//
//    Optimization for Small Chunks on Stack A: If the chunk is on Stack A
//    and is small, switch to a simple two-way split (small vs. large).
//
//        if ((loc == TOP_A || loc == BOTTOM_A) && crt_size < 15)
//
//        *pivot_1 = crt_size;
//
//        (This makes the "medium" category disappear because the condition to
//        enter it becomes impossible to meet).
//
//    Optimization for Very Small Chunks at the Bottom of Stack B: This is
//    a very specific case. If the chunk is at the bottom of B and is tiny,
//    switch to a 50/50 two-way split.
//
//        if (loc == BOTTOM_B && crt_size < 8)
//
//        *pivot_2 = crt_size / 2;
//
//        (This adjusts the boundary between the "small" and "large" groups).

/* `chunk_split` (void) - The main function. It uses the helper functions to
 *  prepare, then iterates through the chunk-to-be-split, moving each element
 *  to its correct new chunk based on the calculated pivot values */

//----- Context & Purpose : ---------------------------
// This is the function that is called by rec_chunk_sort. It brings everything
// together. It prepares the destination chunks, calculates the necessary pivots
// and then executes the main loop that physically separates the numbers. This
// is the function that does the actual work of the "divide" step.

//--------- Params of the function : --------------------------
// data (t_ps *) -> The main push_swap structure.
// to_split (t_chunk *) -> A pointer to the chunk that needs to be divided.
// dest (t_split *) -> A pointer to the structure that will hold
//                  the three new chunks (min, mid, max).

//--------- variables inside the function : --------------------------
// pivot_1, pivot_2 (int) -> The pivot values calculated by set_third_pivots.
// max_value (int) -> The largest indexed value within the to_split chunk, found
//            using chunk_max_value. This is the reference point for the pivots.
// next_value (int) -> Holds the value of the element currently being processed
//            in the loop.

//--------- Setup to follow for implementation : --------------------------
// The implementation can be broken into two phases: Preparation and Execution.
//
// Phase 1: Preparation (Setting up the Sorting Machine)
//
//  Before i can process any numbers, i need to set up
//  the rules and destinations.
//
//    Reset the Counters: Call init_size(&dest->min, &dest->mid, &dest->max);
//
//        What it does: Sets the size of my three new "outbox" chunks to 0.
//        i must start counting from a clean slate.
//
//    Assign Destinations: Call
//    set_split_loc(to_split->loc, &dest->min, &dest->mid, &dest->max);
//
//        What it does: Decides where each of the three new chunks will live.
//        For example, if was splitting from TOP_A, this function sets
//        dest->min.loc to BOTTOM_B, dest->mid.loc to TOP_B, etc.
//
//    Calculate the "Slicing Rules": Call
//    set_third_pivots(to_split->loc, to_split->size, &pivot_1, &pivot_2);
//
//        What it does: Calculates the two integer thresholds i'll use
//        to categorize the numbers.
//
//    Find the Anchor Point: Call max_value = chunk_max_value(data, to_split);
//
//        What it does: Finds the largest number (highest rank) in the chunk
//        i'm about to split. The pivots are meaningless without this
//        reference point.
//
// Phase 2: Execution (Running the Sorting Machine)
//
//  Now that everything is set up, i will process every number from
//  the "inbox" (to_split) chunk.
//
//    Start the Loop: Create a while loop that runs exactly
//    to_split->size times. A clean way to do this is while (to_split->size--).
//    This uses the chunk's size as a counter and decrements it with each
//    iteration.
//
//    Get the Next Number: Inside the loop, the first step is to read
//    the number at the "front" of the chunk i'm about splitting.
//
//        next_value = chunk_value(data, to_split, 1);
//
//        This gets the value of the very first element of the to_split chunk,
//        whether it's at the top or bottom of the stack.
//
//    Sort the Number into a Bin (The if/else if/else block): This is the core
//    decision-making logic.
//
//        Check if it belongs in the "LARGE" bin:
//
//         if (next_value > max_value - pivot_2)
//
//         Action: This number is one of the largest. Move it to
//         the destination assigned to the max chunk.
//
//          dest->max.size += move_from_to(data, to_split->loc, dest->max.loc);
//
//          This line is brilliant: move_from_to executes the move
//          (like ra or pb) and returns 1. You add this 1 to the size counter
//          of your max chunk.
//
//            // Special Optimizations: The lines split_max_reduction
//            // and easy_sort inside this if block are extra optimizations
//            // you've added. They likely perform small sorting adjustments
//            // on-the-fly to make the next steps even more efficient.
//
//        Check if it belongs in the "MEDIUM" bin:
//
//            else if (next_value > max_value - pivot_1)
//
//            Action: The number is not in the largest group, but it's not in
//            the smallest either. Move it to the destination assigned to
//            the mid chunk.
//
//           dest->mid.size += move_from_to(data, to_split->loc, dest->mid.loc);
//
//        If it's in the "SMALL" bin:
//
//            else
//
//            Action: If a number is neither large nor medium, it must be small
//            Move it to the destination assigned to the min chunk.
//
//           dest->min.size += move_from_to(data, to_split->loc, dest->min.loc);
//
// Example to walkthrough (revisited):
//
//    Chunk: 9 numbers at TOP_A. max_value=9, pivot_2=3, pivot_1=6.
//
//    Loop starts. The first number at TOP_A is 4.
//
//    chunk_value gets 4.
//
//    if (4 > 9 - 3) -> if (4 > 6) -> FALSE.
//
//    else if (4 > 9 - 6) -> else if (4 > 3) -> TRUE.
//
//    Action: The number 4 belongs to the mid group. The code calls
//    move_from_to(data, TOP_A, dest->mid.loc), which was set to TOP_B.
//    This executes a pb. The size of dest->mid is incremented to 1.
//
//    The loop continues for the next 8 numbers.
//
//  After the loop finishes, the original chunk to_split is empty,
//  and all its numbers have been partitioned into the three new chunks,
//  ready for the next level of recursion.

void	chunk_split(t_ps *data, t_chunk *to_split, t_split *dest)
{
	int	max_value;
	int	next_value;
	int	pivot_1;
	int	pivot_2;

	init_size(&(*dest).min, &(*dest).mid, &(*dest).max);
	set_split_loc((*to_split).loc, &(*dest).min, &(*dest).mid, &(*dest).max);
	set_third_pivots((*to_split).loc, (*to_split).size, &pivot_1, &pivot_2);
	max_value = chunk_max_value(data, to_split);
	while ((*to_split).size--)
	{
		next_value = ft_chunk_value(data, to_split, 1);
		if (next_value > max_value - pivot_2)
		{
			dest->max.size += move_from_to(data, to_split->loc, dest->max.loc);
			split_max_reduction(data, &(*dest).max);
			if (a_partly_sort(data, 1) && (*to_split).size)
				easy_sort(data, to_split);
		}
		else if (next_value > max_value - pivot_1)
			dest->mid.size += move_from_to(data, to_split->loc, dest->mid.loc);
		else
			dest->min.size += move_from_to(data, to_split->loc, dest->min.loc);
	}
}

void	init_size(t_chunk *min, t_chunk *mid, t_chunk *max)
{
	(*min).size = 0;
	(*mid).size = 0;
	(*max).size = 0;
}

void	set_split_loc(t_location loc, t_chunk *min, t_chunk *mid, t_chunk *max)
{
	if (loc == TOP_A)
	{
		(*min).loc = BOTTOM_B;
		(*mid).loc = TOP_B;
		(*max).loc = BOTTOM_A;
	}
	else if (loc == BOTTOM_A)
	{
		(*min).loc = BOTTOM_B;
		(*mid).loc = TOP_B;
		(*max).loc = TOP_A;
	}
	else if (loc == TOP_B)
	{
		(*min).loc = BOTTOM_B;
		(*mid).loc = BOTTOM_A;
		(*max).loc = TOP_A;
	}
	else if (loc == BOTTOM_B)
	{
		(*min).loc = TOP_B;
		(*mid).loc = BOTTOM_A;
		(*max).loc = TOP_A;
	}
}

void	set_third_pivots(t_location loc, int current_size, int *pivot_1,
		int *pivot_2)
{
	*pivot_2 = current_size / 3;
	if (loc == TOP_A || loc == BOTTOM_A)
		*pivot_1 = 2 * current_size / 3;
	if (loc == TOP_B || loc == BOTTOM_B)
		*pivot_1 = current_size / 2;
	if ((loc == TOP_A || loc == BOTTOM_A) && current_size < 15)
		*pivot_1 = current_size;
	if (loc == BOTTOM_B && current_size < 8)
		*pivot_2 = current_size / 2;
}
