/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zotaj-di <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 16:17:05 by zotaj-di          #+#    #+#             */
/*   Updated: 2025/05/15 22:04:52 by zotaj-di         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*    extract sub string from the original str depending on len     *
 *    line 28 (for test 3):
 *    added condition to protetct my function in case len > lenght of str   */
#include "libft.h"

char	*ft_substr(const char *str, unsigned int str_index, size_t len)
{
	char			*sub_str;
	size_t			i;
	unsigned int	len_str;

	if (!str)
		return (NULL);
	len_str = ft_strlen(str);
	if (str_index >= len_str)
		return (ft_calloc(1, sizeof(char)));
	if (len > len_str - str_index)
		len = len_str - str_index;
	i = 0;
	sub_str = (char *)malloc(len + 1);
	if (!sub_str)
		return (NULL);
	while (i < len && str[str_index + i])
	{
		sub_str[i] = str[str_index + i];
		i++;
	}
	sub_str[i] = '\0';
	return (sub_str);
}
/*
int	main(void)
{
	char	*s;
	char	*sub;
	char	*str;

	s = "42 School is awesome!";
	printf("lenght of string = %zu\n", ft_strlen(s));
	sub = ft_substr(s, 3, 6);
	printf("Substring: \"%s\"\n", sub); // Exfected: "School"
	free(sub);
	sub = ft_substr(s, 20, 10);               // str_index past the end
	printf("Empty substring: \"%s\"\n", sub); // Expected: ""
	free(sub);
	sub = ft_substr(s, 4, 100);              // len too large
	printf("Long substring: \"%s\"\n", sub); // Expected: "chool is awesome!"
	free(sub);
	printf("\n=============\n\n");
	str = ft_substr("year is 1998", 9, 1);
	printf("Result: \"%s\"\n", str); // Expected: "9"
	if (!strcmp(str, "9"))
		printf("✅ PASS\n");
	else
		printf("❌ FAIL\n");
	return (0);
}*/
