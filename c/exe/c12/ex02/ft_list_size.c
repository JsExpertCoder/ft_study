/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnicolau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 18:43:08 by fnicolau          #+#    #+#             */
/*   Updated: 2025/05/20 19:10:10 by fnicolau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
// #include <stdio.h>

int	ft_list_size(t_list *begin_list)
{
	int	size;

	size = 0;
	while (begin_list)
	{
		size++;
		begin_list = begin_list->next;
	}
	return (size);
}

// void	ft_list_push_front(t_list **begin_list, void *data)
// {
// 	t_list	*new_elem;

// 	if (!*begin_list)
// 		*begin_list = ft_create_elem(data);
// 	else
// 	{
// 		new_elem = ft_create_elem(data);
// 		if (new_elem)
// 		{
// 			new_elem->next = *begin_list;
// 			*begin_list = new_elem;
// 		}
// 	}
// }

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
// 	size_t	i;

// 	i = 0;
// 	while (current)
// 	{
// 		if (current->data)
// 			printf("[%li] -> %i\n", i, *(int *)current->data);
// 		else
// 			printf("[%li] -> null\n", i);
// 		i++;
// 		current = current->next;
// 	}
// }

// int	*get_elem(int n)
// {
// 	int	*ptr;

// 	ptr = malloc(sizeof(int));
// 	*ptr = n;
// 	return (ptr);
// }

// int	main(void)
// {
// 	t_list	*head;
// 	int		list_size;

// 	head = ft_create_elem(get_elem(1337));
// 	ft_list_push_front(&head, get_elem(42));
// 	ft_list_push_front(&head, get_elem(345));
// 	ft_list_push_front(&head, get_elem(823));
// 	ft_list_push_front(&head, get_elem(647));
// 	print_list(head);
// 	list_size = ft_list_size(head);
// 	printf("> list-size: %i", list_size);
// 	return (0);
// }
