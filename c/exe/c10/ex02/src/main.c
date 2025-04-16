/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnicolau <marvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 16:47:38 by fnicolau          #+#    #+#             */
/*   Updated: 2025/04/15 20:09:52 by fnicolau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_tail.h"

int	main(int argc, char **argv)
{
	int		fd;
	int		i;
	int		final_return;
	int		bytes_to_read;
	int		total_of_files;

	final_return = 0;
	total_of_files = 0;
	bytes_to_read = option_parser(argv, argc);
	if (bytes_to_read == -1)
		return (-1);
	else if (bytes_to_read)
	{
		i = 1;
		while (argv[i])
		{
			if (argv[i][0] != '-')
			{
				fd = open(argv[i], O_RDONLY);
				if (fd == -1)
				{
					print_error(argv[i], fd);
					final_return = -1;
				}
				else
					ft_tail(argv[i], fd, bytes_to_read);
				total_of_files++;
			}
			i++;
		}
		if (total_of_files == 0)
			final_return = ft_tail("stdin", 0, bytes_to_read);
	}
	return (final_return);
}
