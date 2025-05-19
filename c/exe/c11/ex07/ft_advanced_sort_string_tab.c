/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_advanced_sort_string_tab.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnicolau <marvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 15:50:26 by fnicolau          #+#    #+#             */
/*   Updated: 2025/05/19 17:21:47 by fnicolau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>

// int	ft_strcmp(char *s1, char *s2)
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

void	ft_advanced_sort_string_tab(char **tab, int(*cmp)(char *, char *))
{
	int		i;
	int		j;
	int		len;
	char	*tmp;

	i = 0;
	len = get_tab_len(tab);
	while (i < len - 1)
	{
		j = i + 1;
		while (j < len)
		{
			if ((*cmp)(tab[i], tab[j]) > 0)
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
// 	char	*tab[] = {"apple", "apPlE", "", "010", "1", "banana", "ABC", "42", "Orange", "007", NULL};

// 	printf("> before sorting:\n");
// 	i = 0;
// 	while (tab[i])
// 	{
// 		printf("[%li] -> %s\n", i, tab[i]);
// 		i++;
// 	}
// 	ft_advanced_sort_string_tab(tab, &ft_strcmp);
// 	printf(">  after sorting:\n");
// 	i = 0;
// 	while (tab[i])
// 	{
// 		printf("[%li] -> %s\n", i, tab[i]);
// 		i++;
// 	}
// 	return (0);
// }
