/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stdin_dump.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnicolau <marvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 14:50:26 by fnicolau          #+#    #+#             */
/*   Updated: 2025/04/28 17:07:58 by fnicolau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_hexdump.h"

unsigned int	stdin_dump(bool use_canonical_style)
{
	ssize_t	bytes_read;
	char	temp_buffer[3000];

	bytes_read = read(STDIN, temp_buffer, sizeof(temp_buffer));
	if (bytes_read == -1)
	{
		print_error(0, NULL, errno);
		return (1);
	}
	if (use_canonical_style)
		ft_putstr_fd("> -- canonical on stdin:\n", 1);
	else
		ft_putstr_fd("> -- default on stdin:\n", 1);
	write(1, temp_buffer, bytes_read);
	return (0);
}
