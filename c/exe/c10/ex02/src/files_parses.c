/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   files_parses.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnicolau <marvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 20:40:19 by fnicolau          #+#    #+#             */
/*   Updated: 2025/04/20 17:04:14 by fnicolau         ###   ########.fr       */
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

static size_t	get_total_of_files(char **args)
{
	size_t	i;
	size_t	total_of_files;

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

static void	populate_files(char **args, char **paths)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (args[i])
	{
		if (validate_file(args[i], args[i - 1]))
		{
			paths[j] = args[i];
			j++;
		}
		i++;
	}
	paths[j] = 0;
	return ;
}

t_files	*files_parser(char **args)
{
	t_files	*files;
	size_t	total_of_files;

	total_of_files = get_total_of_files(args);
	if (total_of_files == 0)
		return (0);
	files = malloc(sizeof(t_files));
	if (files == NULL)
		return (NULL);
	files->total = total_of_files;
	files->paths = malloc((total_of_files + 1) * sizeof(char *));
	if (!files->paths)
		return (NULL);
	populate_files(args, files->paths);
	return (files);
}
