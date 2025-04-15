/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   option_parser.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnicolau <fnicolau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 19:02:26 by fnicolau          #+#    #+#             */
/*   Updated: 2025/04/15 19:34:27 by fnicolau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_tail.h"

static int	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	return (0);
}

static int	parser(char *bytes)
{
	char	*bytes_p;

	bytes_p = bytes;
	while (*bytes_p)
	{
		if (!ft_isdigit(*bytes_p))
		{
			ft_putstr_fd("tail: invalid number of bytes: ‘", 2);
			ft_putstr_fd(bytes, 2);
			ft_putstr_fd("’", 2);
			return (-1);
		}
		bytes_p++;
	}
	return (ft_atoi(bytes));
}

void	print_option_usage(void)
{
	ft_putstr_fd("tail: option requires an argument -- 'c'\n", 2);
	ft_putstr_fd("Try 'tail --help' for more information.", 2);
	return ;
}

int	validate_option(char *option, char *passible_option_param )
{
	int	bytes_to_read;

	if (ft_strlen(option) >= 3)
	{
		bytes_to_read = parser(option + 2);
		if (bytes_to_read == -1)
			return (-1);
	}
	else if (passible_option_param)
	{
		bytes_to_read = parser(passible_option_param);
		if (bytes_to_read == -1)
			return (-1);
	}
	else
	{
		print_option_usage();
		return (-1);
	}
	return (bytes_to_read);
}

int	option_parser(char **args, size_t length)
{
	size_t	i;
	int		bytes_to_read;

	i = 1;
	bytes_to_read = -1;
	while (i < length)
	{
		if (ft_strncmp(args[i], "-c", 2) == 0)
		{
			bytes_to_read = validate_option(args[i], args[i + 1]);
			if (bytes_to_read == -1)
				return (-1);
		}
		i++;
	}
	return (bytes_to_read);
}
