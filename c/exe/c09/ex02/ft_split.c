/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnicolau <marvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 15:22:06 by fnicolau          #+#    #+#             */
/*   Updated: 2025/03/23 19:22:26 by fnicolau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	return (false);
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
		else
			str++;
	}
	return (total);
}

char	*get_token_addr(char *str, char *delimiter)
{
	size_t	i;
	char	*token;

	i = 0;
	while (str[i] && !(is_delimiter(str[i], delimiter)))
		i++;
	token = (char *)malloc(sizeof(char) * (i + 1));
	if (!token)
		return (NULL);
	i = 0;
	while (str[i] && !(is_delimiter(str[i], delimiter)))
	{
		token[i] = str[i];
		i++;
	}
	token[i] = 0;
	return (token);
}

char	**ft_split(char *str, char *charset)
{
	size_t	i;
	size_t	tokens;
	char	**result;

	if (!str || !charset)
		return (NULL);
	tokens = tokens_counter(str, charset);
	result = (char **)malloc(sizeof(char *) * (tokens + 1));
	if (!result)
		return (NULL);
	i = 0;
	while (*str)
	{
		if (!(is_delimiter(*str, charset)))
		{
			result[i] = get_token_addr(str, charset);
			while (*str && !(is_delimiter(*str, charset)))
				str++;
			i++;
		}
		else
			str++;
	}
	result[i] = 0;
	return (result);
}
