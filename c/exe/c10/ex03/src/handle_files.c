/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_files.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnicolau <marvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 15:04:36 by fnicolau          #+#    #+#             */
/*   Updated: 2025/05/08 22:48:30 by fnicolau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_hexdump.h"

bool	handle_files(t_buffer *buffer, t_files *files, bool canonical)
{
	int		fd;
	size_t	i;
	size_t	final_return;

	final_return = 0;
	if (canonical)
	{
	}
	i = 0;
	while (files->paths[i])
	{
		fd = open(files->paths[i], O_RDONLY);
		if (fd == -1)
			final_return = print_error(fd, files->paths[i], errno);
		else
		{
			printf("> file-%li: %s\n", i, files->paths[i]);
			printf("> buffer.offset: %li\n", buffer->offset);
			printf("> buffer.bytes_rd: %li\n", buffer->bytes_rd);
			printf("> buffer.total_bytes_rd: %li\n", buffer->total_bytes_rd);
			close(fd);
		}
		i++;
	}
	return (final_return);
}
