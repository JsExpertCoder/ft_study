/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnicolau <marvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 18:11:23 by fnicolau          #+#    #+#             */
/*   Updated: 2025/03/27 20:05:59 by fnicolau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_display_file.h"

int	main(int ac, char **av)
{
	if (ac == 1)
	{
		ft_putstr_fd(2, "File name missing.\n");
		return (-1);
	}
	else if (ac > 2)
	{
		ft_putstr_fd(2, "Too many arguments.\n");
		return (-1);
	}
	else
	{
		if (!ft_display_file(av[1]))
		{
			ft_putstr_fd(2, "Cannot read file.\n");
			return (-1);
		}
	}
	return (0);
}
