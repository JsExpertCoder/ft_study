/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnicolau <marvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 20:46:54 by fnicolau          #+#    #+#             */
/*   Updated: 2025/01/12 21:01:46 by fnicolau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

void	ft_sort_int_tab(int *tab, int size)
{
	int	i;
	int	j;
	int	temp;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (tab[i] > tab[j])
			{
				temp = tab[i];
				tab[i] = tab[j];
				tab[j] = temp;
			}
			j++;
		}
		i++;
	}
}
/*
int	main(void)
{
	int	i = 0;
	int	nbrs[] = {5, 4, 423, 3, 65, 9, 88, 3, 5, 5, 7, 3, 1, 8, 23, 5, 7, 23, 34, 2, 0};
	int	size = sizeof(nbrs) / sizeof(nbrs[0]);

	i = 0;
	while (i < size)
		printf("%d ", nbrs[i++]);
	printf("\n====================\n");
	ft_sort_int_tab(nbrs, size);
	i = 0;
	while (i < size)
		printf("%d ", nbrs[i++]);
	return (0);
}*/
