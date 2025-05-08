/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnicolau <marvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 12:23:00 by fnicolau          #+#    #+#             */
/*   Updated: 2025/05/08 22:48:40 by fnicolau         ###   ########.fr       */
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
		result[len - 1 - i] = hexadecimals[nbr % 16];
		i++;
		nbr /= 16;
	}
	ft_putstr_fd(result, 1);
	free(result);
	return (0);
}
