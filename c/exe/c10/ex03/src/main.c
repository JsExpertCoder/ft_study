/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnicolau <marvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 18:37:15 by fnicolau          #+#    #+#             */
/*   Updated: 2025/04/27 22:33:37 by fnicolau         ###   ########.fr       */
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
	size_t	i;
	t_files	*files;
	bool	with_option;

	(void)argc;
	files = file_collector(++argv);
	with_option = check_option_existence(argv);
	if (files == 0)
	{
		printf("> read from stdin.\n");
		printf("> style: %s\n", (with_option ? "canonical" : "default"));
	}
	else if (files != NULL)
	{
		i = 0;
		printf("> style: %s\n", (with_option ? "canonical" : "default"));
		while (files->paths[i])
		{
			printf("> file-%li: %s\n", i, files->paths[i]);
			i++;
		}
	}
	free(files);
	return (0);
}
