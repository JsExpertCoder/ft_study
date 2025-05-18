/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnicolau <marvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 19:16:19 by fnicolau          #+#    #+#             */
/*   Updated: 2025/05/18 21:41:55 by fnicolau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putstr(char *str)
{
	while (*str)
		write(1, str++, 1);
	return ;
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	ft_putnbr(int nbr)
{
	char	digit;

	if (nbr == INT_MIN)
	{
		write(1, "-2147483648", 11);
	}
	if (nbr < 0)
	{
		write(1, "-", 1);
		nbr *= -1;
	}
	if (nbr >= 10)
		ft_putnbr(nbr / 10);
	digit = (nbr % 10) + '0';
	write (1, &digit, 1);
}

int	ft_atoi(char *nbr)
{
	int	sign;
	int	result;

	sign = 1;
	result = 0;
	while (*nbr == 32 || (*nbr >= 9 && *nbr <= 13))
		nbr++;
	while (*nbr == '-' || *nbr == '+')
	{
		if (*nbr == '-')
			sign *= -1;
		nbr++;
	}
	while (*nbr >= '0' && *nbr <= '9')
	{
		result = (result * 10) + (*nbr - '0');
		nbr++;
	}
	return (result * sign);
}
