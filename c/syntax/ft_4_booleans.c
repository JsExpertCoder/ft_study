/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_4_booleans.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misterjs <misterjs@student.42.luanda>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 11:06:43 by misterjs          #+#    #+#             */
/*   Updated: 2024/09/18 14:09:08 by misterjs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdbool.h>

void	ft_can_user_vote(void)
{
	int	age;
	int	voting_age;

	age = 17;
	voting_age = 18;
	printf("ft_can_user_vote\n");
	if (age >= voting_age)
		printf("with %i you can vote :)\n", age);
	else
		printf("with %i you can´t vote :(\n", age);
}

int	main(void)
{
	int		x;
	int		y;
	bool	evaluation;
	bool	is_programming_fun;
	bool	is_piscine_for_weak_ones;

	x = 7;
	y = 9;
	evaluation = x < y;
	is_programming_fun = true;
	is_piscine_for_weak_ones = false;
	printf("is_programming_fun > %d\n", is_programming_fun);
	printf("is_piscine_for_weak_ones > %d\n", is_piscine_for_weak_ones);
	printf("10 < 9: %d\n", (10 < 9));
	printf("x < y: %d\n", evaluation);
	ft_can_user_vote();
	return (0);
}
