/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zotaj-di <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 17:40:06 by zotaj-di          #+#    #+#             */
/*   Updated: 2025/06/25 22:56:46 by zotaj-di         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_str(char *str)
{
	size_t	i;

	i = 0;
	if (str == NULL)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	return (i);
}
/*
int	main(void)
{
	int	paw;

	paw = ft_print_str("Kimira wiw wiw");
	printf("\n");
	fflush(stdout);
	printf("%d\n", paw);
}*/
