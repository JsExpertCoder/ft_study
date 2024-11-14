/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   repeat_alpha.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnicolau <fnicolau@student.42luanda.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 22:09:21 by fnicolau          #+#    #+#             */
/*   Updated: 2024/11/09 23:02:50 by fnicolau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <unistd.h>

void	repeat_char(char c, int i)
{
	while (i >= 0)
	{
		write(1, &c, 1);
		i--;
	}
}

int	main(int ac, char **av)
{
	int		i;
	bool	is_lower;
	bool	is_upper;
	if (ac == 2)
	{
		i = 0;
		while (av[1][i])
		{
			is_lower = (av[1][i] >= 'a' && av[1][i] <= 'z');
			is_upper = (av[1][i] >= 'A' && av[1][i] <= 'Z');

			if (is_lower)
				repeat_char(av[1][i], av[1][i] - 97);
			else if(is_upper)
				repeat_char(av[1][i], av[1][i] - 65);
			else
				write(1, &av[1][i], 1);
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}
