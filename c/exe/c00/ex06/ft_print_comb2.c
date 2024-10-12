/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnicolau <fnicolau@student.42luanda.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 22:35:06 by fnicolau          #+#    #+#             */
/*   Updated: 2024/10/10 14:15:27 by fnicolau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdbool.h>

void	print_result(char first_char, char second_char, char i, char j)
{
	bool	last_char;

	write(1, &first_char, 1);
	write(1, &second_char, 1);
	write(1, " ", 1);
	write(1, &i, 1);
	write(1, &j, 1);
	last_char = (first_char == '9' && second_char == '8');
	if (!last_char)
	{
		write(1, ", ", 2);
	}
}

void	print_greater_than(char first_char, char second_char)
{
	int		i;
	int		j;

	i = '0';
	j = '0';
	while (i <= '9')
	{
		while (j <= '9')
		{
			if (i > first_char || (i == first_char && j > second_char))
			{
				print_result(first_char, second_char, i, j);
			}
			j++;
		}
		j = '0';
		i++;
	}
}

void	ft_print_comb2(void)
{
	int		i;
	int		j;

	i = '0';
	j = '0';
	while (i <= '9')
	{
		while (j <= '9')
		{
			print_greater_than(i, j);
			j++;
		}
		j = '0';
		i++;
	}
}
