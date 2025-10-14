/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zotaj-di <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 17:01:32 by zotaj-di          #+#    #+#             */
/*   Updated: 2025/08/30 17:02:32 by zotaj-di         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_ps	data;

	ft_init_data(&data, argc, argv, true);
	sort(&data);
	ft_print_operations(data.opr_list);
	ft_free_data(&data);
	exit(EXIT_SUCCESS);
}
