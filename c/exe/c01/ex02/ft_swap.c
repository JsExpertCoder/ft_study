/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnicolau <fnicolau@student.42luanda.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 19:57:06 by fnicolau          #+#    #+#             */
/*   Updated: 2024/10/13 20:07:08 by fnicolau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_swap(int *a, int *b)
{
	int	aux;

	aux = *a;
	*a = *b;
	*b = aux;
}

// remove this before submission!!
int	main(void)
{
	int	x;
	int	y;
	int	*a;
	int	*b;

	x = 97;
	y = 80;
	a = &x;
	b = &y;
	printf("before: x -> %i y -> %i", x, y);
	ft_swap(a, b);
	printf("after x -> %i y -> %i", x, y);
	return (0);
}
