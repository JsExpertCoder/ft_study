/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wdmatch.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnicolau <fnicolau@student.42luanda.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 22:05:34 by fnicolau          #+#    #+#             */
/*   Updated: 2024/11/14 22:43:44 by fnicolau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <unistd.h>

void	ft_putstr(char *str)
{
	while (*str)
		write(1, str++, 1);
	return ;
}


int	main(int ac, char **av)
{
	int	i;
	int	j;
	bool can_write;

	if (ac == 3)
	{
		i = 0;
		j = 0;
		while (av[1][i])
		{
			can_write = false;
			while (av[2][j])
			{
				if (av[2][j] == av[1][i])
				{
					can_write = true;	
					j++;
					break ;
				}
				j++;
			}
			i++;
		}
		if (can_write)
			ft_putstr(av[1]);	
	}
	write(1, "\n", 1);
	return (0);
}
