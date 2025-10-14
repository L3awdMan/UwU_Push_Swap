/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zotaj-di <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 16:59:38 by zotaj-di          #+#    #+#             */
/*   Updated: 2025/05/15 19:17:27 by zotaj-di         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	size_t	i;

	if (!s || !f)
		return ;
	i = 0;
	while (s[i])
	{
		f(i, &s[i]);
		i++;
	}
	s[i] = '\0';
}
/*
#include <ctype.h>

// Example function: converts lowercase to uppercase using index
void	to_upper_index(unsigned int i, char *c)
{
	if (i % 2 == 0 && *c >= 'a' && *c <= 'z')
		*c -= 32; // or use *c = toupper(*c);
}

int	main(void)
{
	char	str[] = "wow ! libft is so much fun!! ha ha ...";

	printf("Before: %s\n", str);
	ft_striteri(str, to_upper_index);
	printf("After:  %s\n", str);
	return (0);
}*/
