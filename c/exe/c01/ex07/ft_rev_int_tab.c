/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnicolau <marvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 20:33:13 by fnicolau          #+#    #+#             */
/*   Updated: 2025/01/12 20:45:22 by fnicolau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

void	ft_rev_int_tab(int *tab, int size)
{
	int	left;
	int	right;
	int	temp;

	left = 0;
	right = size - 1;
	while (left < right)
	{
		temp = tab[left];
		tab[left] = tab[right];
		tab[right] = temp;
		left++;
		right--;
	}
}
/*
int	main(void)
{
	int	i = 0;
	int	nbrs[5] = {0, 5, 6, 3, 5};

	i = 0;
	while (i < 5)
		printf("%d ", nbrs[i++]);
	printf("====================\n");
	ft_rev_int_tab(nbrs, 5);
	i = 0;
	while (i < 5)
		printf("%d ", nbrs[i++]);
	return (0);
}
*/
