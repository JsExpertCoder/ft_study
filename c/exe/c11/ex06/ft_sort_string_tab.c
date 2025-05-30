/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_string_tab.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnicolau <marvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 12:36:38 by fnicolau          #+#    #+#             */
/*   Updated: 2025/05/19 14:17:43 by fnicolau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>

// int	ft_strcmp(const char *s1, const char *s2)
// {
// 	while (*s1 && (*s1 == *s2))
// 	{
// 		s1++;
// 		s2++;
// 	}
// 	return ((unsigned char)*s1 - (unsigned char)*s2);
// }

size_t	get_tab_len(char **tab)
{
	size_t	i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}

void	ft_sort_string_tab(char **tab)
{
	size_t	i;
	size_t	j;
	size_t	len;
	char	*tmp;

	i = 0;
	len = get_tab_len(tab);
	while (i < len - 1)
	{
		j = i + 1;
		while (j < len)
		{
			if (ft_strcmp(tab[i], tab[j]) > 0)
			{
				tmp = tab[i];
				tab[i] = tab[j];
				tab[j] = tmp;
			}
			j++;
		}
		i++;
	}
}

// int	main(void)
// {
// 	size_t	i;
// 	char	*tab[] = {"apple", "apPlE", "banana", "ABC", "42", "Orange", NULL};

// 	printf("> before sorting:\n");
// 	i = 0;
// 	while (tab[i])
// 	{
// 		printf("[%li] -> %s\n", i, tab[i]);
// 		i++;
// 	}
// 	ft_sort_string_tab(tab);
// 	printf(">  after sorting:\n");
// 	i = 0;
// 	while (tab[i])
// 	{
// 		printf("[%li] -> %s\n", i, tab[i]);
// 		i++;
// 	}
// 	return (0);
// }
