/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_7_while.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misterjs <misterjs@student.42.luanda>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 14:41:40 by misterjs          #+#    #+#             */
/*   Updated: 2024/09/18 15:44:31 by misterjs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_countdown(void)
{
	int	count_down;

	count_down = 5;
	printf("countdown\n");
	while (count_down >= 0)
	{
		printf("-> %d\n", count_down);
		count_down--;
	}
	printf("congratulation to approve on 42 piscine!!!!!!!!\n");
	return ;
}

void	ft_reverse_number(int num)
{
	int	reverse_num;
	int	num_to_reverse;

	num_to_reverse = num;
	printf("num > %i\n", num);
	while (num_to_reverse)
	{
		reverse_num = reverse_num * 10 + num_to_reverse % 10;
		num_to_reverse /= 10;
	}
	printf("reverse_num > %i\n", reverse_num);
	return ;
}

int	main(void)
{
	int	i;

	i = 0;
	while (i <= 5)
	{
		printf("%d\n", i);
		i++;
	}
	ft_countdown();
	ft_reverse_number(9702);
	return (1);
}
