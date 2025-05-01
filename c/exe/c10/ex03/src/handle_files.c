/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   files_dump.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnicolau <marvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 15:04:36 by fnicolau          #+#    #+#             */
/*   Updated: 2025/04/28 17:06:29 by fnicolau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_hexdump.h"

unsigned int	files_dump(t_files *files, bool use_canonical_style)
{
	int		fd;
	size_t	i;
	size_t	final_return;

	final_return = 0;
	if (use_canonical_style)
	{
	}
	i = 0;
	while (files->paths[i])
	{
		fd = open(files->paths[i], O_RDONLY);
		if (fd == -1)
			final_return = print_error(fd, files->paths[i], errno);
		else
		{
			printf("> file-%li: %s\n", i, files->paths[i]);
			close(fd);
		}
		i++;
	}
	return (final_return);
}
