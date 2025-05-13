/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_any.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnicolau <marvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 19:55:41 by fnicolau          #+#    #+#             */
/*   Updated: 2025/05/13 20:54:23 by fnicolau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
// #include <stdio.h>

int	ft_any(char **tab, int(*f)(char*))
{
	size_t	i;

	i = 0;
	while (tab[i])
	{
		if ((*f)(tab[i]))
			return (1);
		i++;
	}
	return (0);
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

// int	main(void)
// {
// 	size_t	i;
// 	char	*tab[] = {"pretty!", "this is a spaced string", NULL};

// 	printf("> array elements:\n");
// 	i = 0;
// 	while (tab[i])
// 	{
// 		printf("%li: %s\n",i, tab[i]);
// 		i++;
// 	}
// 	printf("> is_not_empty: %i\n", ft_any(tab, &is_not_empty));
// 	printf("> has_space: %i\n", ft_any(tab, &has_space));
// 	return (0);
// }
