/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tail.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnicolau <marvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 19:03:45 by fnicolau          #+#    #+#             */
/*   Updated: 2025/04/20 20:36:47 by fnicolau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_tail.h"

static void	print_circular_buffer(char *c_buffer, size_t cb_index,	\
	size_t bytes_to_read)
{
	size_t	last_cb_index;

	if ((cb_index + 1) == bytes_to_read)
		write(1, c_buffer, bytes_to_read);
	else
	{
		last_cb_index = cb_index;
		while (true)
		{
			cb_index = (cb_index + 1) % bytes_to_read;
			write(1, &c_buffer[cb_index], 1);
			if (last_cb_index == cb_index)
				break ;
		}
	}
}

int	ft_tail(char *file_path, int fd, size_t bytes_to_read)
{
	ssize_t	i;
	ssize_t	bytes_read;
	char	*circular_buffer;
	size_t	total_bytes_read;
	char	temp_buffer[3000];
	size_t	circular_buf_index;

	circular_buffer = malloc((bytes_to_read));
	if (!circular_buffer)
		return (1);
	total_bytes_read = 0;
	circular_buf_index = 0;
	while (true)
	{
		bytes_read = read(fd, temp_buffer, sizeof(temp_buffer));
		if (bytes_read == -1)
		{
			free(circular_buffer);
			return (print_error(file_path, fd));
		}
		else if (bytes_read > 0)
		{
			total_bytes_read += bytes_read;
			i = 0;
			while (i < bytes_read)
			{
				circular_buffer[circular_buf_index] = temp_buffer[i];
				i++;
				if (i < bytes_read)
					circular_buf_index = (circular_buf_index + 1) % bytes_to_read;
			}
		}
		else
			break ;
	}
	if (total_bytes_read >= bytes_to_read)
		print_circular_buffer(circular_buffer, circular_buf_index, bytes_to_read);
	else
		write(1, circular_buffer, total_bytes_read);
	free(circular_buffer);
	return (0);
}
