/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tail.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnicolau <marvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 16:49:24 by fnicolau          #+#    #+#             */
/*   Updated: 2025/04/21 23:13:39 by fnicolau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_TAIL_H
# define FT_TAIL_H

# include <fcntl.h>		// for open()
# include <unistd.h>	// for read(), write(), close()
# include <errno.h>		// for errno
# include <string.h>	// for strerror()
# include <stdlib.h>	// for malloc, free
# include <libgen.h>	// for basename()
# include <stdbool.h>	// for "true", "false"
# include <stdio.h>		// for debug purpose

typedef struct s_files
{
	size_t	total;
	char	**paths;
}	t_files;

typedef struct s_circular_buffer
{
	size_t	size;
	size_t	index;
	char	*content;
	size_t	total_bytes_read;
}	t_circular_buffer;

size_t	ft_strlen(const char *s);
int		ft_atoi(const char *nptr);
t_files	*files_parser(char **args);
void	ft_putstr_fd(char *str, int fd);
char	*ft_strcpy(char *dst, const char *src);
void	ft_putchar_fd(const char c, int fd);
int		print_error(char *file_path, int fd);
int		option_parser(char **args, size_t length);
int		ft_strcmp(const char *s1, const char *s2);
int		ft_tail(char *file_path, int fd, size_t bytes_to_read);
int		ft_strncmp(const char *s1, const char *s2, size_t n);

#endif