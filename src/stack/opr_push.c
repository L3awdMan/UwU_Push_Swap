/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opr_push.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zotaj-di <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 22:40:33 by zotaj-di          #+#    #+#             */
/*   Updated: 2025/09/30 18:37:47 by zotaj-di         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

void	ft_push(t_stack *src, t_stack *dest)
{
	int	dest_i;

	if (ft_is_full(dest))
		return ;
	dest_i = ft_next_up(dest, (*dest).top);
	(*dest).array[dest_i] = (*src).array[(*src).top];
	(*dest).top = dest_i;
	(*src).array[(*src).top] = 0;
	(*src).top = ft_next_down(src, (*src).top);
}

void	push_to_a(t_ps *data)
{
	ft_push(&(*data).stack_b, &(*data).stack_a);
	if ((*data).record_opr)
		ft_save_opr(data, pa);
}

void	push_to_b(t_ps *data)
{
	ft_push(&(*data).stack_a, &(*data).stack_b);
	if ((*data).record_opr)
		ft_save_opr(data, pb);
}

/* `ft_push` push to the top element from src stack to dest stack */

// ----------- Params : ---------------------------------------------------
// src-> (type t_stack) pointer to the source stack (the one losing the element)
// dest-> (type t_stack) pointer to the destination stack (the one receiving
//         the element )

// ----------- Variables : ---------------------------------------------------
// dest_i -> (type int) integer holding the index where the new element
//           will be placed in dest stack
//
// ----------- Setup : ---------------------------------------------------
//        - check if `dest` is full or empty by using `ft_is_full`
//              if full do nothing just return
//        - find the `dest_i` index for the element in `dest`
//              Use `ft_next_up(dest, dest->top)` to get the next available
//              top index, this handles the circular nature of the stack
//        - copy the element from `src->top` to `dest`
//              ( assign `src->array[src->top]` to `dest->array[dest_i]` )
//        - update the `dest->top` to the new index ( dest_i = dest-> top)
//              now `dest` is top points to the new value pushed
//        - clear the source top value (optional but clean)
//             ( set `src->stack[src->top] = 0` for cleanliness/debugging )
//        - Move `src->top` one down use `next_down(src, src->top)`
//             to remove that top element

/* `push_to_a` push the top element from stack b to stack a */

// ----------- Params : ---------------------------------------------------
// data-> (type t_ps) pointer to the main program `t_ps` holding both stacks

// ----------- Setup : ---------------------------------------------------
//        - call `push(&data->b, &data->a)`,transfer the element from A to B
//        - if recording is enabled (if (record_opr)) call save_op(data,pa)
//             to log the operation

/* `push_to_b` push the top element from stack b to stack a */

// ----------- Params : ---------------------------------------------------
// data -> (type t_ps) pointer to the main program t_ps holding both stacks

// ----------- Setup : ---------------------------------------------------
//        - call push(&data->a, &data->b), transfer the element from A to B
//        - if recording is enabled (if (record_opr)) call save_op(data, pb)
//             to log the operation
