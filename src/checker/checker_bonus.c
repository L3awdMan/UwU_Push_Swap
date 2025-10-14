/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zotaj-di <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 16:37:35 by zotaj-di          #+#    #+#             */
/*   Updated: 2025/09/30 18:57:28 by zotaj-di         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

/*******************************************************************************
 * This file, `checker_bonus.c`, is the main entry point for the bonus part    *
 * of the project. Its purpose is to validate a sequence of sorting            *
 * operations. It starts by setting up the initial state of the stacks based on*
 * command-line arguments. Then, it reads a series of operations from          *
 * standard input, applies them one by one to the stacks, and in the end,      *
 * determines if stack A is correctly sorted. It's the "referee" that          *
 * checks if a given solution is correct.                                      *
 *****************************************************************************/

/* `main` (int) - The main entry point that orchestrates the entire checker
 * program flow.*/

//--------- Params of the function : -----------------------------------------
// argc -> (int) The count of command-line arguments.
// argv -> (char *[]) An array of strings containing the program name and
//         the numbers for the stack.

//----- Context & Purpose : --------------------------------------------------
// This is the main function . It initializes everything, kicks off
// the process of reading and executing instructions, makes the final judgment
// call, and handles cleanup. It defines the high-level logic:
// Setup -> Read -> Execute & Test -> Report -> Clean Up.

//--------- variables inside the function : ----------------------------------
// data -> (t_ps) The main structure that holds all the program's state,
//         including both stacks (a and b) and the list of operations.

//--------- Setup to follow for implementation : -----------------------------
//
// 1. Declare the main data structure: `t_ps data;`.
// 2. Initialize the stacks by calling `init_data(&data, argc, argv, false)`.
//    This function should parse the numbers from `argv` and populate stack A.
//    The `false` argument might indicate it's the checker, not the sorter.
// 3. Handle the edge case where no numbers are given (`data.a.size == 0`).
//    If so, the program should exit successfully without doing anything.
// 4. Call `read_op(&data)` to read all the instructions from standard input
//    and store them in a linked list inside the `data` struct.
// 5. Call `test_sort(&data)`. This function will execute the stored
//    instructions and return `true` if the stack is sorted, `false` otherwise.
// 6. Based on the return value of `test_sort`, print "OK\n" for success or
//    "KO\n" for failure.
// 7. Call `free_data(&data)` to release all allocated memory (the stacks
//    and the operation list).
// 8. Exit the program with `exit(EXIT_SUCCESS)`.

/* `reading_opr` (void) - Reads operations from standard input until the end of
 * input and stores them in a linked list. */

//--------- Params of the function : -----------------------------------------
// data -> (t_ps *) A pointer to the main data structure where the list of
//         operations will be stored.

//----- Context & Purpose : --------------------------------------------------
// This function's job is to listen. It reads every line from standard input,
// assuming each line is an operation (like "ra\n"). For each line, it
// translates the text into an `t_op` enum and adds it to a list. This
// pre-loading step separates the reading phase from the execution phase.

//--------- variables inside the function : ----------------------------------
// new_list    -> (t_list *) A temporary pointer to hold a newly created node
//                for the operations list.
// gnl_status  -> (int) Stores the return value from `push_swap_gnl` to
//                check for read errors.
// line        -> (char *) A buffer to store each line as it's read from the
//                input.
// line_status -> (int) Stores the length of the `line`. Used to detect the
//                end of input (an empty read).

//--------- Setup to follow for implementation : -----------------------------
//
// 1. Allocate memory for the `line` buffer. A size of 5 is safe for any
//    operation (e.g., "rrr\n\0"). Handle allocation failure.
// 2. Start a `while (1)` or `while (line_status)` loop to continuously read.
// 3. Inside the loop, call `push_swap_get_next_line(0, line)` to read
//    from stdin.
// 4. If `push_swap_gnl` returns an error, call your error handler.
// 5. Check the length of the read line (`line_status = ft_strlen(line)`). If
//    it's 0, it means the end of input has been reached, so `break` the loop.
// 6. If the line is not empty:
//    a. Translate the `line` into an enum using `string_to_opr(line)`.
//    b. Create a new linked list node with this enum as its content using
//       `ft_lstnew()`. Handle allocation failure.
//    c. Add this `new` node to the end of your operation list in the `data`
//       struct (`ft_lstadd_back(&data->opr_list, new)`).
// 7. After the loop finishes, `free(line)` to prevent memory leaks.

/* `check_sorting` (bool) - Executes all stored operations and then checks if
 * stack A is sorted correctly.
 */

//--------- Params of the function : -----------------------------------------
//
// data -> (t_ps *) A pointer to the main data structure, which contains the
//         stacks and the list of operations to execute.

//----- Context & Purpose : --------------------------------------------------
//
// This is the action and judgment phase. It takes the list of instructions
// collected by `reading_opr` and executes them one by one. After running
// through all the instructions, it performs the final check: is stack A sorted
// and is stack B empty?

//--------- variables inside the function : ----------------------------------
//
// reader -> (t_list *) A pointer used to iterate through the operations list,
//           node by node.

//--------- Setup to follow for implementation : -----------------------------
//
// 1. Initialize an iterator `reader` to the start of the operations list:
//    `reader = data->opr_list;`.
// 2. Start a `while (reader)` loop to traverse the entire list.
// 3. Inside the loop:
//    a. Get the operation enum from the current node's content. You'll need
//       to cast the `void *` content back to the `t_opr` enum type.
//    b. Execute the operation by calling `call_opr(data, current_op)`.
//    c. Move to the next instruction: `reader = reader->next;`.
// 4. After the loop, the final state of the stacks has been reached. Return
//    the result of a compound boolean check:
//    - `ft_is_full(&data->stack_a)`: Is stack B empty?
//    - `ft_is_sorted(data)`: Are the numbers in stack A in ascending order?
//    - The function should return `true` only if **both** conditions are met.

int	main(int ac, char **av)
{
	t_ps	data;

	ft_init_data(&data, ac, av, false);
	if (data.stack_a.size == 0)
		exit(EXIT_SUCCESS);
	reading_opr(&data);
	if (check_sorting(&data))
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	ft_free_data(&data);
	exit(EXIT_SUCCESS);
}

void	reading_opr(t_ps *data)
{
	t_list	*new_list;
	int		gnl_status;
	char	*line;
	int		line_status;

	gnl_status = 0;
	line_status = 1;
	line = ft_calloc(5, sizeof(char));
	while (1)
	{
		gnl_status = push_swap_gnl(0, line);
		if (gnl_status == EXIT_FAILURE)
			error_reading_opr(data, line);
		line_status = ft_strlen(line);
		if (line_status == 0)
			break ;
		new_list = ft_lstnew((void *)(uintptr_t)string_to_opr(line));
		if (!new_list)
			error_reading_opr(data, line);
		ft_lstadd_back(&(*data).opr_list, new_list);
	}
	free(line);
}

bool	check_sorting(t_ps *data)
{
	t_list	*reader;

	reader = (*data).opr_list;
	while (reader)
	{
		call_opr(data, (t_opr)(uintptr_t)(*reader).content);
		reader = (*reader).next;
	}
	return (ft_is_full(&(*data).stack_a) && ft_is_sorted(data));
}
