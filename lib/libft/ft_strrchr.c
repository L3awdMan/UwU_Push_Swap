/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zotaj-di <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 03:24:12 by zotaj-di          #+#    #+#             */
/*   Updated: 2025/05/15 21:03:16 by zotaj-di         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	while (i >= 0)
	{
		if (s[i] == (unsigned char)c)
			return ((char *)(s + i));
		i--;
	}
	return (NULL);
}
/*
int	main(void)
{
	char		*pew;
	char		s;
	const char	*str = "test string";

	pew = "Zommun core";
	s = 'o';
	printf("%s\n", ft_strrchr(pew, s));
	// 't' + 256 = 372; 372 % 256 = 116 = 't'
	printf("Expecting: %p\n", strrchr(str, 't' + 256));
	printf("Your code: %p\n", ft_strrchr(str, 't' + 256));
}*/
