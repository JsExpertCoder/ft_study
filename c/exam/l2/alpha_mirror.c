/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alpha_mirror.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnicolau <fnicolau@student.42luanda.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 20:07:46 by fnicolau          #+#    #+#             */
/*   Updated: 2024/11/11 22:50:36 by fnicolau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int ac, char **av)
{
	int		i;
	char	c;
	int		lower_max_value;
	int		upper_max_value;
	int		lower_min_value;
	int		upper_min_value;

	if (ac == 2)
	{
		i = 0;
		lower_min_value = 97;
		lower_max_value = 122;
		upper_min_value = 65;
		upper_max_value = 90;

		while (av[1][i])
		{
			c  = av[1][i];
			if (c >= 'a' && c <= 'z')
				c = (lower_max_value - c) + lower_min_value;
			else if (c >= 'A' && c <= 'Z')
				c = (upper_max_value - c) + upper_min_value;
			write(1, &c, 1);
			i++;
		}
	}
	write(1, "\n", 1);
}
