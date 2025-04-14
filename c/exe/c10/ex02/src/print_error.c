/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnicolau <fnicolau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 20:05:11 by fnicolau          #+#    #+#             */
/*   Updated: 2025/04/14 20:05:17 by fnicolau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_tail.h"

int	print_error(char *file_path, int fd)
{
	ft_putstr_fd("tail: ", 2);
	ft_putstr_fd("cannot open: '", 2);
	ft_putstr_fd(file_path, 2);
	ft_putstr_fd("' for reading: ", 2);
	ft_putstr_fd(strerror(errno), 2);
	ft_putstr_fd("\n", 2);
	close(fd);
	return (1);
}
