/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tail.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnicolau <fnicolau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 19:03:45 by fnicolau          #+#    #+#             */
/*   Updated: 2025/04/15 19:42:05 by fnicolau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_tail.h"

int	ft_tail(char *file_path, int fd, size_t bytes_to_read)
{
	(void)fd;
	(void)file_path;
	(void)bytes_to_read;
	if (fd == 0)
	{
		ft_putstr_fd("ft_tail: read all BYTES of fd\n", 1);
		return (0);
	}
	ft_putstr_fd("ft_tail: read bytes_to_read of fd from end\n", 1);
	return (1);
}
