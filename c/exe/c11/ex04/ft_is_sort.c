/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnicolau <marvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 13:15:35 by fnicolau          #+#    #+#             */
/*   Updated: 2025/05/14 13:47:25 by fnicolau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>

int	ft_is_sort(int *tab, int length, int(*f)(int, int))
{
	int	i;
	int	ascendent_order;
	int	descendent_order;

	i = 0;
	ascendent_order = 0;
	descendent_order = 0;
	if (length == 1)
		return (1);
	while (i < length - 1)
	{
		if (((*f)(tab[i], tab[i + 1])) < 0)
			ascendent_order = 1;
		else if (((*f)(tab[i], tab[i + 1])) > 0)
			descendent_order = 1;
		i++;
	}
	if (ascendent_order && descendent_order)
		return (0);
	return (1);
}

// int	get_order_direction(int n1, int n2)
// {
// 	if (n1 < n2)
// 		return (-1);
// 	else if (n1 > n2)
// 		return (1);
// 	return (0);
// }

// int	main(void)
// {
// 	size_t	i;
// 	size_t	len;
// 	int		array[] = {12, 1, 0};

// 	i = 0;
// 	len = sizeof(array) / sizeof(array[0]);
// 	printf("> array (%li): ", len);
// 	while (i < len)
// 	{
// 		printf("%i, ", array[i]);
// 		i++;
// 	}
// 	if (ft_is_sort(array, len, &get_order_direction))
// 		printf("\nthe array is sorted :)\n");
// 	else
// 		printf("\nthe array is'n sorted :(\n");
// 	return (0);
// }