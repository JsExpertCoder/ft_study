/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   union.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnicolau <fnicolau@student.42luanda.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 21:55:48 by fnicolau          #+#    #+#             */
/*   Updated: 2024/11/14 22:01:38 by fnicolau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int ac, char **av)
{
	int	i;
	unsigned int written[256] = {0};

	if (ac == 3)
	{
		i = 0;
		while (av[1][i])
		{
			if (!written[(unsigned int)av[1][i]])
			{
				write(1, &av[1][i], 1);
				written[(unsigned int)av[1][i]] = 1;
			}
			i++;
		}
		i = 0;
		while (av[2][i])
		{
			if (!written[(unsigned int)av[2][i]])
			{
				write(1, &av[2][i], 1);
				written[(unsigned int)av[2][i]] = 1;
			}
			i++;
		}

	}
	write(1, "\n", 1);
	return (0);
}
