/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iez-zagh <iez-zagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 20:18:32 by iez-zagh          #+#    #+#             */
/*   Updated: 2024/03/12 12:28:02 by iez-zagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	ft_lstadd_back2(t_list **lst, t_list *new)
{
	t_list	*n_adrs;

	if (!new || !lst)
		return ;
	if (*lst)
	{
		n_adrs = ft_lstlast2(*lst);
		n_adrs->next = new;
		new->next = NULL;
		return ;
	}
	*lst = new;
}

t_list	*ft_lstlast2(t_list *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

t_list	*ft_lstnew2(int content)
{
	t_list		*node;

	node = (t_list *)malloc(sizeof(t_list));
	if (!node)
		return (NULL);
	node->data = content;
	node->next = NULL;
	return (node);
}

void	ft_lstadd_front2(t_list **lst, t_list *new)
{
	if (lst && new)
	{
		new->next = *lst;
	}
	if (new)
		*lst = new;
}

void	check_duplicate2(t_list *node, int n)
{
	if (!node)
		return ;
	while (node)
	{
		if (node->data == n)
		{
			print_error2();
			exit (1);
		}
		node = node->next;
	}
}
