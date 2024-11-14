/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnicolau <fnicolau@student.42luanda.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 23:54:29 by fnicolau          #+#    #+#             */
/*   Updated: 2024/11/12 16:07:31 by fnicolau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	main(int ac, char **av)
{
	int		n1;
	int		n2;
	int		result;
	char	operator;
	if (ac == 4)
	{
		n1 = atoi(&av[1][0]);
		n2 = atoi(&av[3][0]);
		operator = av[2][0];
		if (operator == '+')
			result = n1 + n2;
		else if (operator == '-')
			result = n1 - n2;
		else if (operator == '*')
			result = n1 * n2;
		else if (operator == '/')
			result = n1 / n2;
		else if (operator == '%')
			result = n1 % n2;
		printf("%i", result);
	}
	printf("\n");
	return (0);
}
