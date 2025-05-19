/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_advanced_sort_string_tab.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnicolau <marvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 15:50:26 by fnicolau          #+#    #+#             */
/*   Updated: 2025/05/19 16:21:38 by fnicolau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 && (*s1 == *s2))
	{
		s1++;
		s2++;
	}
	return ((unsigned char)*s1 - (unsigned char)*s2);
}

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
	size_t	i;
	size_t	j;
	char	*tmp;
	int		swapped;

	i = 0;
	while (i < get_tab_len(tab) - 1)
	{
		j = 0;
		swapped = 0;
		while (j < get_tab_len(tab) - 1 - i)
		{
			if ((*cmp)(tab[j], tab[j + 1]) > 0)
			{
				tmp = tab[j];
				tab[j] = tab[j + 1];
				tab[j + 1] = tmp;
				swapped = 1;
			}
			j++;
		}
		if (!swapped)
			break ;
		i++;
	}
}

int	main(void)
{
	size_t	i;
	char	*tab[] = {"apple", "apPlE", "banana", "ABC", "42", "Orange", NULL};

	printf("> before sorting:\n");
	i = 0;
	while (tab[i])
	{
		printf("[%li] -> %s\n", i, tab[i]);
		i++;
	}
	ft_advanced_sort_string_tab(tab, &ft_strcmp);
	printf(">  after sorting:\n");
	i = 0;
	while (tab[i])
	{
		printf("[%li] -> %s\n", i, tab[i]);
		i++;
	}
	return (0);
}
