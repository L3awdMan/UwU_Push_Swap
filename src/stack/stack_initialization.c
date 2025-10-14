/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_initialization.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zotaj-di <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 23:15:29 by zotaj-di          #+#    #+#             */
/*   Updated: 2025/09/30 18:43:03 by zotaj-di         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

void	ft_fill_stack(t_ps *data, t_stack *stack, int size, char **av)
{
	int	*numbers;
	int	i;

	numbers = ft_calloc(size, sizeof(int));
	if (!numbers)
		ft_error(data);
	i = 0;
	while (av[i])
	{
		if (!ft_valid_arg(av[i]))
		{
			free(numbers);
			ft_error(data);
		}
		numbers[i] = ft_atoi(av[i]);
		i++;
	}
	ft_check_duplicates(data, numbers, size);
	ft_ranking_num(numbers, (*stack).array, size);
	(*stack).bottom = size - 1;
	free(numbers);
}

bool	ft_valid_arg(char *av)
{
	long long int	res;
	int				sign;

	if (*av == '\0')
		return (false);
	sign = 1;
	if (*av == '-' || *av == '+')
	{
		if (*av == '-')
			sign *= -1;
		av++;
		if (*av == '\0')
			return (false);
	}
	res = 0;
	while (*av)
	{
		if (!ft_isdigit(*av))
			return (false);
		res = res * 10 + (*av - '0');
		if ((sign == 1 && res > INT_MAX) || (sign == -1 && -res < INT_MIN))
			return (false);
		av++;
	}
	return (true);
}

void	ft_check_duplicates(t_ps *data, int *numbers, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (numbers[i] == numbers[j])
			{
				free(numbers);
				ft_error(data);
			}
			j++;
		}
		i++;
	}
}

void	ft_ranking_num(int *numbers, int *rank, int size)
{
	int	i;
	int	j;
	int	rank_counter;

	i = 0;
	while (i < size)
	{
		j = 0;
		rank_counter = 0;
		while (j < size)
		{
			if (numbers[j] <= numbers[i])
				rank_counter++;
			j++;
		}
		rank[i] = rank_counter;
		i++;
	}
}

/* `ft_fill_stack` fills the stack after validates it */
//     # converts to integers
//     # checks for duplicates
//     # ranks the numbers

// ----------- Params : ---------------------------------------------------
// data -> (type t_ps_ctx) struct holding the entire program state
// stack -> (type t_stack) pointer to stack to be filled either stack A or B
// size -> (type int) number of values to proceess
// av -> argument vector `int **argv`

// ----------- Variables : ---------------------------------------------------
// numbers -> (type int *) temporary array holds integer values from `av`
//      # used to check for duplicates and asign ranks later
// index i -> (type int)

// ----------- Steps : ---------------------------------------------------
//       # allocate memory for int `numbers` of `size` elements
//       # loop over each argument :
//       #  - check sign, digits, range `ft_valid_arg` if FALSE `ft_error(data)`
//       #  - convert it with `ft_atoi`
//       #  - store in number[i]
//       # check that there's no duplicates `ft_check_duplicates`
//       # convert numbers to ranks `ft_numbers_rank`
//       # fill `stack` with those ranks (*stack).numbers
//       #   - set the `bottom` to the `size - 1`
//       # free the numbers array

/* `ft_valid_arg` (type bool) check string countains only digits */
//       # check if the string is a valid signed int
//       # must contain only digits and with one '+' or '-'
//       # must fit inside the INT_MAX/INT_MIN

// ----------- Params : ---------------------------------------------------
// av -> argument vector (int **argv)

// ----------- Variables : ---------------------------------------------------
// res -> (type long long) to restor the small convertion of the atoi
// sign -> (type int) check the sign of the num

// ----------- Steps : ---------------------------------------------------
//        # if the string is empty (`false`)
//        # if it starts with '+' or `-` store the sign then check if the av++
//          is empty or not
//        # initialize res to 0 then loop through all remaining characters :
//        # - if not a digit : return false
//        # - else, build the number in `res`
//        # - check for overflow
//        # if all checks pass: return true

/* `ft_check_duplicates` check if there are any duplicate numbers in the input
 * array */
//        # if any duplicate is found, clean up and exit

// ----------- Params : ---------------------------------------------------
// data -> (type t_ps_ctx) main program struct
// numbers -> (type int *) array of numbers to be checked
// size -> (type int) how many numbers are in teh array

// ----------- Variables : ---------------------------------------------------
// i -> (type int) index i used for the entier array
// j ->(type int)index j used to compare the specific number to the entier array
//
// ----------- Steps : ---------------------------------------------------
//        # loop through all the array until we arrive to size
//        # initialize j to i + 1;
//        # loop through the array[j] until u arrive at size
// if we found out a duplication([i] == [j]) we free array and `ft_error`
//        #

/* `ft_ranking_num` converts the array of actual numbers to their ranking
 *   value */

// ----------- Params : ---------------------------------------------------
// numbers -> (type int *) array of numbers given
// rank -> (type int *) array to store the rank (index wise)
// size -> (type int) number of elements in the array

// ----------- Variables : ---------------------------------------------------
// i -> (type int) index i used for the entier array
// j -> (type int) index j used to compare the specific number with the entier
//       array
// rank_counter-> (type int) a counter that tells how many numbers are less
//       than or equal current number
//
// ----------- Steps : ---------------------------------------------------
//         # loop through all the array until we arrive to size ( i < size )
//         # - initialize rank_counter and j index to 0
//         # - loop through every other numbers[j]  :
//         #    - if numbers[j] <= numbers [i] :
//         #       - rank_counter++
//         # - set rank[i] to rank_counter
