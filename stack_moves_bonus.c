/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_moves_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iez-zagh <iez-zagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 09:59:39 by iez-zagh          #+#    #+#             */
/*   Updated: 2024/03/09 17:46:57 by iez-zagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	ft_sa2(t_list **stack)
{
	t_list	*list;

	if (!*stack || !stack)
		return ;
	list = *stack;
	if (list && list->next)
		swap(&list->data, &list->next->data);
}

void	ft_ss2(t_list **stack_a, t_list **stack_b)
{
	ft_sa2(stack_a);
	ft_sa2(stack_b);
}

void	ft_rr2(t_list *stack_a, t_list *stack_b)
{
	ft_ra2(stack_a);
	ft_ra2(stack_b);
}

int	ft_search(t_list *node, int *tab, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (tab[i] == node->data)
			return (i);
		i++;
	}
	return (0);
}
