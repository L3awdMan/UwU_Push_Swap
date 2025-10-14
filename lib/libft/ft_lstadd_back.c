/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zotaj-di <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 21:30:56 by zotaj-di          #+#    #+#             */
/*   Updated: 2025/09/11 18:29:11 by zotaj-di         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
example_visual:
  before:
	lst: A <-> B <-> C
	new: D
  after:
	lst: A <-> B <-> C <-> D
 * */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*tmp;

	if (!*lst)
	{
		*lst = new;
		(*new).prev = NULL;
	}
	else
	{
		tmp = ft_lstlast(*lst);
		(*tmp).next = new;
		(*new).prev = tmp;
	}
}
