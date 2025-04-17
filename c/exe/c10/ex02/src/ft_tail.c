/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tail.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnicolau <marvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 19:03:45 by fnicolau          #+#    #+#             */
/*   Updated: 2025/04/17 22:51:15 by fnicolau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_tail.h"

static int	get_file_size(char *file_path)
{
	int		fd;
	char	buffer;
	int		file_size;
	ssize_t	bytes_read;

	fd = open(file_path, O_RDONLY);
	if (fd == -1)
		return (print_error(file_path, fd) *-1);
	file_size = 0;
	while (true)
	{
		bytes_read = read(fd, &buffer, 1);
		if (bytes_read == -1)
		{
			print_error(file_path, fd);
			return (-1);
		}
		else if (bytes_read == 0)
			break ;
		file_size++;
	}
	return (file_size);
}

int	ft_tail(char *file_path, int fd, size_t bytes_to_read)
{
	char	*buffer;
	int		file_size;
	ssize_t	bytes_read;

	(void)bytes_to_read;
	if (fd > 2)
	{
		file_size = get_file_size(file_path);
		if (file_size == -1)
			return (1);
		buffer = malloc(file_size + 1);
		if (buffer == NULL)
			return (1);
		bytes_read = read(fd, buffer, file_size);
		if (bytes_read == -1)
		{
			free(buffer);
			print_error(file_path, fd);
			return (1);
		}
		else if (bytes_read > 0)
		{
			buffer[file_size] = 0;
			ft_putstr_fd(&buffer[file_size - bytes_to_read], 1);
			free(buffer);
		}
	}
	return (0);
}

// use a circular buffer implementation later