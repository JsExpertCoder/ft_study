/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cat.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnicolau <fnicolau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 14:59:58 by fnicolau          #+#    #+#             */
/*   Updated: 2025/04/12 16:08:55 by fnicolau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CAT_H
# define FT_CAT_H

# define BUFFER_SIZE 3000

# include <fcntl.h>
# include <errno.h>
# include <string.h>
# include <unistd.h>
# include <stdbool.h>

int		ft_cat(char *file_path, int fd);
void	ft_putstr_fd(char *str, int fd);
int		print_error(char *file_path, int fd);
void	ft_putchar_fd(const char c, int fd);

#endif
