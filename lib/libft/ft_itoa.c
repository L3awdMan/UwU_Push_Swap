/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zotaj-di <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 20:05:52 by zotaj-di          #+#    #+#             */
/*   Updated: 2025/05/15 22:12:34 by zotaj-di         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long int	ft_len(int n)
{
	int	len;

	len = 0;
	if (n <= 0)
		len = 1;
	while (n != 0)
	{
		len++;
		n = n / 10;
	}
	return (len);
}

static char	*ft_char(char *str, unsigned int n, long int len)
{
	if (n == 0)
	{
		str[0] = '0';
		return (str);
	}
	while (n > 0)
	{
		str[len--] = '0' + (n % 10);
		n = n / 10;
	}
	return (str);
}

char	*ft_itoa(int n)
{
	char			*str;
	long int		len;
	unsigned int	number;
	int				sign;

	sign = 1;
	len = ft_len(n);
	str = (char *)malloc(len + 1 * sizeof(char));
	if (!str)
		return (NULL);
	str[len--] = '\0';
	if (n == 0)
		str[0] = '0';
	if (n < 0)
	{
		sign *= -1;
		number = n * -1;
		str[0] = '-';
	}
	else
		number = n;
	str = ft_char(str, number, len);
	return (str);
}
/*
int	main(void)
{
	int		test_values[] = {0, 1, -1, 42, -42, 123456, -123456, 2147483647,
				-2147483648};
	size_t	num_tests;
	int		n;
	char	*str;

	num_tests = sizeof(test_values) / sizeof(test_values[0]);
	for (size_t i = 0; i < num_tests; i++)
	{
		n = test_values[i];
		str = ft_itoa(n);
		if (str)
		{
			printf("ft_itoa(%d) = \"%s\"\n", n, str);
			free(str); // Don't forget to free to avoid memory leaks
		}
		else
		{
			printf("ft_itoa(%d) = NULL (memory allocation failed)\n", n);
		}
	}
	return (0);
}*/
