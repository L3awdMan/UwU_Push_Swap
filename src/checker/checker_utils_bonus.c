/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zotaj-di <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 19:42:37 by zotaj-di          #+#    #+#             */
/*   Updated: 2025/09/30 18:57:33 by zotaj-di         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

/******************************************************************************
 * This file, `checker_utils_bonus.c`, contains the essential helper          *
 * functions for the `checker` program. Its main responsibility is to handle  *
 * the "read and execute" loop. It provides functions to safely read one      *
 * operation at a time from standard input, parse the text of that            *
 * operation into a format the program can understand (an enum), execute      *
 * the corresponding stack manipulation, and handle any errors that occur     *
 * during this process. It's the engine that drives the checker's logic.      *
 *****************************************************************************/

/* `error_read_op` (void) - A specialized error function called when an
 * invalid operation is read from the input. */

//--------- Params of the function : -----------------------------------------
// data -> (t_ps *) A pointer to the main program structure. It's needed so
//         this function can call the main `error` function, which handles
//         freeing the stacks.
// line -> (char *) The pointer to the heap-allocated string that holds the
//         invalid line read from the input.

//----- Context & Purpose : --------------------------------------------------
// In main checker loop, i will allocate memory for a `line` to read
// an operation. If that operation turns out to be invalid (e.g., "hello"),
// you need to exit, but you must also free the memory for `line` to prevent
// leaks. This function centralizes that action: it frees the line, then
// calls the main error handler to free everything else and exit.

//--------- variables inside the function : ----------------------------------
//                       (No internal variables)

//--------- Setup to follow for implementation : -----------------------------
// - Check if the `line` pointer is not NULL.
// - If it is not NULL, free it using `free(line)`.
// - Call your main `error(data)` function, which should handle freeing the
//   stacks and exiting the program with an error status.

/* `push_swap_gnl` (int) - Reads a single line of input, tailored
 * specifically for push_swap operations.*/

//--------- Params of the function : -----------------------------------------
// fd   -> (int) The file descriptor to read from. For the checker, this
//         will always be `0` (standard input).
// line -> (char *) A pre-allocated buffer where the read line will be
//         stored. The function assumes this buffer is large enough (5 bytes
//         is safe: `rrr\n\0`).

//----- Context & Purpose : --------------------------------------------------
// This is a highly simplified and specialized version of `get_next_line`.
// Its only job is to read one potential operation from standard input. It
// reads character by character until it finds a newline (`\n`). It includes
// strict validation to immediately fail if the input line is too long
// (e.g., "swap\n") or doesn't follow the expected format, which makes the
// main loop cleaner.

//--------- variables inside the function : ----------------------------------
// i           -> (int) A counter for the current position in the `line` buffer.
// read_status -> (int) Stores the return value of the `read` system call to
//                check for errors (`-1`) or end-of-file (`0`).
// buffer -> (char) A tiny, 1-byte buffer to hold each character as it's
//                read from the input.

//--------- Setup to follow for implementation : -----------------------------
// - Initialize `i` to 0.
// - Start a `while` loop that will continue as long as `buffer` is not
//		`\n`
// - Inside the loop:
//   - Call `read(fd, &buffer, 1)` and store its return in `read_status`.
//   - If `read_status` is -1 (error), return `EXIT_FAILURE`.
//   - If `read_status` is 0 (end of input), break the loop.
//   - Store the read character in `line[i++]`.
//   - **Validation**: Check if `i` is now greater than 4. The longest valid
//     operation is 3 chars + `\n` (4 bytes total). If it's more, the
//     operation is invalid. Return `EXIT_FAILURE`.
// - After the loop, perform final checks:
//   - If an empty line was entered (`line[0] == '\n'`), it's an error.
//     Return `EXIT_FAILURE`.
//   - If characters were read but the last one wasn't a newline (e.g., the
//     input ended without one), it's also an error. Return `EXIT_FAILURE`.
// - If `read_status` was 0 (end of file), set `line[0] = '\0'` to indicate
//   there's nothing left to process.
// - Otherwise, replace the newline character at `line[i - 1]` with a null
//   terminator `\0` to create a valid C-string.
// - Return `EXIT_SUCCESS`.

/* `string_to_opr` (t_opr) - Converts a string (e.g., "ra") into its
 * corresponding machine-readable enum value (e.g., `ra`).*/

//--------- Params of the function : -----------------------------------------
// str -> (const char *) The null-terminated string containing the operation.

