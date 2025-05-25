/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_at.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnicolau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 15:11:23 by fnicolau          #+#    #+#             */
/*   Updated: 2025/05/25 15:50:02 by fnicolau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
// #include <stdio.h>

t_list	*ft_list_at(t_list *begin_list, unsigned int nbr)
{
	size_t	i;
	t_list	*searched;

	i = 0;
	searched = NULL;
	while (begin_list && i <= nbr)
	{
		if (i == nbr)
		{
			searched = begin_list;
			break ;
		}
		i++;
		begin_list = begin_list->next;
	}
	return (searched);
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

// void	print_node(t_list *node)
// {
// 	if (node)
// 		printf("%i --> ", *(int *)node->data);
// 	else
// 		printf("> null");
// }

// void	print_list(t_list *current)
// {
// 	printf("> list items: \n");
// 	while (current)
// 	{
// 		print_node(current);
// 		current = current->next;
// 	}
// 	printf("\n\n");
// }

// int	main(void)
// {
// 	int		a;
// 	int		b;
// 	t_list	*head;
// 	t_list	*node2;
// 	t_list	*searched_node;

// 	b = 42;
// 	a = 1337;
// 	node2 = NULL;
// 	head = ft_create_elem(&a);
// 	if (head)
// 	{
// 		node2 = ft_create_elem(&b);
// 		head->next = node2;
// 	}
// 	print_list(head);

// 	searched_node = ft_list_at(head, 0);
// 	printf("> node at position (0): ");
// 	print_node(searched_node);

// 	searched_node = ft_list_at(head, 1);
// 	printf("\n\n> node at position (1): ");
// 	print_node(searched_node);

// 	searched_node = ft_list_at(head, 2);
// 	printf("\n\n> node at position (2): ");
// 	print_node(searched_node);
// 	free(node2);
// 	free(head);
// 	return (0);
// }
