/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_data_types.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misterjs <misterjs@student.42.luanda>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 20:51:37 by misterjs          #+#    #+#             */
/*   Updated: 2024/09/17 21:56:13 by misterjs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_print_tree_letters(void)
{
	char	a;
	char	b;
	char	c;

	a = 97;
	b = 98;
	c = 99;
	printf("char a > %c\n", a);
	printf("char b > %c\n", b);
	printf("char c > %c\n", c);
}

int	main(void)
{
	int		num;
	char	letter;
	float	float_num;
	double	double_num;

	printf("int def size > %lu\n", sizeof(num));
	printf("char def size > %lu\n", sizeof(letter));
	printf("float def size > %lu\n", sizeof(float_num));
	printf("double def size > %luf\n", sizeof(double_num));
	num = 5;
	letter = 'F';
	float_num = 5.99;
	double_num = 1.99;
	printf("int: %i\n", num);
	printf("char: %c\n", letter);
	printf("float: %f\n", float_num);
	printf("double: %lf\n", double_num);
	ft_print_tree_letters();
	return (0);
}
