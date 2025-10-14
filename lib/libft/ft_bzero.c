/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zotaj-di <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 21:36:43 by zotaj-di          #+#    #+#             */
/*   Updated: 2025/05/13 17:58:24 by zotaj-di         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t	i;
	char	*str;

	i = 0;
	str = s;
	while (i < n)
	{
		str[i] = 0;
		i++;
	}
}
/*
int	main(void)
{
	char	pew[20] = "Dembele, belbele";
	char	paw[20] = "Dembele, belbele";

	// ft_bzero(pew, 20);
	printf("My function   : %s\n", pew);
	bzero(paw, 20);
	printf("Real function : %s\n", paw);
}*/
