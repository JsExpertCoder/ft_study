/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_collector.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnicolau <marvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 21:44:03 by fnicolau          #+#    #+#             */
/*   Updated: 2025/04/27 22:34:00 by fnicolau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_hexdump.h"

static size_t	get_total_of_files(char **args)
{
	size_t	i;
	size_t	total;

	i = 0;
	total = 0;
	while (args[i])
	{
		if (args[i][0] != '-')
			total++;
		i++;
	}
	return (total);
}

static void	store_file_paths(char **files, char **args)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (args[i])
	{
		if (args[i][0] != '-')
		{
			files[j] = args[i];
			j++;
		}
		i++;
	}
	files[j] = 0;
	return ;
}

t_files	*file_collector(char **args)
{
	t_files	*files;
	size_t	total_of_files;

	total_of_files = 0;
	total_of_files = get_total_of_files(args);
	if (total_of_files == 0)
		return (0);
	files = malloc(sizeof(t_files));
	if (!files)
		return (NULL);
	files->total = total_of_files;
	files->paths = malloc((total_of_files + 1) * sizeof(char *));
	if (!files->paths)
	{
		free(files);
		return (NULL);
	}
	store_file_paths(files->paths, args);
	return (files);
}
