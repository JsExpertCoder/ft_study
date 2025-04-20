/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnicolau <marvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 16:47:38 by fnicolau          #+#    #+#             */
/*   Updated: 2025/04/20 19:50:52 by fnicolau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_tail.h"

static void	print_file_header(char *file_path)
{
	ft_putstr_fd("==> ", 1);
	ft_putstr_fd(file_path, 1);
	ft_putstr_fd(" <==", 1);
	ft_putstr_fd("\n", 1);
	return ;
}

static int	tail_from_files(t_files *files, int bytes_to_read)
{
	size_t	i;
	int		fd;
	int		final_return;
	bool	print_header;

	i = 0;
	print_header = files->total > 1;
	while (files->paths[i])
	{
		fd = open(files->paths[i], O_RDONLY);
		if (fd == -1)
			final_return = print_error(files->paths[i], fd);
		else
		{
			if (print_header)
				print_file_header(files->paths[i]);
			final_return = ft_tail(files->paths[i], fd, bytes_to_read);
			if (print_header && i < files->total - 1)
				ft_putstr_fd("\n", 1);
		}
		i++;
	}
	free(files->paths);
	free(files);
	return (final_return);
}

int	main(int argc, char **argv)
{
	t_files	*files;
	int		final_return;
	int		bytes_to_read;

	final_return = 0;
	bytes_to_read = option_parser(argv, argc);
	if (bytes_to_read == -1)
		return (1);
	else if (bytes_to_read)
	{
		files = files_parser(argv + 1);
		if (files == 0)
			final_return = ft_tail("stdin", 0, bytes_to_read);
		else if (files != NULL)
			final_return = tail_from_files(files, bytes_to_read);
	}
	return (final_return);
}
