/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zotaj-di <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 17:29:12 by zotaj-di          #+#    #+#             */
/*   Updated: 2025/06/26 16:26:42 by zotaj-di         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

int	ft_print_char(int c);
int	ft_print_str(char *str);
int	ft_print_nbr(int nb);
int	ft_print_hex(unsigned int num, const char specifier);
int	ft_print_ptr(uintptr_t ptr);
int	ft_print_unsigned(unsigned int number);

int	ft_printf(const char *str, ...);

#endif
