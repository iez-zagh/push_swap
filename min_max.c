/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   min_max.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iez-zagh <iez-zagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 11:59:46 by iez-zagh          #+#    #+#             */
/*   Updated: 2024/03/12 01:38:32 by iez-zagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_max(t_list *node)
{
	t_list	*max;

	max = node;
	node = node->next;
	while (node)
	{
		if (node->data > max->data)
			max = node;
		node = node->next;
	}
	return (max);
}

t_list	*ft_min(t_list *node)
{
	t_list	*min;

	min = node;
	node = node->next;
	while (node)
	{
		if (node->data < min->data)
			min = node;
		node = node->next;
	}
	return (min);
}

t_list	*ft_min_cost(t_stack *stack)
{
	t_list	*node;
	t_list	*min;

	node = stack->top;
	min = node;
	node = node->next;
	while (node)
	{
		if (node->cost < min->cost)
			min = node;
		node = node->next;
	}
	return (min);
}

void	print_error(void)
{
	write(2, RED_TEXT, sizeof(RED_TEXT) - 1);
	write(2, "Error\n", 6);
	write(2, RESET_TEXT, sizeof(RESET_TEXT) - 1);
}

void	sort_the_rest(t_stack *stack_a, t_stack *stack_b, int j, t_list *tmp)
{
	while (j < stack_a->size && tmp->target->index_to_m < 0)
	{
		ft_rra(stack_a, 'a');
		j++;
	}
	while (j > 0 && tmp->target->index_to_m > 0)
	{
		ft_ra(&stack_a->top, 'a');
		j--;
	}
	j = tmp->index;
	while (j < stack_b->size && tmp->index_to_m < 0)
	{
		ft_rra(stack_b, 'b');
		j++;
	}
	while (j > 0 && tmp->index_to_m > 0)
	{
		ft_ra(&stack_b->top, 'b');
		j--;
	}
}
