/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_initialize_array.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misterjs <misterjs@student.42.luanda>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 10:16:54 by misterjs          #+#    #+#             */
/*   Updated: 2024/09/20 10:35:16 by misterjs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_initialize_array(int *array_to_initialize, int array_desired_size)
{
	int	i;

	i = 0;
	printf("initializing array...:\n");
	while (i < array_desired_size)
	{
		array_to_initialize[i] = i * 3 + array_desired_size;
		i++;
	}
	printf("done!\n");
}
