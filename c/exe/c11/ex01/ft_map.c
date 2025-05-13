/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnicolau <marvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 19:15:16 by fnicolau          #+#    #+#             */
/*   Updated: 2025/05/13 19:47:26 by fnicolau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h> // for malloc
#include <stdio.h> // for testing purpose only

int	*ft_map(int *tab, int length, int(*f)(int))
{
	int	i;
	int	*mapped;

	i = 0;
	mapped = malloc(length * sizeof(int));
	if (!mapped)
		return (NULL);
	while (i < length)
	{
		mapped[i] = (*f)(tab[i]);
		i++;
	}
	return (mapped);
}

// int	sum_seven(int nbr)
// {
// 	return (nbr + 7);
// }

// void	print_array(int	*tab, size_t len)
// {
// 	size_t	i;

// 	i = 0;
// 	while (i < len)
// 	{
// 		printf("> %i\n", tab[i]);
// 		i++;
// 	}
// }

// int	main(void)
// {
// 	int	*result;
// 	int	array[] = {2, 3, 5, 90, 34, 234, 67, 100};

// 	printf("> before:\n");
// 	print_array(array, sizeof(array) / sizeof(array[0]));
// 	result = ft_map(array, sizeof(array) / sizeof(array[0]), &sum_seven);
// 	printf("> after:\n");
// 	print_array(result, sizeof(array) / sizeof(array[0]));
// 	return (0);
// }
