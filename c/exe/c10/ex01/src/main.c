/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnicolau <fnicolau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 15:14:43 by fnicolau          #+#    #+#             */
/*   Updated: 2025/04/12 18:07:21 by fnicolau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	main(int ac, char **av)
{
	int	i;
	int	fd;
	int	final_return;

	final_return = 0;
	if (ac == 1)
		return (ft_cat("stdin", 0));
	i = 1;
	while (i < ac)
	{
		fd = open(av[i], O_RDONLY);
		if (fd == -1)
			final_return = print_error(av[i], fd);
		else
			final_return = ft_cat(av[i], fd);
		i++;
	}
	return (final_return);
}
