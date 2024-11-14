/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_and_replace.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnicolau <fnicolau@student.42luanda.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 20:18:26 by fnicolau          #+#    #+#             */
/*   Updated: 2024/11/10 21:10:43 by fnicolau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

void	ft_putstr(char *str)
{
	while (*str)
		write(1, str++, 1);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	main(int ac, char **av)
{
	int		i;
	char	str_char;
	char	char_to_find;
	char	replacer_char;

	if (ac == 4)
	{
		i = 0;
		char_to_find = av[2][i];
		replacer_char = av[3][i];
		if (ft_strlen(&av[2][i]) > 1 || ft_strlen(&av[3][i]) > 1)
		{
			write(1, "\n", 1);
			exit(0);
		}
		while (av[1][i])
		{
			str_char = av[1][i];
			if (str_char == char_to_find)
			{
				av[1][i] = replacer_char;
			}
			i++;
		}
		ft_putstr(&av[1][0]);
	}
	write(1, "\n", 1);
	return (0);
}
