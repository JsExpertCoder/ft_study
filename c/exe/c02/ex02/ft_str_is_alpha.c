/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnicolau <marvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 11:51:51 by fnicolau          #+#    #+#             */
/*   Updated: 2025/01/15 12:13:10 by fnicolau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_alpha(char *str)
{
	char	is_lower;
	char	is_upper;

	while (*str)
	{
		is_lower = (*str >= 'a' && *str <= 'z');
		is_upper = (*str >= 'A' && *str <= 'Z');
		if (!is_lower && !is_upper)
			return (0);
		str++;
	}
	return (1);
}
