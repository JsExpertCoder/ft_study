/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnicolau <marvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 18:37:15 by fnicolau          #+#    #+#             */
/*   Updated: 2025/04/28 16:44:26 by fnicolau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_hexdump.h"

static bool	check_option_existence(char **tokens)
{
	size_t	i;

	i = 0;
	while (tokens[i])
	{
		if ((tokens[i][0] == '-'))
		{
			if (ft_strcmp(tokens[i], "-C") == 0)
				return (true);
		}
		i++;
	}
	return (false);
}

int	main(int argc, char **argv)
{
	t_files	*files;
	size_t	final_return;
	bool	use_canonical_style;

	(void)argc;
	final_return = 0;
	files = file_collector(++argv);
	use_canonical_style = check_option_existence(argv);
	if (files == 0)
		final_return = stdin_dump(use_canonical_style);
	else if (files != NULL)
	{
		final_return = files_dump(files, use_canonical_style);
		free(files->paths);
		free(files);
	}
	return (final_return);
}
