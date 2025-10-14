/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zotaj-di <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 21:05:05 by zotaj-di          #+#    #+#             */
/*   Updated: 2025/08/29 01:14:49 by zotaj-di         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* `move_from_to` (int) - This is the main controller or "dispatcher" function.
 *   It reads the starting location of a desired move and calls
 *   the appropriate helper function to execute it. */

//--------- Params of the function: --------------------------
// data (t_ps *) -> A pointer to your main data structure which holds both
//                 stack A and stack B, and any other relevant information.
// from (t_loc) -> An enum or integer representing the starting location
//                 of the element you want to move.
//                 The possible values are TOP_A, TOP_B, BOTTOM_A, or BOTTOM_B.
// to (t_loc) -> An enum or integer representing the destination location for
//               that element.

//--------- variables inside the function : --------------------------
//
//   This function does not declare any local variables.

//--------- Setup to follow for implementation : --------------------------
//
// This function acts like a switchboard. It uses a series of if-else
// if statements to check the value of the from parameter.
//
//    Check if the move starts from TOP_A: If from is TOP_A,
//    it calls the move_from_top_a function, passing along the data structure
//    and the final destination to.
//
//    Check if the move starts from TOP_B: If from is TOP_B, it calls
//    the move_from_top_b function.
//
//    Check if the move starts from BOTTOM_A: If from is BOTTOM_A,
//    it calls move_from_bottom_a.
//
//    Check if the move starts from BOTTOM_B: If from is BOTTOM_B,
//    it calls move_from_bottom_b.
//
//    Finally, it returns 1 to indicate success.

/* `move_from_top_a` (void) - Executes the sequence of operations needed to move
 *  the element at the top of stack A to a specified destination. */

//--------- Params of the function: --------------------------
// data (t_ps *) -> Pointer to your main data structure.
// to (t_loc) -> The destination for the element currently at the top of A.

//--------- Setup to follow for implementation : --------------------------
//
// This function checks the to parameter to decide which operations to perform.
//
//    If the destination is TOP_B:
//
//        This is the simplest case. Moving from the top of A to the top of B
//        is a single push operation.
//
//        Call push_to_b(data).
//
//    Else if the destination is BOTTOM_A:
//
//        To move the top element to the bottom of the same stack, you just
//        need to rotate that stack.
//
//        Call rotate_a(data).
//
//    If the destination is BOTTOM_B:
//
//        This is a two-step process:
//
//            First, move the element from A to B.
//            It will land on top of B. -> push_to_b(data).
//
//            Now that it's on top of B,
//            move it to the bottom of B. -> rotate_b(data).

/* `move_from_top_b`(void) - Executes the sequence of operations needed to move
 * the element at the top of stack B to a specified destination. */

//--------- Params of the function: --------------------------
// data (t_ps *) -> Pointer to your main data structure.
// to (t_loc) -> The destination for the element currently at the top of B.

//--------- Setup to follow for implementation : --------------------------
//
// This is the mirror image of move_from_top_a.
//
//    If the destination is TOP_A:
//
//        Call push_to_a(data).
//
//    If the destination is BOTTOM_B:
//
//       Call rotate_b(data).
//
//    If the destination is BOTTOM_A:
//
//        First, move the element to the top of A. -> push_to_a(data).
//
//       Then, move it to the bottom of A. -> rotate_a(data).

/* `move_from_bottom_a` (void) - Executes the sequence of operations needed
 * to move the element at the bottom of stack A to a specified destination. */

//--------- Params of the function: --------------------------
// data (t_ps *) -> Pointer to your main data structure.
// to (t_loc) -> The destination for the element currently at the bottom of A.

//--------- Setup to follow for implementation : --------------------------
//
// The key insight here is that you cannot directly access the bottom element.
// You must first bring it to the top. Every move from the bottom will therefore
// start with a reverse rotate.
//
//    Bring the bottom element to the top of A: The first step for any
//    destination is to call reverse_rotate_a(data).
//
//    Now that the desired element is at TOP_A, the problem becomes identical
//    to the move_from_top_a function. You just perform the required
//    moves from there.
//
//    If the destination is TOP_A:
//
//        You just needed to bring the bottom element to the top.
//        The single reverse_rotate_a(data) call is enough.
//
//    If the destination is TOP_B:
//
//        First, bring it to the top of A. -> reverse_rotate_a(data).
//
//        Then, push it to the top of B. -> push_to_b(data).
//
//    If the destination is BOTTOM_B:
//
//        First, bring it to the top of A. -> reverse_rotate_a(data).
//
//        Second, push it to the top of B. -> push_to_b(data).
//
//        Finally, rotate it to the bottom of B. -> rotate_b(data).

/* `move_from_bottom_b`` (void) - Executes the sequence of operations needed to
 * move the element at the bottom of stack B to a specified destination. */

//--------- Params of the function: --------------------------
// data (t_ps *) -> Pointer to your main data structure.
// to (t_loc) -> The destination for the element currently at the bottom of B.

//--------- Setup to follow for implementation : --------------------------
//
// This is the mirror image of move_from_bottom_a. Every operation starts
// by bringing the bottom element of B to the top.
//
//    Bring the bottom element to the top of B: The first step
//    is always r_rotate_b(data).
//
//    Now proceed with the moves as if you were starting from TOP_B.
//
//    If the destination is TOP_B:
//
//        The single reverse_rotate_b(data) call is all you need.
//
//    If the destination is TOP_A:
//
//        Bring it to the top of B. -> reverse_rotate_b(data).
//
//        Push it to the top of A. -> push_to_a(data).
//
//    If the destination is BOTTOM_A:
//
//        Bring it to the top of B. -> reverse_rotate_b(data).
//
//        Push it to the top of A. -> push_to_a(data).
//
//        Rotate it to the bottom of A. -> rotate_a(data).

int	move_from_to(t_ps *data, t_location from, t_location to)
{
	if (from == TOP_A)
		move_from_top_a(data, to);
	else if (from == TOP_B)
		move_from_top_b(data, to);
	else if (from == BOTTOM_A)
		move_from_bottom_a(data, to);
	else if (from == BOTTOM_B)
		move_from_bottom_b(data, to);
	return (1);
}

void	move_from_top_a(t_ps *data, t_location to)
{
	if (to == TOP_B)
		push_to_b(data);
	else if (to == BOTTOM_A)
		rotate_a(data);
	else if (to == BOTTOM_B)
	{
		push_to_b(data);
		rotate_b(data);
	}
}

void	move_from_top_b(t_ps *data, t_location to)
{
	if (to == TOP_A)
		push_to_a(data);
	else if (to == BOTTOM_B)
		rotate_b(data);
	else if (to == BOTTOM_A)
	{
		push_to_a(data);
		rotate_a(data);
	}
}

void	move_from_bottom_a(t_ps *data, t_location to)
{
	if (to == TOP_A)
		reverse_rotate_a(data);
	else if (to == TOP_B)
	{
		reverse_rotate_a(data);
		push_to_b(data);
	}
	else if (to == BOTTOM_B)
	{
		reverse_rotate_a(data);
		push_to_b(data);
		rotate_b(data);
	}
}

void	move_from_bottom_b(t_ps *data, t_location to)
{
	if (to == TOP_B)
		reverse_rotate_b(data);
	else if (to == TOP_A)
	{
		reverse_rotate_b(data);
		push_to_a(data);
	}
	else if (to == BOTTOM_A)
	{
		reverse_rotate_b(data);
		push_to_a(data);
		rotate_a(data);
	}
}
