/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_file.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnicolau <marvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 22:51:30 by fnicolau          #+#    #+#             */
/*   Updated: 2025/03/27 18:54:18 by fnicolau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_DISPLAY_FILE_H
# define FT_DISPLAY_FILE_H

# include <fcntl.h>
# include <unistd.h>
# include <stdbool.h>

int		ft_display_file(char *file_path);
void	ft_putstr_fd(int fd, char *str);

#endif
