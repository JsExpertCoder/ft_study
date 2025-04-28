/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexdump.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnicolau <marvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 18:59:26 by fnicolau          #+#    #+#             */
/*   Updated: 2025/04/28 16:26:12 by fnicolau         ###   ########.fr       */
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

t_files			*file_collector(char **args);
size_t			ft_strlen(const char *s);
void			ft_putstr_fd(char *str, int fd);
unsigned int	stdin_dump(bool use_canonical_style);
int				ft_strcmp(const char *s1, const char *s2);
unsigned int	print_error(int fd, char *filepath, int error);
unsigned int	files_dump(t_files *files, bool use_canonical_style);
#endif