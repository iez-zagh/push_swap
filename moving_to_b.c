/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moving_to_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iez-zagh <iez-zagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 13:47:47 by iez-zagh          #+#    #+#             */
/*   Updated: 2024/03/01 15:46:45 by iez-zagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	indexing(t_stack *stack)
{
	int		i;
	t_list	*node;
	int		index;

	stack->size = ft_lstsize(stack->top);
	stack->average_index = stack->size / 2;
	stack->mid_average = (ft_min(stack->top)->data + ft_max(stack->top)->data) / 2;
	index = stack->average_index;
	node = stack->top;
	i = 0;
	while (node)
	{
		if (i <= index)
			node->index_to_m = 1;
		else
			node->index_to_m = -1;
		node->index = i;
		i++;
		node = node->next;
	}
}
