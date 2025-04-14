/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnicolau <fnicolau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 16:47:38 by fnicolau          #+#    #+#             */
/*   Updated: 2025/04/14 20:39:54 by fnicolau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_tail.h"

int	main(int ac, char **av)
{
	int		fd;

	if (ac == 1)
		return (ft_tail("stdin", 0, 0, 0));
	else if (ac == 2)
	{
		if (ft_strncmp(av[1], "-c", 2) == 0)
		{
			if (option_parser(av[1]) == -1)
				return (1);
			else if (option_parser(av[1]) > 0)
				return (ft_tail("stdin", 0, option_parser(av[1]), 0));
		}
		fd = open(av[1], O_RDONLY);
		if (fd == -1)
			return (print_error(av[1], fd));
		return (ft_tail(av[1], fd, 0, 10));
	}
	else if (ac == 3)
	{
	}
	else if (ac >= 4)
	{
	}
	return (0);
}

// 2: tail -c file-paths == some error
// 2: tail file-paths -c == some error
// 1: tail -c BYTES == stdin, read a max of BYTES from the end
// 2: tail -cBYTES file-paths == read file-paths, read max of BYTES / file
// 2: tail file-paths -cBYTES == read file-paths, read max of BYTES / file

// 1: tail -c BYTES file-paths == read file-paths, read max of BYTES / file
// 1: tail file-paths -c BYTES == read file-paths, read max of BYTES / file