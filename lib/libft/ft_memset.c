/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zotaj-di <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 20:02:31 by zotaj-di          #+#    #+#             */
/*   Updated: 2025/04/29 21:25:23 by zotaj-di         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t	i;
	char	*str;

	i = 0;
	str = s;
	while (i < n)
	{
		str[i] = c;
		i++;
	}
	return (s);
}
/*
int	main()
{
	char	pew[20] = "Dembele, belbele";
	char	paw[20] = "Dembele, belbele";

	ft_memset(pew, '+', 3);
	printf("my own function : %s\n", pew);	
	
	memset(paw, '+', 3);
	printf("real function   : %s\n", paw);
}*/
