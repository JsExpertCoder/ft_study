/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_array.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misterjs <misterjs@student.42.luanda>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 10:59:00 by misterjs          #+#    #+#             */
/*   Updated: 2024/09/20 14:20:06 by misterjs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void	ft_print_num_array(int array[], int array_length)
{
	int	i;

	i = 0;

	while (i < array_length)
	{
		if (i > 0)
			write(1, ", ", 2);
		write(1, &array[i] + '0', 1);
		i++;
	}
	write(1, "\n", 1);
}

void	ft_print_char_array(char main_array[], int array_length)
{
	int	i;
	int	j;
	int	local_array[4];

	i = 0;
	j = 0;
	local_array[0] = 123;
	local_array[1] = 345;
	local_array[2] = 2;
	local_array[3] = 345;
	printf("printing main array values:\n");
	while (i < array_length)
	{
		printf("> %d\n", main_array[i]);
		i++;
	}
	printf("printing local array values:\n");
	while (j < 4)
	{
		printf("> %d\n", local_array[j]);
		j++;
	}
}
