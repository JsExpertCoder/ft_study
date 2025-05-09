/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_stdin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnicolau <marvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 14:50:26 by fnicolau          #+#    #+#             */
/*   Updated: 2025/05/09 17:28:15 by fnicolau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_hexdump.h"

static ssize_t	read_into_buffer(int fd, t_buffer *buffer)
{
	ssize_t	bytes_read;
	size_t	bytes_left;
	char	*free_space;

	bytes_left = BUFFER_SIZE - buffer->bytes_rd;
	free_space = buffer->current + buffer->bytes_rd;
	bytes_read = read(fd, free_space, bytes_left);
	return (bytes_read);
}

bool	handle_stdin(t_buffer *buffer, bool canonical)
{
	ssize_t	bytes_read;
	size_t	final_return;

	bytes_read = read_into_buffer(STDIN, buffer);
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
		bytes_read = read_into_buffer(STDIN, buffer);
	}
	if (bytes_read == -1)
		final_return = print_error(0, NULL, errno);
	return (final_return);
}
