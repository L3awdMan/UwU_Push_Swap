/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zotaj-di <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 23:04:49 by zotaj-di          #+#    #+#             */
/*   Updated: 2025/05/06 19:04:39 by zotaj-di         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	if (dest == NULL && src == NULL)
		return (NULL);
	if (dest != src)
	{
		while (i < n)
		{
			((unsigned char *)dest)[i] = ((unsigned char *)src)[i];
			i++;
		}
	}
	return (dest);
}
/*
int	main(void)
{
	char	pew[20] = "Dembele, belbele";
	char	paw[20] = "WHAT ???";

	ft_memcpy(paw, pew, 3);
	printf("real OG function  : %s\n", paw);

	memcpy(paw, pew, 3);
	printf("original function : %s\n", paw);
}*/
