/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zotaj-di <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 18:35:37 by zotaj-di          #+#    #+#             */
/*   Updated: 2025/05/13 19:15:01 by zotaj-di         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*dest;
	int		i;
	int		j;

	if (!s1 || !s2)
		return (NULL);
	dest = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!dest)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		dest[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		dest[i] = s2[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (dest);
}
/*
void	test_strjoin(const char *s1, const char *s2)
{
	char	*result;

	result = ft_strjoin(s1, s2);
	if (result)
		printf("ft_strjoin(\"%s\", \"%s\") = \"%s\"\n", s1 ? s1 : "NULL",
			s2 ? s2 : "NULL", result);
	else
		printf("ft_strjoin(\"%s\", \"%s\") = NULL\n", s1 ? s1 : "NULL",
			s2 ? s2 : "NULL");
	free(result); // Don't forget to free the allocated memory!
}

int	main(void)
{
	// Normal cases
	test_strjoin("Hello, ", "world!");
	test_strjoin("42", " School");
	test_strjoin("", "Test");
	test_strjoin("Test", "");
	// Edge cases
	test_strjoin("", "");
	test_strjoin(NULL, "Valid");
	test_strjoin("Valid", NULL);
	test_strjoin(NULL, NULL);
	return (0);
}*/
