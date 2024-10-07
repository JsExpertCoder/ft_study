/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_2_data_conversion.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misterjs <misterjs@student.42.luanda>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 22:07:21 by misterjs          #+#    #+#             */
/*   Updated: 2024/09/17 22:33:15 by misterjs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_implicit_data_conversion(void)
{
	int		x;
	int		y;
	int		div;
	int		int_num;
	float	float_num;

	x = 5;
	y = 2;
	div = x / y;
	float_num = x;
	int_num = float_num;
	printf("ft_implicit_data_conversion\n");
	printf("float > int: (5 / 2) = %d\n", div);
	printf("float > int: (int_variable = 5.000000) = %i\n", int_num);
	printf("int > float: (float_variable = 5) = %f\n", float_num);
}

void	ft_explicit_data_conversion(void)
{
	float	div;

	div = (float)(5 / 2);
	printf("ft_implicit_data_conversion\n");
	printf("(float) of 5/2 %.2f\n", div);
}

void	main(void)
{
	ft_implicit_data_conversion();
	ft_explicit_data_conversion();
	return ;
}
