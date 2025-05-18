/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnicolau <marvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 20:36:36 by fnicolau          #+#    #+#             */
/*   Updated: 2025/05/18 22:04:37 by fnicolau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	sum(int n1, int n2)
{
	ft_putnbr(n1 + n2);
	return (0);
}

int	sub(int n1, int n2)
{
	ft_putnbr(n1 - n2);
	return (0);
}

int	mult(int n1, int n2)
{
	ft_putnbr(n1 * n2);
	return (0);
}

int	div_(int n1, int n2)
{
	if (n2 == 0)
	{
		ft_putstr("Stop : division by zero");
		return (1);
	}
	ft_putnbr(n1 / n2);
	return (0);
}

int	mod(int n1, int n2)
{
	if (n2 == 0)
	{
		ft_putstr("Stop : modulo by zero");
		return (1);
	}
	ft_putnbr(n1 % n2);
	return (0);
}
