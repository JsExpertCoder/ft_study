/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   option_parser.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnicolau <fnicolau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 19:02:26 by fnicolau          #+#    #+#             */
/*   Updated: 2025/04/14 20:13:55 by fnicolau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_tail.h"

int	option_parser(char *option)
{
	ft_putstr_fd("option_parser(", 1);
	ft_putstr_fd(option, 1);
	ft_putstr_fd(")\n", 1);
	return (-1);
}
// 1: tail -c == some error
// 3: tail -cBYTES == BYTES can an invalid number