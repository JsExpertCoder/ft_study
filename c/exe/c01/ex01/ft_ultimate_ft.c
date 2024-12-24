/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_ft.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnicolau <fnicolau@student.42luanda.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 19:34:23 by fnicolau          #+#    #+#             */
/*   Updated: 2024/10/13 19:56:21 by fnicolau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_ultimate_ft(int *********nbr)
{
	*********nbr = 42;
}

// remove before submission!!
int	main(void)
{
	int	num;
	int	*p0;
	int	**p1;
	int	***p2;
	int	****p3;
	int	*****p4;
	int	******p5;
	int	*******p6;
	int	********p7;
	int	*********p8;

	num = 204;
	p0 = &num;
	p1 = &p0;
	p2 = &p1;
	p3 = &p2;
	p4 = &p3;
	p5 = &p4;
	p6 = &p5;
	p7 = &p6;
	p8 = &p7;
	printf("before -> %i\n", num);
	ft_ultimate_ft(p8);
	printf("after -> %i\n", num);
	return (0);
}
