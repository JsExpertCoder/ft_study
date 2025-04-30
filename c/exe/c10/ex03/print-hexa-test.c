/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print-hexa-test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnicolau <marvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 19:06:50 by fnicolau          #+#    #+#             */
/*   Updated: 2025/04/30 19:55:58 by fnicolau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

void	print_hexa(size_t nbr)
{
	size_t	i;
	char	result[8];
	char	*hexadecimals;

	i = 0;
	hexadecimals = "0123456789abcdef";
	while (i < sizeof(result))
	{
		result[i] = '0';
		i++;
	}
	while (nbr > 0 && i > 0)
	{
		result[i - 1] = hexadecimals[nbr % 16];
		i--;
		nbr /= 16;
	}
	printf("> hexa: %s\n", result);
}

int	main(int c, char **a)
{
	size_t	nbr;

	if (c > 1)
	{
		nbr = atoll(a[1]);
		printf("> dec: %li\n", nbr);
		print_hexa(nbr);
	}
	return (0);
}
