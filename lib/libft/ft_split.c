/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zotaj-di <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 14:07:19 by zotaj-di          #+#    #+#             */
/*   Updated: 2025/05/17 15:54:08 by zotaj-di         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**free_array(char **result, int i)
{
	while (i > 0)
	{
		i--;
		free(result[i]);
	}
	free(result);
	return (0);
}

static int	check_seperator(char c, char sep)
{
	return (c == sep);
}

static int	count_strings(const char *str, char sep)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		while (str[i] && check_seperator(str[i], sep))
			i++;
		if (str[i])
			count++;
		while (str[i] && !check_seperator(str[i], sep))
			i++;
	}
	return (count);
}

static char	*ft_word(const char *str, char sep)
{
	int		i;
	int		len_word;
	char	*word;

	len_word = 0;
	while (str[len_word] && !check_seperator(str[len_word], sep))
		len_word++;
	word = (char *)malloc(len_word + 1);
	if (!word)
		return (NULL);
	i = 0;
	while (i < len_word)
	{
		word[i] = str[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

char	**ft_split(const char *s, char c)
{
	int		i;
	int		size_strs;
	char	**result;

	size_strs = count_strings(s, c);
	result = (char **)malloc((size_strs + 1) * sizeof(char *));
	if (!result)
		return (NULL);
	i = 0;
	while (*s)
	{
		while (*s && check_seperator(*s, c))
			s++;
		if (*s)
		{
			result[i] = ft_word(s, c);
			if (!result[i])
				return (free_array(result, i));
			i++;
		}
		while (*s && !check_seperator(*s, c))
			s++;
	}
	result[i] = NULL;
	return (result);
}
/*
// Helper function to print result
void	print_split(char **split)
{
	int	i;

	i = 0;
	if (!split)
	{
		printf("NULL returned\n");
		return ;
	}
	while (split[i])
	{
		printf("split[%d] = \"%s\"\n", i, split[i]);
		i++;
	}
	printf("Total words: %d\n", i);
}

// Helper function to free split result
void	free_split(char **split)
{
	int	i;

	i = 0;
	if (!split)
		return ;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

int	main(void)
{
	char	sep[] = {' ', ':', ',', '\0'};
	char	**result;
	char	*big;
	char	**res;

	const char *tests[] = {"hello world 42",    // normal string
							"  hello   world  ", // multiple spaces
							"",                  // empty string
							"        ",          // only delimiters
							"oneword",           // single word
							"a:b:c::d",          // colons and empty between
							"::a::b::",          // leading and trailing colons
							"abc",               // no separator
							"abc:def::ghi",      // mix of cases
							NULL};
	for (int j = 0; sep[j]; j++)
	{
		printf("\n--- Testing with separator '%c' ---\n", sep[j]);
		for (int i = 0; tests[i]; i++)
		{
			printf("Input: \"%s\"\n", tests[i]);
			result = ft_split(tests[i], sep[j]);
			print_split(result);
			free_split(result);
			printf("\n");
		}
	}
	// Huge stress test
	printf("\n--- Stress test ---\n");
	big = malloc(1000001);
	if (!big)
		return (1);
	for (int i = 0; i < 1000000; i++)
		big[i] = (i % 10 == 0) ? ',' : 'a';
	big[1000000] = '\0';
	res = ft_split(big, ',');
	printf("Stress test done. First 3 tokens:\n");
	for (int i = 0; i < 3 && res[i]; i++)
		printf("  res[%d] = \"%s\"\n", i, res[i]);
	free_split(res);
	free(big);
	return (0);
}*/
