/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tail.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnicolau <marvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 19:03:45 by fnicolau          #+#    #+#             */
/*   Updated: 2025/04/16 21:48:45 by fnicolau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_tail.h"

int	ft_tail(char *file_path, int fd, size_t bytes_to_read)
{
	char	*buffer;
	ssize_t	bytes_read;
	ssize_t	last_total_bytes_read;

	if (fd == 0)
	{
		buffer = (char *)malloc(bytes_to_read + 1);
		if (buffer == NULL)
			return (1);
		while (true)
		{
			bytes_read = read(fd, buffer, bytes_to_read);
			if (bytes_read == -1)
			{
				free(buffer);
				print_error(file_path, fd);
				return (1);
			}
			if (bytes_read > 0)
				last_total_bytes_read = bytes_read;
			else
			{
				write(1, buffer, last_total_bytes_read);
				free(buffer);
				return (0);
			}
		}
	}
	return (0);
}
