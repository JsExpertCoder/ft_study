/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_foreach.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnicolau <marvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 18:27:23 by fnicolau          #+#    #+#             */
/*   Updated: 2025/05/13 19:10:02 by fnicolau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <unistd.h>
// #include <limits.h>

// void	ft_putnbr(int nbr)
// {
// 	char	digit;

// 	if (nbr == INT_MIN)
// 	{
// 		write(1, "-2147483648", 11);
// 		return ;
// 	}
// 	if (nbr < 0)
// 	{
// 		write(1, "-", 1);
// 		nbr *= -1;
// 	}
// 	while (nbr >= 10)
// 	{
// 		ft_putnbr(nbr / 10);
// 		nbr %= 10;
// 	}
// 	digit = nbr + '0';
// 	write (1, &digit, 1);
// 	return ;
// }

void	ft_foreach(int *tab, int length, void(*f)(int))
{
	int	i;

	i = 0;
	while (i < length)
	{
		(*f)(tab[i]);
		/* write(1, "\n", 1); */
		i++;
	}
	return ;
}

// int	main(void)
// {
// 	int	tab[] = {1, 23, -34534, 345, -23, 24, INT_MIN, INT_MAX};

// 	ft_foreach(tab, (sizeof(tab) / sizeof(tab[0])), &ft_putnbr);
// 	write(1, "\n", 1);
// 	return (0);
// }
