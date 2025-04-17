/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   files_parses.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnicolau <marvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 20:40:19 by fnicolau          #+#    #+#             */
/*   Updated: 2025/04/17 21:49:53 by fnicolau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_tail.h"

static bool	validate_file(char *file, char *arg_before_file)
{
	bool	simple_option;
	bool	complete_option;

	if (file[0] != '-')
	{
		simple_option = ft_strncmp(arg_before_file, "-c", 2) == 0;
		complete_option = simple_option && ft_strlen(arg_before_file) > 2;
		if (!simple_option || complete_option)
			return (true);
	}
	return (false);
}

static int	get_total_of_files(char **args)
{
	int	i;
	int	total_of_files;

	i = 0;
	total_of_files = 0;
	while (args[i])
	{
		if (validate_file(args[i], args[i - 1]))
			total_of_files++;
		i++;
	}
	return (total_of_files);
}

char	**files_parser(char **args)
{
	int		i;
	int		j;
	char	**files;
	int		total_of_files;

	i = 1;
	files = NULL;
	total_of_files = 0;
	total_of_files = get_total_of_files(args);
	if (total_of_files > 0)
	{
		files = (char **)malloc((total_of_files + 1) * sizeof(char *));
		if (files == NULL)
			return (NULL);
		i = 0;
		j = 0;
		while (args[i])
		{
			if (validate_file(args[i], args[i - 1]))
			{
				files[j] = args[i];
				j++;
			}
			i++;
		}
		files[j] = 0;
	 }
	return (files);
}

// int	main(void)
// {
// 	return (0);
// }