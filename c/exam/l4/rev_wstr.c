/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_wstr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnicolau <marvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 13:25:25 by fnicolau          #+#    #+#             */
/*   Updated: 2025/01/07 16:33:00 by fnicolau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

// 32 == space and 9 == tab
int	is_delimiter(char c)
{
	return (c == 32 || c == 9);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

// print a word of a strint based on its start and its end
void	print_word(char *str, int start, int end)
{
	while (str[start] && (start <= end))
		write(1, &str[start++], 1);
}

void	rev_wstr(char *str)
{
	int	i;
	int	end_of_string;
	int	end_of_a_word;
	int	start_of_a_word;

	end_of_string = ft_strlen(str) - 1;
	i = end_of_string;
	while (i >= 0 && str[i])
	{
		while (is_delimiter(str[i]))
			write(1, &str[i--], 1);
		end_of_a_word = i;
		while (i >= 0 && !(is_delimiter(str[i])))
		{
			if (is_delimiter(str[--i]) || i < 0)
			{
				start_of_a_word = i + 1;
				print_word(str, start_of_a_word, end_of_a_word);
			}
		}
	}
}

int	main(int ac, char **av)
{
	if (ac == 2)
		rev_wstr(av[1]);
	write(1, "\n", 1);
	return (0);
}
