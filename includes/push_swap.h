/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zotaj-di <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 15:57:34 by zotaj-di          #+#    #+#             */
/*   Updated: 2025/09/11 18:37:16 by zotaj-di         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "stack.h"

typedef enum e_location
{
	TOP_A,
	BOTTOM_A,
	TOP_B,
	BOTTOM_B,
}				t_location;

typedef struct s_chunk
{
	t_location	loc;
	int			size;
}				t_chunk;

typedef struct s_split
{
	t_chunk		min;
	t_chunk		mid;
	t_chunk		max;
}				t_split;

// move files ( need better comment )
int				move_from_to(t_ps *data, t_location from, t_location to);
void			move_from_top_a(t_ps *data, t_location to);
void			move_from_top_b(t_ps *data, t_location to);
void			move_from_bottom_a(t_ps *data, t_location to);
void			move_from_bottom_b(t_ps *data, t_location to);

// sort files, efficient sort for small stack <= 5
void			sort(t_ps *data);
void			sort_three_a(t_ps *data);
void			sort_five_a(t_ps *data);

// chunk utils
t_stack			*location_to_stack(t_ps *data, t_location loc);
int				ft_chunk_value(t_ps *data, t_chunk *chunk, int n);
int				chunk_max_value(t_ps *data, t_chunk *chunk);

// chunk sort functions
void			chunk_sort(t_ps *data);
void			rec_chunk_sort(t_ps *data, t_chunk *to_sort);
void			sort_one(t_ps *data, t_chunk *to_sort);
void			sort_two(t_ps *data, t_chunk *to_sort);

// chunk split functions
void			chunk_split(t_ps *data, t_chunk *to_split, t_split *dest);
void			init_size(t_chunk *min, t_chunk *mid, t_chunk *max);
void			set_split_loc(t_location loc, t_chunk *min, t_chunk *mid,
					t_chunk *max);
void			set_third_pivots(t_location loc, int current_size, int *pivot_1,
					int *pivot_2);

// optimize three sort
void			sort_three(t_ps *data, t_chunk *to_sort);
void			sort_three_top_a(t_ps *data, t_chunk *to_sort, t_stack *stack,
					int max);
void			sort_three_top_b(t_ps *data, t_chunk *to_sort, t_stack *stack,
					int max);
void			sort_three_bottom_a(t_ps *data, t_chunk *to_sort,
					t_stack *stack, int max);
void			sort_three_bottom_b(t_ps *data, t_chunk *to_sort,
					t_stack *stack, int max);

// UTILS : post sort
t_opr			neutral_opr(t_opr opr);
bool			opr_on_same_stack(t_opr ref, t_opr to_check);
t_opr			child_opr(t_opr first, t_opr second);

// optimize post sort
void			post_sort_optimization(t_ps *data);
void			eliminate_neutral_opr(t_list *opr_list);
void			merge_opr(t_list *opr_list);
void			remove_opr(t_list *to_delete);

// optimize easy sort
void			easy_sort(t_ps *data, t_chunk *to_sort);
void			easy_sort_second(t_ps *data, t_chunk *to_sort);
void			handle_top_b(t_ps *data, t_chunk *to_sort);
void			handle_bottom_a(t_ps *data, t_chunk *to_sort);
void			handle_bottom_b(t_ps *data, t_chunk *to_sort);

// opti SORT ASAP
void			split_max_reduction(t_ps *data, t_chunk *max);
bool			a_partly_sort(t_ps *data, int from);
bool			is_consecutive(int a, int b, int c, int d);
void			sort_three_numbers(int *a, int *b, int *c);

// TO THE TOP
void			chunk_to_the_top(t_ps *data, t_chunk *to_sort);
#endif
