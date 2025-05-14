/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_if.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnicolau <marvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 12:46:15 by fnicolau          #+#    #+#             */
/*   Updated: 2025/05/14 13:07:19 by fnicolau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h> // for size_t
// #include <stdio.h>

int	ft_count_if(char **tab, int length, int(*f)(char*))
{
	int		i;
	size_t	total;

	i = 0;
	total = 0;
	while (i < length)
	{
		if ((*f)(tab[i]))
			total++;
		i++;
	}
	return (total);
}

// int	has_space(char *s)
// {
// 	while (*s)
// 	{
// 		if (*s == 32)
// 			return (1);
// 		s++;
// 	}
// 	return (0);
// }

// int	is_not_empty(char *s)
// {
// 	return (*s != 0);
// }

// size_t	get_total(char **s)
// {
// 	size_t	i;

// 	i = 0;
// 	while (s[i])
// 		i++;
// 	return (i);
// }

// int	main(void)
// {
// 	size_t	i;
// 	char	*tab[] = {"pretty!", "this is a spaced string", 0};

// 	printf("> array elements:\n");
// 	i = 0;
// 	while (tab[i])
// 	{
// 		printf("%li: %s\n", i, tab[i]);
// 		i++;
// 	}
// 	printf("> is_not_empty: %i\n", ft_count_if(tab, get_total(tab), &is_not_empty));
// 	printf("> has_space: %i\n", ft_count_if(tab, get_total(tab), &has_space));
// 	return (0);
// }
