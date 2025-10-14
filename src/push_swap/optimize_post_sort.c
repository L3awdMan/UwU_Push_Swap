/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimize_post_sort.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zotaj-di <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 20:18:03 by zotaj-di          #+#    #+#             */
/*   Updated: 2025/09/30 18:47:01 by zotaj-di         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* *****************************************************************************
 *   This file implements a "post-processing" optimization pass. After my      *
 *   main chunk_sort algorithm has produced a list of operations, the          *
 *   functions in this file will read through that list and clean it up        *
 *   It does two things: first, it removes pairs of operations that cance      *
 *   each other out (like ra and a later rra). Second, it merges adjacent      *
 *   operations into more efficient combined ones (like ra and rb              *
 *   becoming rr). This phase is crucial for achieving a competitive score.    *
 *****************************************************************************/

/* `post_sort_optimization` (void) - The main entry point for the optimization
	phase. It calls the two optimization subroutines in the correct order. */

//--------- Params of the function : -----------------------------------------
// data -> (t_ps *) The main program structure, which contains the list of
//        operations (op_list) that needs to be optimized.

//----- Context & Purpose : ---------------------------------------------------
// This function is the dispatcher for the entire optimization process. It's
// called once, right after the main sort function has finished its work.
// Its purpose is to ensure that both optimization strategies (eliminate and
// merge) are applied to the generated list of moves before they are
// printed.

//--------- Setup to follow for implementation : -----------------------------
// 1.  Safety Check: First, check if there is an operation list to work on.
//     If data->op_list is NULL, simply return.
//
// 2.  Eliminate Redundancy: Call the eliminate_neutral_op function,
//     passing it the start of the operation list (data->op_list). This
//     step will scan for and remove pairs like pa and pb.
//
// 3.  Merge Operations: After the neutral operations are gone, call the
//     merge_op function, also passing data->op_list. This will combine
//     adjacent operations like ra and rb into rr.

/* `eliminate_neutral_opr` (void) - Scans the operations list to find and
	remove pairs of moves that cancel each other out (e.g., ra then rra). */

//--------- Params of the function : -----------------------------------------
// op_list -> (t_list *) A pointer to the head of the linked list
//            containing the generated operations.

//----- Context & Purpose : --------------------------------------------------
// the thing with my recursive algorithm, is while it's smart, can't always
// see the big picture. It might generate a rotate_a early on and then,
// much later, a reverse_rotate_a to undo it. This function acts like a chess
// player looking several moves ahead. It finds these "neutralizing" pairs and
// removes both operations, as they waste moves and achieve nothing.

//--------- variables inside the function -------------------------------------
// ref -> (t_list *) The "reference" node. This pointer iterates through the
//        list, pointing to the operation we are trying to find a match for
//        (e.g., the ra).
//
// cmp -> (t_list *) The "comparison" node. This pointer scans forward from
//        ref, looking for the neutralizing operation (e.g., the rra).
//
// op_neutral -> (t_op) Stores the operation that is the inverse of the ref
//               operation. If ref is sa, op_neutral will be sa. If
//               ref is ra, op_neutral will be rra.

//--------- Setup to follow for implementation -------------------------------
//
// 1.  Initialize ref: Start ref at the beginning of the list.
//
// 2.  Main Loop: Loop through the list with ref as long as it's valid.
//
// 3.  Find the Opposite: Inside the loop, determine the neutralizing
//     operation for the current ref node. You'll need a helper function
//     neutral_op(op_from(ref)) that returns the inverse move.
//
// 4.  Scan Forward: If an opposite exists, start cmp at the node right
//     after ref.
//
// 5.  Inner Loop: Loop forward with cmp. The key is this loop's
//     condition: continue as long as the cmp operation is NOT on the same
//     stack as ref, and is NOT the op_neutral we are looking for.
//     This allows the scan to correctly skip over unrelated moves.
//
//     Example: If ref is ra, the inner loop will skip sb, rb, pb.
//
// 6.  Check for a Match: After the inner loop, check if cmp landed on
//     the op_neutral.
//
// 7.  Eliminate: If it's a match, you've found a pair to eliminate.
//     You'll need a remove_op helper that can safely delete a node from
//     your doubly linked list. Remove both the ref node and the cmp node.
//     Reset ref to the beginning of the list to rescan, as the removal
//     might have created new optimization opportunities.
//
// 8.  Continue: If no match was found, advance ref to the next node and
//     repeat the process.

