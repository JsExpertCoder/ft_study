/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_bits.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnicolau <fnicolau@student.42luanda.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 20:19:03 by fnicolau          #+#    #+#             */
/*   Updated: 2024/11/14 21:11:07 by fnicolau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void	print_bits(unsigned char octet)
{
	int i;
	unsigned char bit;
	
	i = 8;
	while (i--)
	{
		bit = (octet >> i & 1) + '0';
		write(1, &bit, 1);
	}
	return ;
}

unsigned char	reverse_bits(unsigned char octet)
{
	int	i;
	unsigned char result;

	i = 0;
	while (i < 8)
	{
		result = result * 2 + (octet % 2);
		octet /= 2;
		i++;
	}
	return (result);
}


int main(void)
{
	unsigned char octet = 7;
	print_bits(reverse_bits(octet));
	return (0);
}
