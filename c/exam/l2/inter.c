/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnicolau <fnicolau@student.42luanda.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 15:22:02 by fnicolau          #+#    #+#             */
/*   Updated: 2024/11/13 16:13:05 by fnicolau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

int	main(int ac, char **av)
{
	int i;
	int	j;
	unsigned int	wrote[256] = {0};
   
	if (ac == 3)
	{
		i = 0;
		while(av[1][i])
		{
			j = 0;
			while (av[2][j])
			{
				if (av[1][i] == av[2][j] && !wrote[(unsigned int)av[1][i]])
				{
					write(1, &av[1][i], 1);
					wrote[(unsigned int)av[1][i]] = 1;
					break ;
				}
				j++;
			}
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}
