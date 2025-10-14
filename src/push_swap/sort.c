/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zotaj-di <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 01:14:48 by zotaj-di          #+#    #+#             */
/*   Updated: 2025/09/30 10:42:56 by zotaj-di         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**************************************************************************
 *  "sort.c" file is the brain of my push_swap program it analyzes        *
 *  the size of the stack and chooses the most efficient sorting strategy *
 *  for that specific case. For very small stacks                         *
 *************************************************************************/

/* `sort` (void) - This is the main sorting entry point, it checks the stack
 *  size and calls the appropriate sorting function based on
 *  the number of elements. */

//--------- Params of the function : --------------------------
// data (t_ps *) -> A pointer to your main push_swap structure, containing both
//                stacks and their sizes.

//--------- Setup to follow for implementation : --------------------------
//
// This function is a high-level router that directs the program to the correct
// sorting algorithm.
//
//   Handle Base Cases: It first checks for trivial cases where no sorting
//   is needed:
//
//        If the stack has 1 or 0 elements (data->stack_a.size <= 1). OR
//        If the stack is already sorted (checked by your is_sorted function).
//
//        In these cases, the function simply returns, and the program
//        terminates.
//
//    Sort Size 3: If the stack has exactly three elements, it calls
//    `sort_three_a`, which is a specialized function to handle this specific
//    case efficiently.
//
//    Sort Size 5: If the stack has exactly five elements, it calls
//    `sort_five_a`, another specialized function.
//
//    General Case: For any other size (2, 4, or >5), it calls the main
//    sorting algorithm, chunk_sort. This is where your primary logic
//    for sorting large numbers will live.
//
//    Optimization: After the main sorting is complete, it calls
//    `post_sort_optimization`. This is a great addition, suggesting you might
//    have a step to clean up redundant moves (like a ra followed by an rra).

/* `sort_three_a` (void) - Sorts a stack of three elements in stack A using
 *  the minimum number of operations possible. */

//--------- Params of the function : --------------------------
// data (t_ps *) -> Pointer to your main data structure.

//--------- variables inside the function : --------------------------
// first, second, third (int) -> These variables store the values of the top,
//     middle, and bottom elements of stack A, respectively. This makes
//      the conditions easier to read than repeatedly calling value().

//--------- Setup to follow for implementation : --------------------------
//
// This function is a series of if/else if statements that identify which
// of the 5 unsorted permutations of three numbers is currently in the stack.
// There are 3!=6 total permutations, and one of them is the sorted one (1 2 3),
// which is handled by the initial is_sorted check.
//
//   Example Case 1: [2 1 3]
//
//        first > second (2 > 1)
//
//        third > second (3 > 1)
//
//        third > first (3 > 2)
//
//        This pattern corresponds to the sequence 2 1 3. The only action
//        needed is to swap the top two elements.
//
//        Implementation: Call swap_a(data).
//
//   Case 2: [3 1 2]
//
//        first > second (3 > 1) -> true
//
//        third > second (2 > 1) -> true
//
//        first > third (3 > 2) -> true
//
//        Logic: The largest number is at the top. Rotating it to the bottom
//        will place the other two elements (1 and 2) in their correct
//        sorted positions.
//
//        Implementation: Call rotate_a(data).
//
//   Case 3: [2 3 1]
//
//        second > first (3 > 2) -> true
//
//        second > third (3 > 1) -> true
//
//        first > third (2 > 1) -> true
//
//        Logic: The smallest number is at the bottom. A single reverse
//        rotation will bring it to the top, sorting the stack.
//
//        Implementation: Call reverse_rotate_a(data).
//
//   Case 4: [1 3 2]
//
//        second > first (3 > 1) -> true
//
//        second > third (3 > 2) -> true
//
//        third > first (2 > 1) -> true
//
//        Logic: The first element is correct, but the second and third are
//        swapped. A swap (sa) turns 1 3 2 into 3 1 2. Now it matches Case 2,
//        which is solved by a rotate (ra).
//
//        Implementation: Call swap_a(data), then rotate_a(data).
//
//    Case 5: [3 2 1]
//
//        first > second (3 > 2)
//
//        second > third (2 > 1)
//
//        first > third (3 > 1)
//
//        This is the fully reversed case. Swapping the top two gives 2 3 1.
//        Then, a reverse rotate gives 1 2 3.
//
//        Implementation: Call swap_a(data), then reverse_rotate_a(data).
//
// The function continues this logic for all other unsorted combinations.

/* `sort_five_a` (void) - Sorts a stack of five elements by isolating the two
 *  smallest elements in stack B, sorting the remaining three in A, and then
 *  pushing the two back. */

//--------- Params of the function : --------------------------
// data (t_ps *) -> Pointer to your main data structure.

