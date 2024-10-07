/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_8_arrays.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misterjs <misterjs@student.42.luanda>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 09:24:48 by misterjs          #+#    #+#             */
/*   Updated: 2024/09/20 14:20:08 by misterjs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "array_fn/ft_initialize_array.h"
#include "array_fn/ft_print_array.h"

void	ft_print_lowest_value(int array[], int array_length)
{
	int		i;
	int		j;
	int		lowest_value;

	i = 0;
	printf("looking for lowest value between:\n");
	ft_print_num_array(array, array_length);
	while (i < array_length)
	{
		j = 0;
		while (j < array_length)
		{
			if (array[i] < array[j] && lowest_value != array[i])
				lowest_value = array[i];
			j++;
		}
		i++;
	}
	printf("the lowest value is >\n");
}

void	ft_print_array_avg(int array[], int array_length)
{
	int		i;
	int		sum;
	float	avg;

	i = 0;
	sum = 0;
	printf("calculating array avg...\n");
	while (i < array_length)
	{
		sum += array[i];
		i++;
	}
	avg = sum / array_length;
	printf("array avg > %.2f\n", avg);
}

char	*are_you_playing_banjo(const char *name)
{
	static char	result[100];

	if (name[0] == 82 || name[0] == 114)
		snprintf(result, sizeof(result), "%s plays banjo", name);
	else
		snprintf(result, sizeof(result), "%s does not play banjo", name);
	return (result);
	return (calloc(1, 1));
}

// char name[] = {"Fabio"};
// printf("%s\n", are_you_playing_banjo(name));
// printf("%s\n", are_you_playing_banjo("john"));
// printf("%s\n", are_you_playing_banjo("mister bug"));
// printf("%s\n", are_you_playing_banjo("ruth"));
int	main(void)
{
	int	int_array[7];
	int	array_length;

	ft_initialize_array(int_array, 7);
	array_length = sizeof(int_array) / sizeof(int_array[0]);
	ft_print_num_array(int_array, array_length);
	ft_print_array_avg(int_array, array_length);
	ft_print_lowest_value(int_array, array_length);
	return (0);
}
