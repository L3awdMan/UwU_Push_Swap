/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zotaj-di <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 14:26:48 by zotaj-di          #+#    #+#             */
/*   Updated: 2025/05/12 14:49:04 by zotaj-di         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*    allocating specific amount of memroy to each block (that contain 0)   */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*array;

	array = (void *)malloc(nmemb * size);
	if (!array)
		return (NULL);
	ft_bzero(array, (nmemb * size));
	return (array);
}
/*
int	compare_with_std(size_t nmemb, size_t size)
{
	void	*std_ptr;
	void	*my_ptr;
	int		result;

	std_ptr = calloc(nmemb, size);
	my_ptr = ft_calloc(nmemb, size);
	if (!std_ptr && !my_ptr)
		return (1);
	if (!std_ptr || !my_ptr)
		return (0);
	result = memcmp(std_ptr, my_ptr, nmemb * size) == 0;
	free(std_ptr);
	free(my_ptr);
	return (result);
}

int	main(void)
{
	int	*arr;

	printf("=== Testing ft_calloc ===\n");
	// Test 1: Normal int allocation
	if (compare_with_std(5, sizeof(int)))
		printf("✅ Test 1: int array passed\n");
	else
		printf("❌ Test 1: int array failed\n");
	// Test 2: Normal char allocation
	if (compare_with_std(12, sizeof(char)))
		printf("✅ Test 2: char array passed\n");
	else
		printf("❌ Test 2: char array failed\n");
	// Test 3: Zero elements
	if (compare_with_std(0, sizeof(int)))
		printf("✅ Test 3: zero nmemb passed\n");
	else
		printf("❌ Test 3: zero nmemb failed\n");
	// Test 4: Zero size
	if (compare_with_std(10, 0))
		printf("✅ Test 4: zero size passed\n");
	else
		printf("❌ Test 4: zero size failed\n");
	// Test 5: Manually check if memory is zeroed
	arr = (int *)ft_calloc(4, sizeof(int));
	if (arr && arr[0] == 0 && arr[1] == 0 && arr[2] == 0 && arr[3] == 0)
		printf("✅ Test 5: memory is zeroed passed\n");
	else
		printf("❌ Test 5: memory is zeroed failed\n");
	free(arr);
	printf("=== Done ===\n");
	return (0);
}*/
