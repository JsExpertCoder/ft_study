/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnicolau <marvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 22:36:34 by fnicolau          #+#    #+#             */
/*   Updated: 2025/01/05 22:56:46 by fnicolau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	main(void)
{
	int		a;
	int		b;
	char	c;
	char	*str;

	c = '$';
	str = "Hello, libft!";
	ft_putchar(c);
	ft_putchar('\n');
	ft_putstr(str);
	ft_putchar('\n');
	ft_putchar('\n');
	ft_swap(&a, &b);
	return (0);
}
