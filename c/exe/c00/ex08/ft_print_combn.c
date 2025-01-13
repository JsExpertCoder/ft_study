/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnicolau <fnicolau@student.42luanda.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 23:22:28 by fnicolau          #+#    #+#             */
/*   Updated: 2025/01/13 22:24:52 by fnicolau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdbool.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	print_comma_or_not(int *comb, int n)
{
	int		i;
	bool	is_last_comb;
	int		maximum_value_of_digit_in_comb;

	i = 0;
	is_last_comb = true;
	while (i < n)
	{
		maximum_value_of_digit_in_comb = 10 - n + i;
		if (comb[i] != maximum_value_of_digit_in_comb)
		{
			is_last_comb = false;
			break ;
		}
		i++;
	}
	if (is_last_comb)
		return ;
	else
	{
		ft_putchar(',');
		ft_putchar(' ');
	}
}

void	print_comb(int *comb, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		ft_putchar(comb[i] + '0');
		i++;
	}
	print_comma_or_not(comb, n);
}

void	ft_print_combn(int n)
{
	int	i;
	int	comb[10];

	i = 0;
	while (i < n)
	{
		comb[i] = i;
		i++;
	}
	while (1)
	{
		print_comb(comb, n);
		i = n - 1;
		while (i >= 0 && comb[i] == 10 - n + i)
			i--;
		if (i < 0)
			break ;
		comb[i]++;
		while (++i < n)
			comb[i] = comb[i - 1] + 1;
	}
}

/*int	main(void)
{
	int	n;

	n = 0;
	while (n < 10)
	{
		ft_print_combn(n);
		ft_putchar('\n');
		ft_putchar('\n');
		ft_putchar('\n');
		n++;
	}
	return (0);
}*/
