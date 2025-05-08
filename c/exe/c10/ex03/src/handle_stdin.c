/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_stdin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnicolau <marvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 14:50:26 by fnicolau          #+#    #+#             */
/*   Updated: 2025/05/03 14:12:33 by fnicolau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_hexdump.h"

bool	handle_stdin(t_buffer *buffer, bool canonical)
{
	size_t	bytes_left;
	ssize_t	bytes_read;
	char	*free_space;
	size_t	final_return;

	bytes_left = 16 - buffer->bytes_rd;
	free_space = buffer->current + buffer->bytes_rd;
	bytes_read = read(STDIN, free_space, bytes_left);
	while (bytes_read > 0)
	{
		buffer->bytes_rd += bytes_read;
		buffer->total_bytes_rd += bytes_read;
		if (buffer->bytes_rd == 16)
		{
			final_return = ft_hexdump(buffer, canonical);
			buffer->bytes_rd = 0;
			buffer->offset += 16;
		}
		bytes_left = 16 - buffer->bytes_rd;
		free_space = buffer->current + buffer->bytes_rd;
		bytes_read = read(STDIN, free_space, bytes_left);
	}
	if (bytes_read == -1)
		final_return = print_error(0, NULL, errno);
	return (final_return);
}
