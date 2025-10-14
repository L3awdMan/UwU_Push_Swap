/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   UwU.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zotaj-di <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 16:54:35 by zotaj-di          #+#    #+#             */
/*   Updated: 2025/09/18 22:36:52 by zotaj-di         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Color definitions
#define RESET "\033[0m"
#define PINK "\033[95m"
#define VIOLET "\033[94m"
#define YELLOW "\033[93m"
#define BLUE "\033[96m"
#define GREEN "\033[92m"
#define RED "\033[91m"
#define BOLD "\033[1m"

// Function to count operations in the list
int	count_operations(t_list *op_list)
{
	int		count;
	t_list	*current;

	count = 0;
	current = op_list;
	while (current)
	{
		count++;
		current = (*current).next;
	}
	return (count);
}

// Function to print stack contents with better formatting
void	print_stack_content(t_stack *stack, char *color)
{
	int i, count;
	printf("%s", color);
	if (ft_current_size(stack) > 0)
	{
		i = (*stack).top;
		count = ft_current_size(stack);
		while (count-- > 0)
		{
			printf("%d", (*stack).array[i]);
			if (count > 0)
				printf(" ");
			i = ft_next_down(stack, i);
		}
	}
	else
	{
		printf("empty");
	}
	printf(RESET);
}

// Function to print both stacks with nice formatting
void	print_stacks(t_ps *data)
{
	printf("\n%s┌──────────────────────────────┐%s\n", VIOLET, RESET);
	printf("%s│         STACK STATE          │%s\n", VIOLET, RESET);
	printf("%s└──────────────────────────────┘%s\n", VIOLET, RESET);
	printf("  %sStack A:%s [", YELLOW, RESET);
	print_stack_content(&(*data).stack_a, BLUE);
	printf("]\n");
	printf("  %sStack B:%s [", YELLOW, RESET);
	print_stack_content(&(*data).stack_b, PINK);
	printf("]\n\n");
}

// Print separator line
void	print_separator(void)
{
	printf("%s════════════════════════════════════════%s\n", VIOLET, RESET);
}

// Helper function to run test with given arguments
void	run_test(char *test_name, int argc, char **argv, char *expected)
{
	t_ps	data;
	int		op_count;

	print_separator();
	printf("\n%s%s📊 %s %s%s\n", BOLD, PINK, test_name, RESET, RESET);
	printf("%sInput:%s", YELLOW, RESET);
	for (int i = 1; i < argc; i++)
		printf(" %s", argv[i]);
	printf("\n");
	// Initialize data
	ft_init_data(&data, argc, argv, true);
	printf("\n%sBefore sorting:%s", VIOLET, RESET);
	print_stacks(&data);
	// Sort
	sort(&data);
	// Count operations
	op_count = count_operations(data.opr_list);
	printf("%sAfter sorting:%s", VIOLET, RESET);
	print_stacks(&data);
	// Check if sorted
	if (ft_is_sorted(&data))
		printf("%s✓ Stack is sorted correctly%s\n", GREEN, RESET);
	else
		printf("%s✗ Stack is NOT sorted correctly%s\n", RED, RESET);
	printf("%sOperations count: %s%d%s\n", YELLOW, BOLD, op_count, RESET);
	if (expected)
		printf("%sExpected: %s%s\n", BLUE, expected, RESET);
	printf("\n");
	// Clean up
	ft_free_data(&data);
}

// Test case 1: Already sorted
void	test_already_sorted(void)
{
	char	*argv[] = {"tester", "1", "2", "3", "4", "5", NULL};

	run_test("Already Sorted", 6, argv, "0 operations");
}

// Test case 2: Reverse sorted
void	test_reverse_sorted(void)
{
	char	*argv[] = {"tester", "5", "4", "3", "2", "1", NULL};

	run_test("Reverse Sorted", 6, argv, "~8 operations");
}

// Test case 3: Three elements
void	test_three_elements(void)
{
	char	*argv[] = {"tester", "3", "1", "2", NULL};

	run_test("Three Elements", 4, argv, "≤3 operations");
}

// Test case 4: Five elements
void	test_five_elements(void)
{
	char	*argv[] = {"tester", "5", "2", "1", "4", "3", NULL};

	run_test("Five Elements", 6, argv, "≤12 operations");
}

// Test case 5: Random small set
void	test_random_small(void)
{
	char	*argv[] = {"tester", "7", "2", "9", "1", "5", "3", "8", "4", "6",
			NULL};

	run_test("Random Small Set", 10, argv, "<50 operations");
}

// Test case 6: Single element
void	test_single_element(void)
{
	char	*argv[] = {"tester", "42", NULL};

	run_test("Single Element", 2, argv, "0 operations");
}

// Test case 7: Two elements
void	test_two_elements(void)
{
	char	*argv[] = {"tester", "2", "1", NULL};

	run_test("Two Elements", 3, argv, "1 operation (sa)");
}

// Test random numbers
void	test_random(int size)
{
	char	**argv;
	int		*numbers;
	int		used[size * 10];
	int		used_count;
	char	expected[50];
	int		num;
	int		is_unique;
	t_ps	data;
	clock_t	start;
	clock_t	end;
	double	time_taken;
	int		op_count;

	int i, j;
	used_count = 0;
	print_separator();
	printf("\n%s%s🎲 Random %d Elements Test %s%s\n", BOLD, PINK, size, RESET,
		RESET);
	// Generate unique random numbers
	numbers = malloc(size * sizeof(int));
	argv = malloc((size + 2) * sizeof(char *));
	srand(time(NULL) + size); // Add size to seed for variety
	for (i = 0; i < size; i++)
	{
		do
		{
			num = (rand() % (size * 10)) - (size * 5);
			is_unique = 1;
			for (j = 0; j < used_count; j++)
			{
				if (used[j] == num)
				{
					is_unique = 0;
					break ;
				}
			}
		} while (!is_unique);
		used[used_count++] = num;
		numbers[i] = num;
	}
	// Create argv
	argv[0] = "tester";
	for (i = 0; i < size; i++)
	{
		argv[i + 1] = malloc(12);
		snprintf(argv[i + 1], 12, "%d", numbers[i]);
	}
	argv[size + 1] = NULL;
	// Print sample of numbers
	printf("%sInput:%s", YELLOW, RESET);
	for (i = 0; i < size && i < 10; i++)
		printf(" %d", numbers[i]);
	if (size > 10)
		printf(" ... (%d more)", size - 10);
	printf("\n");
	// Set expected operations
	if (size == 3)
		snprintf(expected, sizeof(expected), "≤3 operations");
	else if (size == 5)
		snprintf(expected, sizeof(expected), "≤12 operations");
	else if (size == 100)
		snprintf(expected, sizeof(expected), "<700 operations");
	else if (size == 500)
		snprintf(expected, sizeof(expected), "<5500 operations");
	else
		snprintf(expected, sizeof(expected), "varies");
	// Run test
	ft_init_data(&data, size + 1, argv, true);
	printf("\n%sBefore sorting:%s", VIOLET, RESET);
	printf("\n  %sStack A:%s %d elements", YELLOW, RESET, size);
	printf("\n  %sStack B:%s empty\n\n", YELLOW, RESET);
	start = clock();
	sort(&data);
	end = clock();
	time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
	op_count = count_operations(data.opr_list);
	printf("%sAfter sorting:%s", VIOLET, RESET);
	printf("\n  %sStack A:%s %d elements (sorted)", YELLOW, RESET, size);
	printf("\n  %sStack B:%s empty\n\n", YELLOW, RESET);
	// Check if sorted
	if (ft_is_sorted(&data))
		printf("%s✓ Stack is sorted correctly%s\n", GREEN, RESET);
	else
		printf("%s✗ Stack is NOT sorted correctly%s\n", RED, RESET);
	printf("%sOperations count: %s%d%s\n", YELLOW, BOLD, op_count, RESET);
	printf("%sExpected: %s%s%s\n", BLUE, RESET, expected, RESET);
	printf("%sTime: %s%.4f seconds%s\n\n", VIOLET, RESET, time_taken, RESET);
	// Clean up
	ft_free_data(&data);
	for (i = 1; i <= size; i++)
		free(argv[i]);
	free(argv);
	free(numbers);
}

void	print_menu(void)
{
	printf("\n%s╔════════════════════════════════════╗%s\n", PINK, RESET);
	printf("%s║   UwU PUSH_SWAP TESTER ₍^. .^₎⟆    ║%s\n", PINK, RESET);
	printf("%s╚════════════════════════════════════╝%s\n\n", PINK, RESET);
	printf("%s[1]%s  Already sorted (1,2,3,4,5)\n", YELLOW, RESET);
	printf("%s[2]%s  Reverse sorted (5,4,3,2,1)\n", YELLOW, RESET);
	printf("%s[3]%s  Three elements (3,1,2)\n", YELLOW, RESET);
	printf("%s[4]%s  Five elements (5,2,1,4,3)\n", YELLOW, RESET);
	printf("%s[5]%s  Random small set (9 elements)\n", YELLOW, RESET);
	printf("%s[6]%s  Single element (42)\n", YELLOW, RESET);
	printf("%s[7]%s  Two elements (2,1)\n", YELLOW, RESET);
	printf("%s[8]%s  Random 10 elements\n", BLUE, RESET);
	printf("%s[9]%s  Random 100 elements\n", BLUE, RESET);
	printf("%s[10]%s Random 500 elements\n", BLUE, RESET);
	printf("%s[0]%s  Exit\n", VIOLET, RESET);
	printf("\n%sChoose option:%s ", PINK, RESET);
}

int	main(int argc, char **argv)
{
	int	choice;

	// If arguments provided, use them directly
	if (argc > 1)
	{
		run_test("Command Line Test", argc, argv, NULL);
		return (0);
	}
	printf("\n%s%s✨ Welcome to my UwU Push_Swap Tester! (〃✨ ω ✨〃)ゞ %s\n", BOLD,
		PINK, RESET);
	while (1)
	{
		print_menu();
		if (scanf("%d", &choice) != 1)
		{
			printf("%sInvalid input. Goodbye!%s\n", RED, RESET);
			break ;
		}
		switch (choice)
		{
		case 0:
			printf("\n%s👋 ヾ(￣▽￣) Bye~Bye~ 👋%s\n\n", VIOLET, RESET);
			return (0);
		case 1:
			test_already_sorted();
			break ;
		case 2:
			test_reverse_sorted();
			break ;
		case 3:
			test_three_elements();
			break ;
		case 4:
			test_five_elements();
			break ;
		case 5:
			test_random_small();
			break ;
		case 6:
			test_single_element();
			break ;
		case 7:
			test_two_elements();
			break ;
		case 8:
			test_random(10);
			break ;
		case 9:
			test_random(100);
			break ;
		case 10:
			test_random(500);
			break ;
		default:
			printf("%sInvalid option!%s\n", RED, RESET);
		}
	}
	return (0);
}
