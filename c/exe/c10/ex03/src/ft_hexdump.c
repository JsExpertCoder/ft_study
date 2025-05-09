/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexdump.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnicolau <marvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 10:04:16 by fnicolau          #+#    #+#             */
/*   Updated: 2025/05/09 16:59:03 by fnicolau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_hexdump.h"

void	print_two_hexa_columns(t_buffer *buffer)
{
	size_t	i;

	i = 0;
	while (i < BUFFER_SIZE)
	{
		if (i == BUFFER_SIZE / 2)
			write(1, " ", 1);
		if (buffer->current[i])
			print_hexa(2, buffer->current[i]);
		else
			write(1, "  ", 2);
		write(1, " ", 1);
		i++;
	}
	return ;
}

void	print_chars(t_buffer *buffer)
{
	size_t	i;

	i = 0;
	write(1, " ", 1);
	write(1, "|", 1);
	while (i < buffer->bytes_rd)
	{
		if (buffer->current[i] >= 32 && buffer->current[i] <= 126)
			write (1, &buffer->current[i], 1);
		else
			write(1, ".", 1);
		i++;
	}
	write(1, "|", 1);
	return ;
}

void	reset_current(char *current)
{
	size_t	i;

	i = 0;
	while (i < BUFFER_SIZE)
	{
		current[i] = 0;
		i++;
	}
}

bool	ft_hexdump(t_buffer *buffer, bool canonical_style)
{
	if (ft_strcmp(buffer->current, buffer->previous) == 0)
	{
		if (buffer->flag)
		{
			write(1, "*\n", 2);
			buffer->flag = false;
		}
	}
	else
	{
		buffer->flag = true;
		print_hexa(8, buffer->offset);
		write(1, "  ", 2);
		print_two_hexa_columns(buffer);
		if (canonical_style)
			print_chars(buffer);
		write(1, "\n", 1);
		ft_strcpy(buffer->previous, buffer->current);
	}
	reset_current(buffer->current);
	return (0);
}
