/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnicolau <marvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 16:47:38 by fnicolau          #+#    #+#             */
/*   Updated: 2025/04/17 23:38:56 by fnicolau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_tail.h"

int	main(int argc, char **argv)
{
	int		j;
	t_files	*files;
	int		final_return;
	int		bytes_to_read;

	final_return = 0;
	bytes_to_read = option_parser(argv, argc);
	if (bytes_to_read == -1)
		return (-1);
	else if (bytes_to_read)
	{
		files = files_parser(argv + 1);
		if (files == NULL)
			return (1);
		printf("> bytes to read: %i\n", bytes_to_read);
		printf("> total of files: %i\n", files->total);
		j = 0;
		while (files->paths[j])
		{
			printf("> files-%i: %s\n", j, files->paths[j]);
			free(files->paths[j]);
			j++;
		}
		free(files->paths);
		free(files);
	}
	return (final_return);
}
