/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnicolau <marvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 23:14:14 by fnicolau          #+#    #+#             */
/*   Updated: 2024/12/31 23:54:17 by fnicolau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <limits.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *src)
{
	while (*src)
		ft_putchar(*src++);
}

void	ft_putnbr(int nb)
{
	char	digit_as_char;

	if (nb == INT_MIN)
	{
		write(1, "-2147483648", 11);
		return ;
	}
	if (nb < 0)
	{
		ft_putchar('-');
		nb = -nb;
	}
	if (nb >= 10)
	{
		ft_putnbr(nb / 10);
	}
	digit_as_char = (nb % 10) + '0';
	ft_putchar(digit_as_char);
}

void	ft_show_tab(struct s_stock_str *par)
{
	int	i;

	if (par != NULL)
	{
		i = 0;
		while (par[i].str)
		{
			ft_putstr(par[i].str);
			write(1, "\n", 1);
			ft_putnbr(par[i].size);
			write(1, "\n", 1);
			ft_putstr(par[i].copy);
			write(1, "\n", 1);
			i++;
		}
	}
	return ;
}
