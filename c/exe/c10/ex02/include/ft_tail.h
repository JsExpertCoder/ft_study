/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tail.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnicolau <fnicolau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 16:49:24 by fnicolau          #+#    #+#             */
/*   Updated: 2025/04/15 19:42:19 by fnicolau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_TAIL_H
# define FT_TAIL_H

# include <fcntl.h>		// for open()
# include <unistd.h>	// for read(), write(), close()
# include <errno.h>		// for errno
# include <string.h>	// for strerror()
# include <libgen.h>	// for basename()
# include <stdbool.h>	// for "true", "false"

int		ft_atoi(const char *nptr);
size_t	ft_strlen(const char *s);
void	ft_putstr_fd(char *str, int fd);
void	ft_putchar_fd(const char c, int fd);
int		print_error(char *file_path, int fd);
int		option_parser(char **args, size_t length);
int		ft_strcmp(const char *s1, const char *s2);
int		ft_tail(char *file_path, int fd, size_t bytes_to_read);
int		ft_strncmp(const char *s1, const char *s2, size_t n);

#endif