/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zotaj-di <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 22:49:14 by zotaj-di          #+#    #+#             */
/*   Updated: 2025/09/11 18:31:26 by zotaj-di         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 *  `ft_lstclear` Deletes each node of the linked list
 *
// ----------- Params : ---------------------------------------------------
 *
 * list -> (type t_list **) a double pointer to the head of the linked list
 *      - This allows the function to modify the caller's list pointer
 * del -> (type (void)(*)(void *)) A function pointer to a function that
 *        properly deletes the content of a node
			( Typically it calls `free()` on the node's content )

 // ----------- Variables : ---------------------------------------------------
 *  current -> (type t_list *) points to the node that being procced on the loop
 *  next -> (type t_list *) Temporarily holds the reference to the next node
 *         before the current node is deleted

 // ----------- Setup : ---------------------------------------------------
 *      - check if list, *list or `del` are NULL, return if any are NULL
 *      - assign `list` to current ( current = list )
 *      - loop until all nodes being procced ( while (current) )
 *      - set `next` to the (*current).next
 *      - delete current node using `ft_lstdelone(current, del)`
 *      - move current to next node ( current = next )
 *      - set `*list` to NULL
 * */

void	ft_lstclear(t_list **list, void (*del)(void *))
{
	t_list	*buffer;

	if (!list || !*list)
		return ;
	while (*list)
	{
		buffer = (**list).next;
		ft_lstdelone(*list, del);
		*list = buffer;
	}
	*list = NULL;
}
