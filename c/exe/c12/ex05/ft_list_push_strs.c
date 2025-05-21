/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_strs.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnicolau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 15:56:32 by fnicolau          #+#    #+#             */
/*   Updated: 2025/05/21 16:58:28 by fnicolau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
// #include <stdio.h>

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

t_list	*ft_list_push_strs(int size, char **strs)
{
	int		i;
	t_list	*head;

	i = 0;
	head = NULL;
	while (i < size)
	{
		ft_list_push_front(&head, strs[i]);
		i++;
	}
	return (head);
}

// void	print_list(t_list *current)
// {
// 	if (!current)
// 		printf("> THE LIST IS EMPTY :(");
// 	else
// 	{
// 		while (current)
// 		{
// 			if (current->data)
// 				printf("%s --> ", (char *)current->data);
// 			else
// 				printf("(null) --> ");
// 			current = current->next;
// 		}
// 	}
// 	printf("\n\n");
// }

// int	main(void)
// {
// 	t_list	*head;
// 	int		size;
// 	char	*strs[] = {"1337 is", "the", "same as", "42", ":)"};

// 	head = NULL;
// 	size = sizeof(strs) / sizeof(strs[0]);
// 	printf("> BEFORE ft_list_push_strs:\n");
// 	print_list(head);
// 	head = ft_list_push_strs(size, strs);
// 	printf("> AFTER ft_list_push_strs:\n");
// 	print_list(head);
// 	return (0);
// }
