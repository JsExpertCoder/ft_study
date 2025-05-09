/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnicolau <marvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 12:23:00 by fnicolau          #+#    #+#             */
/*   Updated: 2025/05/09 17:35:58 by fnicolau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_hexdump.h"

char	*ft_strcpy(char *dst, const char *src)
{
	size_t	i;

	i = 0;
	while (src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = 0;
	return (dst);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	while (*s1 && (*s1 == *s2))
	{
		s1++;
		s2++;
	}
	return ((unsigned char)*s1 - (unsigned char)*s2);
}

void	ft_putstr_fd(char *str, int fd)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		write(fd, &str[i], 1);
		i++;
	}
	return ;
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

bool	print_hexa(size_t len, size_t nbr)
{
	size_t	i;
	char	*result;
	char	*hexadecimals;

	result = malloc(len + 1);
	if (!result)
		return (1);
	i = 0;
	hexadecimals = "0123456789abcdef";
	while (i < len)
	{
		result[i] = '0';
		i++;
	}
	result[i] = 0;
	i = 0;
	while (nbr > 0 && i < len)
	{
		result[len - 1 - i] = hexadecimals[nbr % BUFFER_SIZE];
		i++;
		nbr /= BUFFER_SIZE;
	}
	ft_putstr_fd(result, 1);
	free(result);
	return (0);
}
