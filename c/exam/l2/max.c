/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   max.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnicolau <fnicolau@student.42luanda.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 20:43:54 by fnicolau          #+#    #+#             */
/*   Updated: 2024/11/13 21:18:08 by fnicolau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	max(int *tab, unsigned int len)
{
	int				largest;
	unsigned int	i;
	
	if (len == 0)
		return (0);
	i = 1;
	largest = tab[0];
	while (i < len)
	{
		if (tab[i] > largest)
			largest = tab[i];
		i++;
	}
	return (largest);
}

int	main(void)
{
	int	n[] = {24, 56, 0, 45, 76, 3, 87, -345, 7,3, 6,34};
	printf("%i", max(n, (sizeof(n) / sizeof(n[0]))));
	//printf("%i", max(n, 0));

	return (0);
}
