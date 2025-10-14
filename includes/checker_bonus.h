/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zotaj-di <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 19:57:03 by zotaj-di          #+#    #+#             */
/*   Updated: 2025/09/30 17:08:40 by zotaj-di         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_BONUS_H
# define CHECKER_BONUS_H

# include "stack.h"

// utils of the checker
void	error_reading_opr(t_ps *data, char *line);
int		push_swap_gnl(int fd, char *line);
t_opr	string_to_opr(const char *str);
void	call_opr(t_ps *data, t_opr opr);
int		ft_strcmp(const char *s1, const char *s2);

// checker
int		main(int ac, char **av);
void	reading_opr(t_ps *data);
bool	check_sorting(t_ps *data);

#endif
