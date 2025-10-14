/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zotaj-di <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 17:49:44 by zotaj-di          #+#    #+#             */
/*   Updated: 2025/05/04 14:26:51 by zotaj-di         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
    copy a src to dest (depending on size n) while manipulating overlaping
*/
#include "libft.h"

void	*ft_memmove(void *dest, const char *src, size_t n)
{
	size_t			i;
	unsigned char	*t_dest;
	unsigned char	*t_src;

	t_dest = (unsigned char *)dest;
	t_src = (unsigned char *)src;
	i = 0;
	if (t_dest == t_src || n == 0)
		return (dest);
	i = 0;
	if (t_dest > t_src)
		while (n-- > 0)
			t_dest[n] = t_src[n];
	else
	{
		while (i < n)
		{
			t_dest[i] = t_src[i];
			i++;
		}
	}
	return (dest);
}
/*
int	main()
{
	char test[20] = "Hello brother";
	char test2[20] = "********";

	ft_memmove(test2, test, 5);
	printf("%s\n", test2);
}*/
