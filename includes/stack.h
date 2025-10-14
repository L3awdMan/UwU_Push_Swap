/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zotaj-di <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 11:03:30 by zotaj-di          #+#    #+#             */
/*   Updated: 2025/09/11 18:39:08 by zotaj-di         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H

# include "ft_printf.h"
# include "libft.h"
# include <errno.h>
# include <limits.h>
# include <stdbool.h>
# include <stdint.h>
# include <stdlib.h>
// Stack structure
typedef struct s_stack
{
	int		*array;
	int		top;
	int		bottom;
	int		size;
}			t_stack;

// Master structre , grouped state of push_swap "context"
typedef struct s_push_swap
{
	t_stack	stack_a;
	t_stack	stack_b;
	t_list	*opr_list;
	bool	record_opr;
}			t_ps;

typedef enum s_opr
{
	null_opr,
	pa,
	pb,
	ra,
	rb,
	rr,
	rra,
	rrb,
	rrr,
	sa,
	sb,
	ss
}			t_opr;

// Data mamnagement, initialize the stack and the data inside it
void		ft_init_stack(t_ps *data, t_stack *stack, int size);
void		ft_init_data(t_ps *data, int ac, char **av, bool record_opr);
bool		ft_is_sorted(t_ps *data);
void		ft_error(t_ps *data);
void		ft_free_data(t_ps *data);

// Utils 1 , filling the stack, check that arg valid and if there's any dup
void		ft_fill_stack(t_ps *data, t_stack *stack, int size, char **av);
bool		ft_valid_arg(char *av);
void		ft_check_duplicates(t_ps *data, int *numbers, int size);
void		ft_ranking_num(int *numbers, int *rank, int size);

// Utils 2 contains helper functions
int			ft_next_up(t_stack *stack, int i);
int			ft_next_down(t_stack *stack, int i);
int			ft_value(t_stack *stack, int n);
int			ft_current_size(t_stack *stack);
bool		ft_is_full(t_stack *stack);

// operations utils
void		ft_save_opr(t_ps *data, t_opr opr);
void		ft_print_operations(t_list *head);
const char	*ft_opr_to_string(t_opr opr);
t_opr		ft_opr_from(t_list *node);

// Push to stack A or stack B
void		ft_push(t_stack *src, t_stack *dest);
void		push_to_a(t_ps *data);
void		push_to_b(t_ps *data);

// swap operation
void		ft_swap(t_stack *stack);
void		swap_a(t_ps *data);
void		swap_b(t_ps *data);
void		swap_a_and_b(t_ps *data);

// Rotate operation
void		ft_rotate(t_stack *stack);
void		rotate_a(t_ps *data);
void		rotate_b(t_ps *data);
void		rotate_a_and_b(t_ps *data);

// reverse rotate operation
void		ft_reverse_rotate(t_stack *stack);
void		reverse_rotate_a(t_ps *data);
void		reverse_rotate_b(t_ps *data);
void		reverse_rotate_a_and_b(t_ps *data);

#endif
