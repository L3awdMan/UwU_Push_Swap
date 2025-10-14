/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zotaj-di <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 03:40:03 by zotaj-di          #+#    #+#             */
/*   Updated: 2025/09/30 18:49:38 by zotaj-di         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

/* `ft_save_opr` stores an operation `t_op` into the `op_list` */

// ----------- Params : ---------------------------------------------------
// data -> (type t_ps) pointer to the main structure `t_ps` holding both stacks
// opr -> (type t_opr) an enum `t_op` representing the operation

// ----------- Variables : ---------------------------------------------------
// new -> (type t_list) pointer to a new node that stores operations

// ----------- Setup: ---------------------------------------------------
//       - cast opr to void store ( (void *)(uintptr_t)opr) ) then create
//             a new node ( new = ft_lstnew(...) ) to stores the operation
//       - handle allocation error ( if new is NULL you call `ft_error(data)` )
//       - add `new` to end of `data->op_list` using `ft_lstadd_back`
//           ( ft_lstadd_back(&data->op_list, new) )

/* `ft_print_operations` print all saved operations */

// ----------- Params : ---------------------------------------------------
// head -> (type t_list) pointer to the beginning of the operation list

// ----------- Variables : ---------------------------------------------------
// index -> (type t_list) used to iterate through the entire list node by node

// ----------- Setup: ---------------------------------------------------
//       - start with index = head
//       - while `index` is not NULL
//           -  a. Convert index->content to t_op → op_from(index)
//           -  b. Get operation string → op_to_string(op)
//           -  c. Print the operation using ft_printf
//           -  d. Move index to the next node

/* `ft_opr_to_string` (type cosnt char) convert an enum value
 *                    to it's corresponding string */

// ----------- Params : ---------------------------------------------------
// opr -> (type t_opr) enum that contains the operations

// ----------- Variables: ---------------------------------------------------
// strings -> (type static const char) string that represent each enum value

// ----------- Setup: ---------------------------------------------------
//       - map each index to its operation string
//         ( strings[1] = "pa", strings[2] = "pb", etc... )
//       - return strings[op] index into array by the enum value

/* `op_from` (type t_ opr) convert the content stored in a list node (as void *)
 *          back into an operation enum `t_opr` */

// ----------- Params : ---------------------------------------------------
// node -> (type t_list) list node containing operation stored as void pointer

// ----------- Setup : ---------------------------------------------------
//       -  cast node->content first to `uintptr_t`
//          then to `t_opr` enum
//          return all of this

void	ft_save_opr(t_ps *data, t_opr opr)
{
	t_list	*new;

	new = ft_lstnew((void *)(uintptr_t)opr);
	if (!new)
		ft_error(data);
	ft_lstadd_back(&(*data).opr_list, new);
}

void	ft_print_operations(t_list *head)
{
	t_list	*reader;

	reader = head;
	while (reader)
	{
		ft_printf("%s\n", ft_opr_to_string(ft_opr_from(reader)));
		reader = (*reader).next;
	}
}

const char	*ft_opr_to_string(t_opr opr)
{
	static const char	*strings[12];

	strings[0] = "null_opr";
	strings[1] = "pa";
	strings[2] = "pb";
	strings[3] = "ra";
	strings[4] = "rb";
	strings[5] = "rr";
	strings[6] = "rra";
	strings[7] = "rrb";
	strings[8] = "rrr";
	strings[9] = "sa";
	strings[10] = "sb";
	strings[11] = "ss";
	return (strings[opr]);
}

t_opr	ft_opr_from(t_list *node)
{
	return ((t_opr)(uintptr_t)(*node).content);
}
