/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zotaj-di <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 16:22:21 by zotaj-di          #+#    #+#             */
/*   Updated: 2025/05/04 16:51:42 by zotaj-di         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
    Copy the src into the dest "behind the scene" and return the length of src

	// if size != 0 thqt means we will copy something
	// while the src[i] and the i is strict less the n - 1 (for '\0')
	// we copy the src into the dest
	// we give the last tab the '\0'

*/
#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t n)
{
	size_t	i;

	i = 0;
	if (n != 0)
	{
		while (src[i] && (i < n - 1))
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = '\0';
	}
	return (ft_strlen(src));
}
/*
int 	main()
{
	char	paw[20] = "Aha Aha";
	char	meow[5];
	size_t	ret;
	
	ret = ft_strlcpy(meow, paw, 8);
	printf("return value : %zu\n", ret);
	
	printf("dest after copy : %s", meow);
}*/
