/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tail.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnicolau <marvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 19:03:45 by fnicolau          #+#    #+#             */
/*   Updated: 2025/04/21 21:55:24 by fnicolau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_tail.h"

// cbuf = circular_buffer
int	ft_tail(char *file_path, int fd, size_t bytes_to_read)
{
	ssize_t	i;
	ssize_t	bytes_read;
	size_t	total_bytes_read;
	size_t	cbuf_index;
	char	temp_buffer[3000];
	char	*circular_buffer;

	circular_buffer = malloc(bytes_to_read);
	if (!circular_buffer)
		return (1);
	cbuf_index = 0;
	total_bytes_read = 0;
	bytes_read = read(fd, temp_buffer, sizeof(temp_buffer));
	while (bytes_read > 0)
	{
		i = 0;
		total_bytes_read += bytes_read;
		while (i++ < bytes_read)
		{
			circular_buffer[cbuf_index] = temp_buffer[i - 1];
			cbuf_index = (cbuf_index + 1) % bytes_to_read;
		}
		bytes_read = read(fd, temp_buffer, sizeof(temp_buffer));
	}
	if (bytes_read == -1)
	{
		free(circular_buffer);
		return (print_error(file_path, fd));
	}
	if (total_bytes_read <= bytes_to_read)
		write(1, circular_buffer, total_bytes_read);
	else
	{
		write(1, circular_buffer + cbuf_index, (bytes_to_read - cbuf_index));
		if (cbuf_index > 0)
			write(1, circular_buffer, cbuf_index);
	}
	free(circular_buffer);
	return (0);
}
