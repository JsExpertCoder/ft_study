/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_files.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnicolau <marvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 15:04:36 by fnicolau          #+#    #+#             */
/*   Updated: 2025/05/09 17:14:17 by fnicolau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_hexdump.h"

ssize_t	read_into_buffer(int fd, t_buffer *buffer)
{
	ssize_t	bytes_read;
	size_t	bytes_left;
	char	*free_space;

	bytes_left = BUFFER_SIZE - buffer->bytes_rd;
	free_space = buffer->current + buffer->bytes_rd;
	bytes_read = read(fd, free_space, bytes_left);
	return (bytes_read);
}

bool	read_file(int fd, char *filepath, t_buffer *buffer, bool canonical)
{
	ssize_t	bytes_read;
	size_t	final_return;

	bytes_read = read_into_buffer(fd, buffer);
	while (bytes_read > 0)
	{
		buffer->bytes_rd += bytes_read;
		buffer->total_bytes_rd += bytes_read;
		if (buffer->bytes_rd == BUFFER_SIZE)
		{
			final_return = ft_hexdump(buffer, canonical);
			buffer->bytes_rd = 0;
			buffer->offset += BUFFER_SIZE;
		}
		bytes_read = read_into_buffer(fd, buffer);
	}
	if (bytes_read == -1)
		final_return = print_error(fd, filepath, errno);
	return (final_return);
}

bool	handle_files(t_buffer *buffer, t_files *files, bool canonical)
{
	size_t	i;
	int		fd;
	size_t	final_return;

	i = 0;
	final_return = 0;
	while (files->paths[i])
	{
		fd = open(files->paths[i], O_RDONLY);
		if (fd == -1)
			final_return = print_error(fd, files->paths[i], errno);
		else
		{
			final_return = read_file(fd, files->paths[i], buffer, canonical);
			close(fd);
		}
		i++;
	}
	return (final_return);
}
