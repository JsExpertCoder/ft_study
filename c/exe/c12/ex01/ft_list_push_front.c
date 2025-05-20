/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_front.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnicolau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 17:55:14 by fnicolau          #+#    #+#             */
/*   Updated: 2025/05/20 18:32:19 by fnicolau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdio.h>

void	ft_list_push_front(t_list **begin_list, void *data)
{
	t_list	*new_elem;

	if (!*begin_list)
		*begin_list = ft_create_elem(data);
	else
	{
		new_elem = ft_create_elem(data);
		if (new_elem)
		{
			new_elem->next = *begin_list;
			*begin_list = new_elem;
		}
	}
}

int	*get_data_ptr(int n)
{
	int	*ptr;

	ptr = malloc(sizeof(int));
	*ptr = n;
	return (ptr);
}

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

void	print_list(t_list *node)
{
	if (!node)
		printf("> THE LIST IS EMPTY :(\n\n");
	else
	{
		printf("Nodes in the List:\n");
		while (node)
		{
			if (node->data)
				printf("%i --> ", *(int *)node->data);
			else
				printf("(null) --> ");
			node = node->next;
		}
	}
}

int	main(void)
{
	t_list	*head;

	head = NULL;
	print_list(head);
	ft_list_push_front(&head, get_data_ptr(1));
	ft_list_push_front(&head, NULL);
	ft_list_push_front(&head, get_data_ptr(42));
	ft_list_push_front(&head, get_data_ptr(82));
	ft_list_push_front(&head, NULL);
	ft_list_push_front(&head, get_data_ptr(1337));
	ft_list_push_front(&head, NULL);
	ft_list_push_front(&head, get_data_ptr(0));
	ft_list_push_front(&head, NULL);
	print_list(head);
	return (0);
}
