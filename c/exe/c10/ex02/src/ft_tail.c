/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tail.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnicolau <marvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 19:03:45 by fnicolau          #+#    #+#             */
/*   Updated: 2025/04/21 23:33:06 by fnicolau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_tail.h"

static t_circular_buffer	*structure_circular_buffer(size_t size, int fd)
{
	ssize_t				i;
	t_circular_buffer	*cb;
	ssize_t				bytes_read;
	char				temp_buffer[3000];

	cb = malloc(sizeof(t_circular_buffer));
	if (!cb)
		return (0);
	cb->size = size;
	cb->index = 0;
	cb->total_bytes_read = 0;
	cb->content = malloc(size);
	if (!cb->content)
		return (0);
	bytes_read = read(fd, temp_buffer, sizeof(temp_buffer));
	while (bytes_read > 0)
	{
		i = 0;
		cb->total_bytes_read += bytes_read;
		while (i++ < bytes_read)
		{
			cb->content[cb->index] = temp_buffer[i - 1];
			cb->index = (cb->index + 1) % cb->size;
		}
		bytes_read = read(fd, temp_buffer, sizeof(temp_buffer));
	}
	if (bytes_read == -1)
	{
		free(cb->content);
		free(cb);
		return (0);
	}
	return (cb);
}

int	ft_tail(char *file_path, int fd, size_t bytes_to_read)
{
	t_circular_buffer	*cb;

	cb = structure_circular_buffer(bytes_to_read, fd);
	if (!cb)
		return (print_error(file_path, fd));
	if (cb->total_bytes_read <= bytes_to_read)
		write(1, cb->content, cb->total_bytes_read);
	else
	{
		write(1, cb->content + cb->index, (bytes_to_read - cb->index));
		if (cb->index > 0)
			write(1, cb->content, cb->index);
	}
	free(cb);
	return (0);
}
