/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_bits.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnicolau <fnicolau@student.42luanda.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 21:39:16 by fnicolau          #+#    #+#             */
/*   Updated: 2024/11/14 21:48:42 by fnicolau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

unsigned char	swap_bits(unsigned char octet)
{
	return ((octet >> 4) | (octet << 4));
}

void	pb(unsigned char o)
{
	int i;

	i = 8;
	while (i--)
	{
		unsigned char b = (o >> i & 1) + '0';
		write(1, &b, 1);
	}
	return ;
}

int	main (void)
{
	unsigned char o = 1;
	pb(o);
	o = swap_bits(o);
	write(1, "\n", 1);
	pb(o);
	return (0);
}
