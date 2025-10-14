/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zotaj-di <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 14:01:50 by zotaj-di          #+#    #+#             */
/*   Updated: 2025/05/12 14:15:18 by zotaj-di         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str)
{
	size_t	len_str;
	char	*dest;
	int		i;

	len_str = ft_strlen(str);
	dest = (char *)malloc(sizeof(char) * (len_str + 1));
	if (!dest)
		return (NULL);
	i = 0;
	while (str[i])
	{
		dest[i] = str[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
/*
void	test_strdup(const char *s)
{
	char	*dup1;
	char	*dup2;

	dup1 = strdup(s);
	dup2 = ft_strdup(s);
	if (dup1 == NULL || dup2 == NULL)
		printf("Memory allocation failed!\n");
	else if (strcmp(dup1, dup2) == 0)
		printf("✅ PASS: \"%s\"\n", s);
	else
		printf("❌ FAIL: \"%s\" | Expected: \"%s\", Got: \"%s\"\n", s, dup1,
			dup2);
	free(dup1);
	free(dup2);
}

int	main(void)
{
	test_strdup("");              // Empty string
	test_strdup("Hello, World!"); // Normal string
	test_strdup("A");             // Single character
	test_strdup("Line1\nLine2");  // Newline characters
	test_strdup("123\0456");      // Contains octal escape
	test_strdup("null\0hidden");
		// Embedded null: won't be fully tested by strcmp
	return (0);
}
*/
