/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_last.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnicolau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 14:41:58 by fnicolau          #+#    #+#             */
/*   Updated: 2025/05/21 15:03:57 by fnicolau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
// #include <stdio.h>

t_list	*ft_list_last(t_list *begin_list)
{
	if (begin_list)
		while (begin_list->next)
			begin_list = begin_list->next;
	return (begin_list);
}

// t_list	*ft_create_elem(void *data)
// {
// 	t_list	*elem;

// 	elem = malloc(sizeof(t_list));
// 	if (!elem)
// 		return (NULL);
// 	elem->data = data;
// 	elem->next = NULL;
// 	return (elem);
// }

// void	print_list(t_list *current)
// {
// 	while (current)
// 	{
// 		if (current->data)
// 			printf("> %i\n", *(int *)current->data);
// 		else
// 			printf("> null\n");
// 		current = current->next;
// 	}
// }

// int	main(void)
// {
// 	int		n;
// 	t_list	*head;
// 	t_list	*node2;

// 	n = 1337;
// 	head = ft_create_elem(NULL);
// 	node2 = ft_create_elem(&n);
// 	head->next = node2;
// 	printf("> The last element is:\n");
// 	print_list(ft_list_last(head));
// 	free(head);
// 	free(node2);
// 	return (0);
// }
