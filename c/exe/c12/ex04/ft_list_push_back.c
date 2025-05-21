/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_back.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnicolau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 15:15:00 by fnicolau          #+#    #+#             */
/*   Updated: 2025/05/21 15:47:30 by fnicolau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>
#include "ft_list.h"

void	ft_list_push_back(t_list **begin_list, void *data)
{
	t_list	*tmp;

	if (!*begin_list)
		*begin_list = ft_create_elem(data);
	else
	{
		tmp = *begin_list;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = ft_create_elem(data);
	}
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
// 		return (0);
// 	elem->data = data;
// 	elem->next = NULL;
// 	return (elem);
// }

// void	print_list(t_list *current)
// {
// 	if (!current)
// 		printf("> THE LIST IS EMPTY :(");
// 	else
// 	{
// 		while (current)
// 		{
// 			if (current->data)
// 				printf("%i --> ", *(int *)current->data);
// 			else
// 				printf("(null) --> ");
// 			current = current->next;
// 		}
// 	}
// 	printf("\n\n");
// }

// int	*get_data_ptr(int n)
// {
// 	int	*ptr;

// 	ptr = malloc(sizeof(int));
// 	*ptr = n;
// 	return (ptr);
// }

// int	main(void)
// {
// 	t_list	*head;

// 	head = NULL;
// 	printf("> BEGIN:\n");
// 	print_list(head);

// 	ft_list_push_front(&head, get_data_ptr(1));
// 	ft_list_push_front(&head, NULL);
// 	ft_list_push_front(&head, get_data_ptr(42));
// 	printf("> AFTER PUSH_FRONT(1, NULL, 42):\n");
// 	print_list(head);

// 	ft_list_push_back(&head, get_data_ptr(82));
// 	ft_list_push_back(&head, NULL);
// 	ft_list_push_back(&head, get_data_ptr(1337));
// 	printf("> AFTER PUSH_BACK(82, NULL, 1337):\n");
// 	print_list(head);

// 	ft_list_push_front(&head, get_data_ptr(111));
// 	ft_list_push_back(&head, get_data_ptr(222));
// 	printf("> AFTER FRONT(111) and BACK(222):\n");
// 	print_list(head);
// 	return (0);
// }
