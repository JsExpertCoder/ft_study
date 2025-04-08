/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnicolau <marvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 15:14:43 by fnicolau          #+#    #+#             */
/*   Updated: 2025/04/08 18:33:10 by fnicolau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cat.h"

int	main(int ac, char **av)
{
	int		i;
	int		fd;
	ssize_t	bytes_read;
	int		final_return;
	char	buffer[BUFFER_SIZE];

	i = 1;
	final_return = 0;
	while (i < ac)
	{
		fd = open(av[i], O_RDONLY);
		if (fd == -1)
		{
			ft_putstr_fd("cat: ", 2);
			ft_putstr_fd(av[i], 2);
			ft_putstr_fd(": ", 2);
			ft_putstr_fd(strerror(errno), 2);
			ft_putstr_fd("\n", 2);
			close(fd);
			final_return = -1;
		}
		else
		{
			bytes_read = read(fd, &buffer, BUFFER_SIZE);
			if (bytes_read == -1)
			{
				ft_putstr_fd(strerror(errno), 2);
				close(fd);
				final_return = -1;
			}
			else if (bytes_read > 0)
			{
				buffer[bytes_read] = 0;
				ft_putstr_fd(buffer, 1);
			}
		}
		close(fd);
		i++;
	}
	return (final_return);
}
