/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_stdin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnicolau <marvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 14:50:26 by fnicolau          #+#    #+#             */
/*   Updated: 2025/04/30 23:06:36 by fnicolau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_hexdump.h"

static void	print_offset(size_t nbr)
{
	size_t	i;
	char	result[8];
	char	*hexadecimals;

	i = 0;
	hexadecimals = "0123456789abcdef";
	while (i < sizeof(result))
	{
		result[i] = '0';
		i++;
	}
	while (nbr > 0 && i > 0)
	{
		result[i - 1] = hexadecimals[nbr % 16];
		i--;
		nbr /= 16;
	}
	ft_putstr_fd(result, 1);
	ft_putstr_fd(" ", 1);
	return ;
}

unsigned int	stdin_dump(bool use_canonical_style)
{
	size_t	offset;
	ssize_t	bytes_read;
	char	temp_buffer[16];

	offset = 0;
	(void)use_canonical_style;
	bytes_read = read(STDIN, temp_buffer, sizeof(temp_buffer) - 1);
	while (bytes_read > 0)
	{
		if (bytes_read == 16)
		{
			print_offset(offset);
			ft_putstr_fd("\n", 1);
			offset += 16;
		}
		bytes_read = read(STDIN, temp_buffer, sizeof(temp_buffer));
	}
	if (bytes_read == -1)
	{
		print_error(0, NULL, errno);
		return (1);
	}
	return (0);
}
