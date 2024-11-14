/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fizzbuzz.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnicolau <fnicolau@student.42luanda.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 20:45:22 by fnicolau          #+#    #+#             */
/*   Updated: 2024/11/09 21:45:01 by fnicolau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putnbr(int n);
void	ft_putchar(char c);
void	ft_putstr(char *str);

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	if (nb >= 10)
		ft_putnbr(nb / 10);
	write(1, &"0123456789"[nb % 10], 1);
	//ft_putchar((nb % 10) + '0');
	return ;
}

void	ft_putstr(char *str)
{
	while (*str)
		write(1, str++, 1);
	return ;
}

int	main(void)
{
	int i;

	i = 0;
	while(i < 101)
	{
		if (i % 15 == 0)
			ft_putstr("fizzbuzz");
		else if (i % 5 == 0)
			ft_putstr("buzz");
		else if (i % 3 == 0)
			ft_putstr("fizz");
		else
			ft_putnbr(i);
		ft_putstr("\n");
		i++;
	}
	return (0);
}
