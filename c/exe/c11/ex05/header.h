/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnicolau <marvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 19:20:08 by fnicolau          #+#    #+#             */
/*   Updated: 2025/05/18 21:33:05 by fnicolau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include <unistd.h>
# include <limits.h>
# include <stdbool.h>

typedef int	(*t_calc)(int, int);

int		sum(int n1, int n2);
int		sub(int n1, int n2);
int		div_(int n1, int n2);
int		mod(int n1, int n2);
int		mult(int n1, int n2);

void	ft_putnbr(int nbr);
int		ft_atoi(char *nbr);
void	ft_putstr(char *str);
size_t	ft_strlen(const char *s);

#endif
