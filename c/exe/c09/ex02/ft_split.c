/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnicolau <marvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 15:22:06 by fnicolau          #+#    #+#             */
/*   Updated: 2025/03/22 20:52:38 by fnicolau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool	is_delimiter(const char c, const char *delimiter)
{
	while (*delimiter)
	{
		if (c == *delimiter)
			return (true);
		delimiter++;
	}
	return (0);
}

int	tokens_counter(const char *str, const char *delimiter)
{
	int	total;

	if (!str || !delimiter)
		return (0);
	total = 0;

	while (*str)
	{
		if (!(is_delimiter(*str, delimiter)))
		{
			while (*str && !(is_delimiter(*str, delimiter)))
				str++;
			total++;
		}
		if (*str)
			str++;
	}
	return (total);
}

char	**ft_split(char *str, char *charset)
{
	char	**result;
	size_t	tokens;

	if (!(str))
		return NULL;
	tokens = tokens_counter(str, charset);
	result = (char **)malloc(tokens * sizeof(char *));
	if (!result)
		return (NULL);

	return (result);
}

int	main(void)
{
	char *str = "thisaaa isaaa anaaa str";
	char *charset = "aaa";

	//ft_split("this is the best programming school ever", " ");
	printf("%i ", tokens_counter(str, charset));
	return (0);
}
