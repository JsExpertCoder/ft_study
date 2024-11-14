/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rot_13.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnicolau <fnicolau@student.42luanda.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 23:20:15 by fnicolau          #+#    #+#             */
/*   Updated: 2024/11/09 23:52:56 by fnicolau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdbool.h>

int	main(int ac, char **av)
{
	int		i;
	char	c;
	bool	is_n_to_z;
	bool	is_a_to_m;

	if (ac == 2)
	{
		i = 0;
		while (av[1][i])
		{
			is_a_to_m = (av[1][i] >= 'a' && av[1][i] <= 'm') ||
						(av[1][i] >= 'A' && av[1][i] <= 'M');
			is_n_to_z = (av[1][i] >= 'n' && av[1][i] <= 'z') ||
						(av[1][i] >= 'N' && av[1][i] <= 'Z');

			if (is_a_to_m)
			{
				c = av[1][i] + 13;
				write(1, &c, 1);
			}
			else if(is_n_to_z)
			{
				c = av[1][i] - 13;
				write(1, &c, 1);
			}
			else
				write(1, &av[1][i], 1);
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}
