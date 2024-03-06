/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_moves.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iez-zagh <iez-zagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 10:39:34 by iez-zagh          #+#    #+#             */
/*   Updated: 2024/03/04 18:13:24 by iez-zagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	ft_sa(t_list **stack, char a_or_b)
{
	t_list	*list;

	if (!*stack || !stack)
		return ;
	list = *stack;
	if (list && list->next)
	{
		swap(&list->data, &list->next->data);
		if (a_or_b == 'a')
			write(1, "sa\n", 3);
		else if (a_or_b == 'b')
			write(1, "sb\n", 3);
	}
}

void	ft_ss(t_list **stack_a, t_list **stack_b)
{
	ft_sa(stack_a, 'a');
	ft_sa(stack_b, 'b');
	write(1, "ss\n", 3);
}

void	ft_rr(t_list **stack_a, t_list **stack_b)
{
	ft_ra(stack_a, 'a');
	ft_ra(stack_b, 'b');
	write(1, "rr\n", 3);
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
