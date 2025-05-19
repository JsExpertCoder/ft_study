/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_elem.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnicolau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 20:56:43 by fnicolau          #+#    #+#             */
/*   Updated: 2025/05/19 21:31:49 by fnicolau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
// #include <stdio.h>

t_list	*ft_create_elem(void *data)
{
	t_list	*elem;

	elem = malloc(sizeof(t_list));
	if (!elem)
		return (0);
	elem->data = data;
	elem->next = NULL;
	return (elem);
}

// void	print_list(t_list *list)
// {
// 	t_list	*current;

// 	current = list;
// 	while (current != NULL)
// 	{
// 		printf("> %i\n", *(int *)current->data);
// 		current = current->next;
// 	}
// }

// int	main(void)
// {
// 	int		*n1;
// 	int		*n2;
// 	t_list	*head;

// 	n1 = malloc(sizeof(int));
// 	n2 = malloc(sizeof(int));
// 	if (n1 && n2)
// 	{
// 		*n1 = 07;
// 		*n2 = 42;
// 		head = ft_create_elem(n1);
// 		if (head)
// 		{
// 			head->next = ft_create_elem(n2);
// 			print_list(head);
// 			if (head->next)
// 				free(head->next);
// 			free(head);
// 		}
// 		free(n1);
// 		free(n2);
// 	}
// 	return (0);
// }
