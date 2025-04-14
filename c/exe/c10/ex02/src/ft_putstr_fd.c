/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnicolau <fnicolau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 16:56:36 by fnicolau          #+#    #+#             */
/*   Updated: 2025/04/14 17:02:12 by fnicolau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_tail.h"

void	ft_putstr_fd(char *str, int fd)
{
	while (*str)
	{
		ft_putchar_fd(*str, fd);
		str++;
	}
	return ;
}
