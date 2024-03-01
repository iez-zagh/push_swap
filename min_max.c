/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   min_max.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iez-zagh <iez-zagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 11:59:46 by iez-zagh          #+#    #+#             */
/*   Updated: 2024/03/01 15:35:43 by iez-zagh         ###   ########.fr       */
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
	write(1, RED_TEXT, sizeof(RED_TEXT) - 1);
	write(1, "Error\n", 6);
	write(1, RESET_TEXT, sizeof(RESET_TEXT) - 1);
}