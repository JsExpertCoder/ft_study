/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cat.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnicolau <fnicolau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 15:53:37 by fnicolau          #+#    #+#             */
/*   Updated: 2025/04/12 16:30:54 by fnicolau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_cat(char *file_path, int fd)
{
	ssize_t	bytes_read;
	char	buffer[BUFFER_SIZE];

	while (true)
	{
		bytes_read = read(fd, &buffer, BUFFER_SIZE);
		if (bytes_read == -1)
			return (print_error(file_path, fd));
		else if (bytes_read > 0)
			write(1, &buffer, bytes_read);
		else
			break ;
	}
	return (1);
}
