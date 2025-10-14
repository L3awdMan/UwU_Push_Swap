/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zotaj-di <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 21:50:09 by zotaj-di          #+#    #+#             */
/*   Updated: 2025/08/05 21:54:52 by zotaj-di         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * before adding :
 * [ A ] <-> [ B ] <-> [ C ] -> NULL
 *
 * after adding :
 * [ A ] <-> [ B ] <-> [ C ] <-> [ D ] -> NULL
 */

t_list	*ft_lstlast(t_list *lst)
{
	while (lst && (*lst).next)
		lst = (*lst).next;
	return (lst);
}
