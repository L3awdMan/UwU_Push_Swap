/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_management.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zotaj-di <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 16:31:09 by zotaj-di          #+#    #+#             */
/*   Updated: 2025/09/30 18:47:36 by zotaj-di         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

/* `ft_init_stack` allocate and initialize `t_stack` ` */

// ----------- Params : ---------------------------------------------------
// data -> (type t_ps)master struct (for error handling)
// stack -> (type t_stack) pointer to the stack to
// size -> (type int) number of elements the stack must hold

// ----------- Steps : ---------------------------------------------------
//     - allocate an int array of length size, assign to stk->array
//     - if allocation fails, call `ft_error(data)`
//     - set stack->top = 0
//     - set stack->bottom = 0
//     - set stack->size = size

/* `ft_init_data` set up stack A/B and operation list,
	then fill stack A with the provided numbers */

// ----------- Params : ---------------------------------------------------
// data -> (type t_ps *) Holds stack A/B and setting ,
//      # fill and prepare it in this fucntion
// ac -> argc
// av -> argv
// record_opr -> (type bool) record operations into `*opr_list`
//       # TRUE: record the operations like pa, pb ...
//       # FALSE: operations happen but are not saved

// ----------- Setup : ---------------------------------------------------
//     - decrement argc to ignore program name
//     - call init_stack(data, &data->stack_a, argc)
//     - call init_stack(data, &data->stack_b, argc)
//     - call fill_stack(data, &data->stack_a, argc, argv + 1)
//     - set (*data).record_opr to record_opr
//     - set (*data).opr_list to NULL

/* `ft_is_sorted` (type bool) return TRUE if stack A in order */

// ----------- Params : ---------------------------------------------------
// data -> (type t_ps_ctx) struct holding the entire program state

// ----------- Variables : ---------------------------------------------------
// i -> (type int) index of the array
// rank -> (type int) index to iterate through the loop

// ----------- Setup : ---------------------------------------------------
//    - i = data->stack_a.top
//    - for rank in 1 to data->stack_a.size
//       - if data->stack_a.array[i] != rank:
//          - return false
//       - i = next_down(&data->stack_a, i)
//    - return true

/* `ft_error` on fatal error clean up all memeory,
	print "Error" to stderr and exit */

// ----------- Params : ---------------------------------------------------
// data -> (type t_ps_ctx) struct holding the entire program state

// ----------- Setup : ---------------------------------------------------
//     - call free_all(data)
//     - print "Error" to file descriptor 2
//     - exit(EXIT_FAILURE)

/* `ft_free_all` free both stacks, arrays and the operations list*/

// ----------- Params : ---------------------------------------------------
// data -> (type t_ps_ctx) struct holding the entire program state

// ----------- Setup : ---------------------------------------------------
//     - if data->stack_a.array != NULL, free it
//     - if data->stack_b.array != NULL, free it
//     - if data->op_list != NULL, clear the list with ft_lstclear
//      ( ft_lstclear(&data->op_list, NULL) )
void	ft_init_stack(t_ps *data, t_stack *stack, int size)
{
	(*stack).array = ft_calloc(sizeof(int), size);
	if (!((*stack).array))
		ft_error(data);
	(*stack).top = 0;
	(*stack).bottom = 0;
	(*stack).size = size;
}

void	ft_init_data(t_ps *data, int ac, char **av, bool record_opr)
{
	(*data).stack_a.array = NULL;
	(*data).stack_b.array = NULL;
	(*data).opr_list = NULL;
	(*data).record_opr = record_opr;
	ac--;
	ft_init_stack(data, &((*data).stack_a), ac);
	ft_init_stack(data, &((*data).stack_b), ac);
	ft_fill_stack(data, &((*data).stack_a), ac, av + 1);
	(*data).record_opr = record_opr;
	(*data).opr_list = NULL;
}

bool	ft_is_sorted(t_ps *data)
{
	int	i;
	int	rank;

	i = (*data).stack_a.top;
	rank = 1;
	while (rank <= (*data).stack_a.size)
	{
		if ((*data).stack_a.array[i] != rank)
			return (false);
		i = ft_next_down(&((*data).stack_a), i);
		rank++;
	}
	return (true);
}

void	ft_free_data(t_ps *data)
{
	if ((*data).stack_a.array != NULL)
	{
		free((*data).stack_a.array);
		(*data).stack_a.array = NULL;
	}
	if ((*data).stack_b.array != NULL)
	{
		free((*data).stack_b.array);
		(*data).stack_b.array = NULL;
	}
	if ((*data).opr_list != NULL)
		ft_lstclear(&(*data).opr_list, NULL);
}

void	ft_error(t_ps *data)
{
	ft_free_data(data);
	ft_putendl_fd("error", 2);
	exit(EXIT_FAILURE);
}
