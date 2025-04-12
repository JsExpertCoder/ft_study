/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnicolau <fnicolau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 15:14:43 by fnicolau          #+#    #+#             */
/*   Updated: 2025/04/12 16:37:49 by fnicolau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	main(int ac, char **av)
{
	int	i;
	int	fd;
	int	final_return;

	i = 1;
	final_return = 0;
	while (i < ac)
	{
		fd = open(av[i], O_RDONLY);
		if (fd == -1)
			final_return = print_error(av[i], fd);
		else
			if (ft_cat(av[i], fd) == -1)
				final_return = -1;
		close(fd);
		i++;
	}
	return (final_return);
}