/* `merge_op` (void) - Scans the list for adjacent operations that can be
	combined into a single, more efficient operation (e.g., ra + rb -> rr).*/

//--------- Params of the function : -----------------------------------------
//
// op_list -> (t_list *) A pointer to the head of the operations list.

//----- Context & Purpose : --------------------------------------------------
//
// This function performs the second pass of optimization. It looks for a
// simpler, more direct kind of inefficiency: two consecutive moves that could
// have been a single move. For example, instead of telling the program to
// "rotate A" and then "rotate B," we can just say "rotate both," which is
// the rr command. This function finds these pairs and merges them.

//--------- variables inside the function : ----------------------------------
//
// reader -> (t_list *) The pointer that iterates through the linked list,
//           node by node.
//
// child -> (t_op) A variable to hold the result of a potential merge. If ra
//          and rb can be merged, child will become rr. If not, it will
//          be 0 or NULL.

//--------- Setup to follow for implementation : ------------------------------
//
// 1.  Initialize reader: Start reader at the head of the list.
//
// 2.  Main Loop: Loop as long as reader and reader->next are both
//     valid (we need to look at pairs of nodes).
//
// 3.  Check for Merge: Inside the loop, look at the operation in reader
//     and the one in reader->next. Call a helper function,
//     child_op(op_from(reader), op_from(reader->next)), that checks if
//     they form a valid pair (like sa+sb or ra+rb). If they do, this
//     helper should return the merged operation (ss or rr). If not, it
//     should return a value indicating failure (like 0).
//
// 4.  Perform Merge: If the child_op helper returned a valid new
//     operation:
//
//     a.  Update: Change the operation in the current reader node to
//         this new child operation.
//
//     b.  Remove: Delete the reader->next node, as its operation has
//         now been merged into the reader node.
//
// 5.  Advance: Move reader to the next node in the list and repeat.

void	post_sort_optimization(t_ps *data)
{
	if (!(*data).opr_list)
		return ;
	eliminate_neutral_opr((*data).opr_list);
	merge_opr((*data).opr_list);
}

void	eliminate_neutral_opr(t_list *opr_list)
{
	t_list	*ref;
	t_list	*cmp;
	t_opr	opr_neutral;

	ref = (*opr_list).next;
	while (ref && (*ref).next)
	{
		opr_neutral = neutral_opr(ft_opr_from(ref));
		if (opr_neutral)
		{
			cmp = (*ref).next;
			while (cmp && !opr_on_same_stack(ft_opr_from(ref), ft_opr_from(cmp))
				&& (ft_opr_from(cmp) != opr_neutral))
				cmp = (*cmp).next;
			if (cmp && (*ref).prev && ft_opr_from(cmp) == opr_neutral)
			{
				ref = (*ref).prev;
				remove_opr((*ref).next);
				remove_opr(cmp);
				continue ;
			}
		}
		ref = (*ref).next;
	}
}

void	merge_opr(t_list *opr_list)
{
	t_list	*reader;
	t_opr	child;

	reader = (*opr_list).next;
	while (reader && (*reader).next)
	{
		child = child_opr(ft_opr_from(reader), ft_opr_from((*reader).next));
		if (child != null_opr)
		{
			remove_opr((*reader).next);
			(*reader).content = (void *)(uintptr_t)child;
		}
		else
			reader = (*reader).next;
	}
}
