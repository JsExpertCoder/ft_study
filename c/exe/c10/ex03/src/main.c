/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnicolau <marvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 18:37:15 by fnicolau          #+#    #+#             */
/*   Updated: 2025/05/09 17:24:02 by fnicolau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_hexdump.h"

static bool	check_option_existence(char **tokens)
{
	size_t	i;

	i = 0;
	while (tokens[i])
	{
		if ((tokens[i][0] == '-'))
		{
			if (ft_strcmp(tokens[i], "-C") == 0)
				return (true);
		}
		i++;
	}
	return (false);
}

void	init_buffer(t_buffer *buffer)
{
	size_t		i;

	buffer->offset = 0;
	buffer->bytes_rd = 0;
	buffer->flag = false;
	buffer->total_bytes_rd = 0;
	i = 0;
	while (i++ <= BUFFER_SIZE)
	{
		buffer->current[i - 1] = 0;
		buffer->previous[i - 1] = 0;
	}
}

t_buffer	*alloc_buffer(void)
{
	t_buffer	*buffer;

	buffer = malloc(sizeof(t_buffer));
	if (!buffer)
		return (NULL);
	buffer->current = malloc(BUFFER_SIZE + 1);
	buffer->previous = malloc(BUFFER_SIZE + 1);
	if (!buffer->current || !buffer->previous)
	{
		free(buffer);
		return (NULL);
	}
	init_buffer(buffer);
	return (buffer);
}

void	final_print(t_buffer *buffer, bool canonical_style)
{
	if (buffer->bytes_rd)
		ft_hexdump(buffer, canonical_style);
	if (buffer->total_bytes_rd)
	{
		print_hexa(8, buffer->total_bytes_rd);
		write(1, "\n", 1);
	}
	return ;
}

int	main(int _, char **argv)
{
	t_files		*files;
	t_buffer	*buffer;
	size_t		final_return;
	bool		use_canonical_style;

	(void)_;
	buffer = alloc_buffer();
	if (buffer == NULL)
		return (1);
	final_return = 0;
	files = file_collector(++argv);
	use_canonical_style = check_option_existence(argv);
	if (files == 0)
		final_return = handle_stdin(buffer, use_canonical_style);
	else if (files != NULL)
	{
		final_return = handle_files(buffer, files, use_canonical_style);
		free(files->paths);
		free(files);
	}
	final_print(buffer, use_canonical_style);
	free(buffer->current);
	free(buffer->previous);
	free(buffer);
	return (final_return);
}
