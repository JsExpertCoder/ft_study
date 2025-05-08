/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexdump.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnicolau <marvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 18:59:26 by fnicolau          #+#    #+#             */
/*   Updated: 2025/05/08 22:48:53 by fnicolau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_HEXDUMP_H
# define FT_HEXDUMP_H

# include <errno.h> // errno
# include <fcntl.h> // open()
# include <string.h> // strerror
# include <stdio.h>	// debug purpose
# include <stdbool.h> // "true", "false"
# include <stdlib.h> // malloc() and free()
# include <unistd.h> // read(), close(), write(), size_t, ssize_t

# define STDIN 0

typedef struct s_files
{
	size_t	total;
	char	**paths;
}	t_files;

typedef struct s_buffer
{
	char	*current;
	char	*previous;
	size_t	bytes_rd;
	size_t	offset;
	size_t	total_bytes_rd;
}	t_buffer;

size_t	ft_strlen(const char *s);
t_files	*file_collector(char **args);
void	reset_buffer(t_buffer *buffer);
void	ft_putstr_fd(char *str, int fd);
bool	print_hexa(size_t len, size_t nbr);
char	*ft_strcpy(char *dst, const char *src);
int		ft_strcmp(const char *s1, const char *s2);
bool	print_error(int fd, char *filepath, int error);
bool	handle_stdin(t_buffer *buffer, bool canonical_style);
bool	ft_hexdump(t_buffer *buffer, bool canonical_style);
bool	handle_files(t_buffer *buffer, t_files *files, bool canonical_style);
#endif