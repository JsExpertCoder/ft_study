/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cat.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnicolau <fnicolau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 14:59:58 by fnicolau          #+#    #+#             */
/*   Updated: 2025/04/12 18:08:06 by fnicolau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CAT_H
# define FT_CAT_H

# define BUFFER_SIZE 3000

# include <fcntl.h>		// for open()
# include <unistd.h>	// for read(), write(), close()
# include <errno.h>		// for errno
# include <string.h>	// for strerror()
# include <libgen.h>	// for basename()
# include <stdbool.h>	// for "true", "false"

int		ft_cat(char *file_path, int fd);
void	ft_putstr_fd(char *str, int fd);
int		print_error(char *file_path, int fd);
void	ft_putchar_fd(const char c, int fd);

#endif
