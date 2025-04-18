/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnicolau <fnicolau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 20:32:01 by fnicolau          #+#    #+#             */
/*   Updated: 2025/04/12 17:33:45 by fnicolau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	print_error(char *file_path, int fd)
{
	ft_putstr_fd("cat: ", 2);
	ft_putstr_fd(file_path, 2);
	ft_putstr_fd(": ", 2);
	ft_putstr_fd(strerror(errno), 2);
	ft_putstr_fd("\n", 2);
	close(fd);
	return (1);
}
