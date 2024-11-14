/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotone.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnicolau <fnicolau@student.42luanda.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 20:01:01 by fnicolau          #+#    #+#             */
/*   Updated: 2024/11/10 20:10:03 by fnicolau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <unistd.h>

int	main(int ac, char **av)
{
	int		i;
	char	c;
	bool	is_a_to_y;

	if (ac == 2)
	{
		i = 0;
		while (av[1][i])
		{
			c =  av[1][i];
			is_a_to_y = ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
			if (c == 'z' || c == 'Z')
				c -= 25;
			else if (is_a_to_y)
				c += 1;
			write(1, &c, 1);
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}
