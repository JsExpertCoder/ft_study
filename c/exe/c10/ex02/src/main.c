/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnicolau <marvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 16:47:38 by fnicolau          #+#    #+#             */
/*   Updated: 2025/04/17 21:50:21 by fnicolau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_tail.h"

int	main(int argc, char **argv)
{
	int		j;
	char	**files;
	int		final_return;
	int		bytes_to_read;

	final_return = 0;
	bytes_to_read = option_parser(argv, argc);
	if (bytes_to_read == -1)
		return (-1);
	else if (bytes_to_read)
	{
		printf("> bytes to read: %i\n", bytes_to_read);
		files = files_parser(argv + 1);
		if (files == NULL)
			return (1);
		j = 0;
		while (files[j])
		{
			printf("> files-%i: %s\n", j, files[j]);
			j++;
		}
		free(files);
	}
	return (final_return);
}

// int	main(void)
// {
// 	return (0);
// }