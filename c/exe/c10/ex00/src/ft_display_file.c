/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnicolau <marvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 22:51:27 by fnicolau          #+#    #+#             */
/*   Updated: 2025/03/27 19:49:25 by fnicolau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_display_file.h"

int	ft_display_file(char *file_path)
{
	int		fd;
	char	buffer;
	ssize_t	bytes_read;

	fd = open(file_path, O_RDONLY);
	if (fd == -1)
		return (false);
	while (true)
	{
		bytes_read = read(fd, &buffer, 1);
		if (bytes_read == -1)
		{
			close(fd);
			return (false);
		}
		else if (bytes_read > 0)
			write(1, &buffer, 1);
		else
			break ;
	}
	close(fd);
	return (true);
}
