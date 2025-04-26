/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexdump.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnicolau <marvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 18:59:26 by fnicolau          #+#    #+#             */
/*   Updated: 2025/04/25 19:02:06 by fnicolau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_HEXDUMP_H
# define FT_HEXDUMP_H

# include <fcntl.h>		// for open()
# include <unistd.h>	// for read(), write(), close()
# include <errno.h>		// for errno
# include <string.h>	// for strerror()
# include <stdlib.h>	// for malloc, free
# include <libgen.h>	// for basename()
# include <stdbool.h>	// for "true", "false"
# include <stdio.h>		// for debug purpose

#endif