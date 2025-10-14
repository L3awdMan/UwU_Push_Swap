/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zotaj-di <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 17:44:43 by zotaj-di          #+#    #+#             */
/*   Updated: 2025/05/15 19:07:41 by zotaj-di         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long	nb;

	nb = n;
	if (nb < 0)
	{
		write(fd, "-", 1);
		nb *= -1;
	}
	if (nb > 9)
	{
		ft_putnbr_fd((nb / 10), fd);
		ft_putchar_fd((nb % 10) + '0', fd);
	}
	else
		ft_putchar_fd((nb + '0'), fd);
}
/*
int	main(void)
{
	ft_putnbr_fd(21, 1);
	printf("\n");
	ft_putnbr_fd(-21, 2);
	printf("\n");
	ft_putnbr_fd(2147483647, 2);
	printf("\n");
	ft_putnbr_fd(-2147483648, 2);
}*/
