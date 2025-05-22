/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_clear.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnicolau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 22:33:41 by fnicolau          #+#    #+#             */
/*   Updated: 2025/05/22 23:01:25 by fnicolau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
// #include <stdio.h>

void	ft_list_clear(t_list *begin_list, void (*free_fct)(void *))
{
	t_list	*tmp;

	while (begin_list)
	{
		tmp = begin_list->next;
		if (free_fct)
			(*free_fct)(begin_list->data);
		free(begin_list);
		begin_list = tmp;
	}
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

// void	ft_list_push_back(t_list **begin_list, void *data)
// {
// 	t_list	*tmp;

// 	if (!*begin_list)
// 		*begin_list = ft_create_elem(data);
// 	else
// 	{
// 		tmp = *begin_list;
// 		while (tmp->next)
// 			tmp = tmp->next;
// 		tmp->next = ft_create_elem(data);
// 	}
// }

// void	free_allocated_data(void *data)
// {
// 	free(data);
// }

// void	print_list(t_list *current)
// {
// 	printf("\n");
// 	if (!current)
// 		printf("> THE LIST IS EMPTY :(");
// 	else
// 	{
// 		printf("currents in the List:\n");
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

// /**
// * 1 - the current version frees every node but leaves head
// * dangling.
// * 2 - you nedd to use a program such as "valgrind" to
// * check if all heap block where freed and no leaks are
// * possible. run this program like "valgrind --leak-check=full ./program"
// * and see the results.
// */
// int	main(void)
// {
// 	t_list	*head;
// 	int		*a_ptr;
// 	int		*b_ptr;
// 	int		*c_ptr;

// 	a_ptr = malloc(sizeof(int));
// 	b_ptr = malloc(sizeof(int));
// 	c_ptr = malloc(sizeof(int));
// 	*a_ptr = 4;
// 	*b_ptr = 45;
// 	*c_ptr = 456;
// 	head = NULL;
// 	ft_list_push_back(&head, a_ptr);
// 	ft_list_push_back(&head, b_ptr);
// 	ft_list_push_back(&head, c_ptr);
// 	print_list(head);
// 	ft_list_clear(head, &free_allocated_data);
// 	//ft_list_clear(head, NULL); // is also valid, but results in memory leak
// 	return (0);
// }
