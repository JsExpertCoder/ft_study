/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnicolau <fnicolau@student.42luanda.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 07:38:16 by fnicolau          #+#    #+#             */
/*   Updated: 2024/11/13 08:29:44 by fnicolau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strrev(char *str)
{
	size_t	i;
	size_t	end;
	char	temp;
	
	i = 0;
	end = 0;

	if (!str)
		return (NULL);
	while (str[end])
		end++;
	end--;
	while(i < end)
	{
		temp = str[i];
		str[i] = str[end];
		str[end] = temp;
		i++;
		end--;
	}
	return (str);
}

int	main(void)
{
	char	str[] = "ab#cdefghijklmnopqrstuvwxyz";
	printf("b: %s\n", str);
	printf("a: %s\n", ft_strrev(str));
}
