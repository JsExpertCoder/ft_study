/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ulstr.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnicolau <fnicolau@student.42luanda.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 21:38:52 by fnicolau          #+#    #+#             */
/*   Updated: 2024/11/10 21:46:37 by fnicolau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <unistd.h>

int	main(int ac, char **av)
{
	int		i;
	char	c;
	bool	is_lower;
	bool	is_upper;

	if (ac == 2)
	{
		i = 0;
		while (av[1][i])
		{
			c = av[1][i];
			is_lower = (c >= 'a' && c <= 'z');
			is_upper = (c >= 'A' && c <= 'Z');
			if(is_lower)
				c -= 32;
			else if (is_upper)
				c += 32;
			write(1, &c, 1);
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}