//--------- Setup to follow for implementation : --------------------------
//
// Step 1: Isolate the Two Smallest Elements
//
//  The goal is to move the numbers 1 and 2 into Stack B, leaving the other
//  three in Stack A. We use a while loop that continues as long as Stack A
//  has more than 3 elements.
//
//    Loop: while (current_size(&data->stack_a) > 3)
//
//    Check: Inside the loop, we look at the top element of Stack A:
//    if (value(&data->stack_a, 1) == 1 || value(&data->stack_a, 1) == 2)
//
//        If TRUE (the top is 1 or 2): We've found what we're looking for.
//        We push it to Stack B using push_b(data).
//
//        If FALSE (the top is something else): We don't want this number yet,
//        so we move it out of the way by sending it to the bottom of its
//        own stack using rotate_a(data). This brings the next number to
//        the top for us to inspect.
//
// -> Example:
//
//    Start: A: [3, 5, 2, 1, 4], B: []. size is 5.
//
//    Loop 1: Top is 3. Not 1 or 2. ra. -> A: [5, 2, 1, 4, 3].
//
//    Loop 2: Top is 5. Not 1 or 2. ra. -> A: [2, 1, 4, 3, 5].
//
//    Loop 3: Top is 2. It's a target! pb. -> A: [1, 4, 3, 5], B: [2].
//    size is now 4.
//
//    Loop 4: Top is 1. It's a target! pb. -> A: [4, 3, 5], B: [1, 2].
//    size is now 3.
//
//    The loop condition (3 > 3) is now false. The loop terminates.
//
//  Outcome of Step 1: Stack A now contains the three largest numbers,
//  and Stack B contains the two smallest.
//
// Step 2: Order the Elements in Stack B
//
//   Stack B now holds 1 and 2, but they might be in the wrong order
//   (1 on top of 2). We need the larger number (2) on top so that when
//   we push them backlater, 1 ends up at the very top of Stack A.
//
//    Check: if (value(&data->b, 1) < value(&data->b, 2))
//
//        This condition literally asks: "Is the top element of B smaller
//        than the one below it?"
//
//        If TRUE: They are in the wrong order. We fix it with swap_b(data).
//
// -> Example:
//
//    Stack B is [1, 2]. The top value (1) is less than the second value (2).
//
//    The condition is true, so we perform sb.
//
//    Outcome of Step 2: Stack B is now correctly ordered: [2, 1].
//
// Step 3: Sort the Three Elements in Stack A
//
//   This is the "conquer" step. Stack A has only three elements, which is
//   a simple problem we already know how to solve.
//
//    Action: Call sort_three_a(data). This function will apply the correct
//    1 or 2 moves to sort the remaining numbers.
//
// -> Example:
//
//    Stack A is [4, 3, 5].
//
//    sort_three_a is called. It will perform sa to get [3, 4, 5].
//
//    Outcome of Step 3: Stack A is now sorted: [3, 4, 5].
//
// Step 4: Merge the Stacks
//
//   Now that both parts are sorted, we simply push the elements from Stack B
//   back onto Stack A.
//
//    Action: Call push_a(data) twice.
//
// Running Example:
//
//    State: A: [3, 4, 5], B: [2, 1].
//
//    First pa: The 2 is pushed from B to A. -> A: [2, 3, 4, 5], B: [1].
//
//    Second pa: The 1 is pushed from B to A. -> A: [1, 2, 3, 4, 5], B: [].
//
//   Final Result: Stack A is fully sorted, and Stack B is empty.
//   The mission is complete

void	sort(t_ps *data)
{
	if ((*data).stack_a.size <= 1 || ft_is_sorted(data))
		return ;
	else if ((*data).stack_a.size == 3)
		sort_three_a(data);
	else if ((*data).stack_a.size == 5)
		sort_five_a(data);
	else
		chunk_sort(data);
	post_sort_optimization(data);
}

void	sort_three_a(t_ps *data)
{
	int	first;
	int	second;
	int	third;

	first = ft_value(&(*data).stack_a, 1);
	second = ft_value(&(*data).stack_a, 2);
	third = ft_value(&(*data).stack_a, 3);
	if ((first > second) && (third > second) && (third > first))
		swap_a(data);
	else if ((first > second) && (third > second) && (first > third))
		rotate_a(data);
	else if ((second > first) && (second > third) && (first > third))
		reverse_rotate_a(data);
	else if ((second > first) && (second > third) && (third > first))
	{
		swap_a(data);
		rotate_a(data);
	}
	else if ((first > second) && (second > third) && (first > third))
	{
		swap_a(data);
		reverse_rotate_a(data);
	}
}

void	sort_five_a(t_ps *data)
{
	while (ft_current_size(&(*data).stack_a) > 3)
	{
		if (ft_value(&(*data).stack_a, 1) == 1 || ft_value(&(*data).stack_a,
				1) == 2)
			push_to_b(data);
		else
			rotate_a(data);
	}
	if (ft_value(&(*data).stack_b, 1) < ft_value(&(*data).stack_b, 2))
		swap_b(data);
	sort_three_a(data);
	push_to_a(data);
	push_to_a(data);
}
