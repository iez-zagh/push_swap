/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_moves.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iez-zagh <iez-zagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 10:39:34 by iez-zagh          #+#    #+#             */
/*   Updated: 2024/03/11 23:16:07 by iez-zagh         ###   ########.fr       */
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

void	ft_sa(t_list *stack, char a_or_b)
{
	t_list	*list;

	if (!stack)
		return ;
	list = stack;
	if (list && list->next)
	{
		swap(&list->data, &list->next->data);
		if (a_or_b == 'a')
			write(1, "sa\n", 3);
		else if (a_or_b == 'b')
			write(1, "sb\n", 3);
	}
}
