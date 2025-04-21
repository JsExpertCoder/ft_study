/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tail.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnicolau <marvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 19:03:45 by fnicolau          #+#    #+#             */
/*   Updated: 2025/04/21 21:00:06 by fnicolau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_tail.h"

// cbuf = circular_buffer
int	ft_tail(char *file_path, int fd, size_t bytes_to_read)
{
	ssize_t	i;
	char	*cbuf;
	size_t	cbuf_index;
	ssize_t	bytes_read;
	size_t	total_bytes_read;
	char	temp_buf[4096];

	cbuf_index = 0;
	total_bytes_read = 0;
	cbuf = malloc(bytes_to_read);
	if (cbuf == NULL)
		return (1);
	bytes_read = read(fd, temp_buf, sizeof(temp_buf));
	while (bytes_read > 0)
	{
		total_bytes_read += bytes_read;
		i = 0;
		while (i++ < bytes_read)
		{
			cbuf[cbuf_index] = temp_buf[i - 1];
			cbuf_index = (cbuf_index + 1) % bytes_to_read;
		}
		bytes_read = read(fd, temp_buf, sizeof(temp_buf));
	}
	if (bytes_read == -1)
	{
		free(cbuf);
		return (print_error(file_path, fd));
	}
	if (total_bytes_read < bytes_to_read)
		write(1, cbuf, total_bytes_read);
	else
	{
		write(1, cbuf + cbuf_index, (bytes_to_read - cbuf_index));
		if (cbuf_index > 0)
			write(1, cbuf, cbuf_index);
	}
	free(cbuf);
	return (0);
}
