/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnicolau <marvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 15:43:27 by fnicolau          #+#    #+#             */
/*   Updated: 2025/05/08 22:48:37 by fnicolau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_hexdump.h"

bool	print_error(int fd, char *filepath, int error)
{
	ft_putstr_fd("hexdump: ", 2);
	if (filepath)
	{
		ft_putstr_fd(filepath, 2);
		ft_putstr_fd(": ", 2);
	}
	ft_putstr_fd(strerror(error), 2);
	ft_putstr_fd("\n", 2);
	if (fd > 2)
		close(fd);
	return (1);
}
