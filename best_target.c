/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   best_target.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iez-zagh <iez-zagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 13:23:46 by iez-zagh          #+#    #+#             */
/*   Updated: 2024/02/29 22:06:00 by iez-zagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	count_cost(t_stack *sstack_b, t_stack *sstack_a)
{
	t_list	*stack_b;

	stack_b = sstack_b->top;
	geting_count(sstack_a);
	geting_count(sstack_b);
	while (stack_b)
	{
		stack_b->cost += stack_b->target->cost;
		stack_b = stack_b->next;
	}
}

void	geting_count(t_stack *stack)
{
	t_list	*stack_;
	int		size;

	size = ft_lstsize(stack->top);
	stack_ = stack->top;
	while (stack_)
	{
		if (stack_->index_to_m == 1)
			stack_->cost = stack_->index;
		else
			stack_->cost = size - stack_->index;
		stack_ = stack_->next;
	}
}