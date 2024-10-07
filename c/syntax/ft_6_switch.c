/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_6_switch.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misterjs <misterjs@student.42.luanda>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 14:20:15 by misterjs          #+#    #+#             */
/*   Updated: 2024/09/18 14:40:41 by misterjs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	main(void)
{
	int	day;

	day = 42;
	switch (day)
	{
		case 0:
		{
			printf("today is sunday");
			break ;
		}
		case 1:
		{
			printf("today is monday");
			break ;
		}
		case 2:
		{
			printf("today is tuesday");
			break ;
		}
		case 3:
		{
			printf("today is wednesday");
			break ;
		}
		case 4:
		{
			printf("today is thursday");
			break ;
		}
		case 5:
		{
			printf("today is friday");
			break ;
		}
		case 6:
		{
			printf("today is saturday");
			break ;
		}
		default :
		{
			printf("invalid day :(");
		}
	}
	return (1);
}
