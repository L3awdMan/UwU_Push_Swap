/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimize_post_sort_utils.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zotaj-di <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 20:29:46 by zotaj-di          #+#    #+#             */
/*   Updated: 2025/09/11 20:01:36 by zotaj-di         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_opr	neutral_opr(t_opr opr)
{
	if (opr == pa)
		return (pb);
	if (opr == pb)
		return (pa);
	if (opr == ra)
		return (rra);
	if (opr == rb)
		return (rrb);
	if (opr == rra)
		return (ra);
	if (opr == rrb)
		return (rb);
	if (opr == sa)
		return (sa);
	if (opr == sb)
		return (sb);
	if (opr == rrr)
		return (rr);
	return (null_opr);
}

bool	opr_on_same_stack(t_opr ref, t_opr to_check)
{
	if (ref == pa || ref == pb || ref == rr || ref == rrr)
		return (true);
	if (to_check == pa || to_check == pb || to_check == rr || to_check == rrr)
		return (true);
	else if (ref == ra || ref == rra || ref == sa)
		return (to_check == ra || to_check == rra || to_check == sa);
	else if (ref == rb || ref == rrb || ref == sb)
		return (to_check == rb || to_check == rrb || to_check == sb);
	return (false);
}

t_opr	child_opr(t_opr first, t_opr second)
{
	if ((first == ra && second == rb) || (first == rb && second == ra))
		return (rr);
	else if ((first == rra && second == rrb) || (first == rrb && second == rra))
		return (rrr);
	else if ((first == sa && second == sb) || (first == sb && second == sa))
		return (ss);
	else
		return (null_opr);
}

void	remove_opr(t_list *to_delete)
{
	t_list	*prev_list;
	t_list	*next_list;

	if (!to_delete)
		return ;
	prev_list = (*to_delete).prev;
	next_list = (*to_delete).next;
	if (prev_list)
		(*prev_list).next = next_list;
	if (next_list)
		(*next_list).prev = prev_list;
	(*to_delete).prev = NULL;
	(*to_delete).next = NULL;
	ft_lstdelone(to_delete, NULL);
}
