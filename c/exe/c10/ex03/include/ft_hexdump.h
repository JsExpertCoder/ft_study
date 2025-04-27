/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexdump.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnicolau <marvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 18:59:26 by fnicolau          #+#    #+#             */
/*   Updated: 2025/04/27 22:37:57 by fnicolau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_HEXDUMP_H
# define FT_HEXDUMP_H

# include <stdio.h>	// debug purpose
# include <stdlib.h> // malloc and free
# include <stdbool.h> // "true", "false"

typedef struct s_files
{
	size_t	total;
	char	**paths;
}	t_files;

t_files	*file_collector(char **args);
int		ft_strcmp(const char *s1, const char *s2);

#endif