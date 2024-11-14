/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strpbrk.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnicolau <fnicolau@student.42luanda.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 06:29:45 by fnicolau          #+#    #+#             */
/*   Updated: 2024/11/13 07:07:30 by fnicolau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

//#include <stdef.h>

char	*ft_strpbrk(const char *s1, const char *s2)
{
	int		j;

	if (!s1 || !s2)
		return (NULL);

	while (s1)
	{
		j = 0;
		while (s2[j])
		{
			if (*s1 == s2[j])
				return (char *)s1;
			j++;
		}
		s1++;
	}
	return (NULL);
}

int main(void)
{
    const char *str1 = "Hello, World!";
    const char *str2 = NULL;

    char *result = ft_strpbrk(str1, str2);

    if (result)
        printf("First matching character: '%c' at position %li\n", *result, result - str1);
    else
        printf("No matching characters found.\n");

    return 0;
}
