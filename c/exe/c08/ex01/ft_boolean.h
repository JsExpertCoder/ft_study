/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_boolean.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnicolau <fnicolau@student.42luanda.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 15:55:12 by fnicolau          #+#    #+#             */
/*   Updated: 2024/11/22 17:26:37 by fnicolau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_BOOLEAN_H
# define FT_BOOLEAN_H

# include <unistd.h>

# define SUCCESS 0
# define EVEN_MSG "I have an even number of arguments.\n"
# define ODD_MSG "I have an odd number of arguments.\n"

# define EVEN(nbr) ((nbr) % 2 == 0)

typedef enum e_bool
{
	TRUE = 1,
	FALSE = 0
}	t_bool;

void	ft_putstr(char *str);
t_bool	ft_is_even(int nbr);

#endif