//----- Context & Purpose : --------------------------------------------------
// It's much more efficient and safer to work with integers or enums than
// with strings. This function acts as a parser. It takes the text read from
// the input and translates it into a unique `t_opr` enum value. This allows the
// next function, `call_opr`, to easily determine which action to perform.

//--------- variables inside the function : ----------------------------------
//                       (No internal variables)

//--------- Setup to follow for implementation : -----------------------------
//
// - Use a series of `if/else if` statements.
// - For each possible valid operation, compare the input `str` using
//   `ft_strcmp`.
//   - `if (!ft_strcmp(str, "pa")) return (pa);`
//   - `else if (!ft_strcmp(str, "rra")) return (rra);`
//   - ... and so on for all 11 operations (`pa`, `pb`, `sa`, `sb`, `ss`,
//     `ra`, `rb`, `rr`, `rra`, `rrb`, `rrr`).
// - If none of the comparisons match, have a final `else` block that returns
//   an "invalid" enum value, like `null_op`, to signify an error.

/* `call_op` (void) - Takes an operation enum and executes the corresponding
 * stack manipulation function.*/

//--------- Params of the function : -----------------------------------------
// data -> (t_ps *) The main data structure containing the stacks.
// op   -> (t_opr) The enum value representing the operation to execute, as
//         determined by `string_to_op`.

//----- Context & Purpose : --------------------------------------------------
// This function is the "dispatcher". After `string_to_op` has figured out
// *what* the user wants to do, `call_op` is the function that *does* it. It
// takes the enum and, based on its value, calls the appropriate function
// (`push_a`, `rotate_b`, etc.) to modify the stacks.

//--------- variables inside the function : ----------------------------------
//                      (No internal variables)

//--------- Setup to follow for implementation : -----------------------------
// - Use another series of `if/else if` statements, this time checking the
//   value of the `op` enum.
//   - `if (op == pa) push_a(data);`
//   - `else if (op == rra) r_rotate_a(data);`
// Note: use non-printing versions
//   - ... and so on for all 11 valid operations.
// - The final `else` case will catch the `null_op` value from the previous
//   function. If the operation is invalid, you should immediately call your
//   main `ft_error(data)` function to stop the program.

void	error_reading_opr(t_ps *data, char *line)
{
	if (!line)
	{
		free(line);
		ft_error(data);
	}
}

int	push_swap_gnl(int fd, char *line)
{
	int		i;
	int		read_status;
	char	buffer;

	i = 0;
	buffer = ' ';
	while (buffer != '\n')
	{
		read_status = read(fd, &buffer, 1);
		if (read_status == -1)
			return (EXIT_FAILURE);
		if (read_status == 0)
			break ;
		line[i++] = buffer;
		if (i > 4)
			return (EXIT_FAILURE);
	}
	if (line[0] == '\n' || (line[i - 1] != '\n' && i < 0))
		return (EXIT_FAILURE);
	if (read_status == 0)
		line[0] = '\0';
	else
		line[i - 1] = '\0';
	return (EXIT_SUCCESS);
}

t_opr	string_to_opr(const char *str)
{
	if (!ft_strcmp(str, "pa"))
		return (pa);
	else if (!ft_strcmp(str, "pb"))
		return (pb);
	else if (!ft_strcmp(str, "sa"))
		return (sa);
	else if (!ft_strcmp(str, "sb"))
		return (sb);
	else if (!ft_strcmp(str, "ss"))
		return (ss);
	else if (!ft_strcmp(str, "ra"))
		return (ra);
	else if (!ft_strcmp(str, "rb"))
		return (rb);
	else if (!ft_strcmp(str, "rr"))
		return (rr);
	else if (!ft_strcmp(str, "rra"))
		return (rra);
	else if (!ft_strcmp(str, "rrb"))
		return (rrb);
	else if (!ft_strcmp(str, "rrr"))
		return (rrr);
	else
		return (null_opr);
}

void	call_opr(t_ps *data, t_opr opr)
{
	if (opr == pa)
		push_to_a(data);
	else if (opr == pb)
		push_to_b(data);
	else if (opr == sa)
		swap_a(data);
	else if (opr == sb)
		swap_b(data);
	else if (opr == ss)
		swap_a_and_b(data);
	else if (opr == ra)
		rotate_a(data);
	else if (opr == rb)
		rotate_b(data);
	else if (opr == rr)
		rotate_a_and_b(data);
	else if (opr == rra)
		reverse_rotate_a(data);
	else if (opr == rrb)
		reverse_rotate_b(data);
	else if (opr == rrr)
		reverse_rotate_a_and_b(data);
	else
		ft_error(data);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i] && (s1[i] == s2[i]))
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
