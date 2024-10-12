/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnicolau <fnicolau@student.42luanda.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 19:14:43 by fnicolau          #+#    #+#             */
/*   Updated: 2024/10/09 22:16:25 by fnicolau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdbool.h>

void	print_comb_result(char num1, char num2, char num3)
{
	bool	last_char;

	write(1, &num1, 1);
	write(1, &num2, 1);
	write(1, &num3, 1);
	last_char = (num1 == '7' && num2 == '8' && num3 == '9');
	if (!last_char)
	{
		write(1, ", ", 2);
	}
}

void	ft_print_comb(void)
{
	int		i;
	int		j;
	int		k;

	i = '0';
	while (i <= '7')
	{
		j = i + 1;
		while (j <= '8')
		{
			k = j + 1;
			while (k <= '9')
			{
				print_comb_result(i, j, k);
				k++;
			}
			j++;
		}
		i++;
	}
}
