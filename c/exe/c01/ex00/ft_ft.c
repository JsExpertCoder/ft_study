/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnicolau <fnicolau@student.42luanda.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 17:16:53 by fnicolau          #+#    #+#             */
/*   Updated: 2024/10/13 17:55:26 by fnicolau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdbool.h>
#include <limits.h>
#include <stdio.h>

// remove this before submission
void	break_line(void)
{
	write(1, "\n", 1);
}

// remove this before submission
void	ft_putchar(char c)
{
	write(1, &c, 1);
}

// remove this before submission
void	ft_putnbr(int num)
{
	if (num == INT_MIN)
	{
		write(1, "-2147483648", 1);
	}
	if (num < 0)
	{
		write(1, "-", 1);
	}
	if (num >= 10)
	{
		ft_putnbr(num / 10);
	}
	ft_putchar((num % 10) + '0');
}

void	ft_ft(int *nbr)
{
	*nbr = 42;
	return ;
}

// remove this before submission
int	main(void)
{
	int	num;
	int	*p;

	p = &num;
	write(1, "before -> ", 9);
	ft_putnbr(num);
	break_line();
	write(1, "after ->", 9);
	ft_ft(p);
	ft_putnbr(num);
	return (0);
}
