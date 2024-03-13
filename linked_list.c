/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iez-zagh <iez-zagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 14:35:44 by iez-zagh          #+#    #+#             */
/*   Updated: 2024/03/11 23:37:01 by iez-zagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*n_adrs;

	if (!new || !lst)
		return ;
	if (*lst)
	{
		n_adrs = ft_lstlast(*lst);
		n_adrs->next = new;
		new->next = NULL;
		return ;
	}
	*lst = new;
}

t_list	*ft_lstlast(t_list *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}

t_list	*ft_lstnew(int content)
{
	t_list		*node;

	node = (t_list *)malloc(sizeof(t_list));
	if (!node)
		return (NULL);
	node->data = content;
	node->next = NULL;
	return (node);
}

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (lst && new)
		new->next = *lst;
	if (new)
		*lst = new;
}

void	check_duplicate(t_list *node, int n)
{
	if (!node)
		return ;
	while (node)
	{
		if (node->data == n)
		{
			print_error();
			exit (1);
		}
		node = node->next;
	}
}
