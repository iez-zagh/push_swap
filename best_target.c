/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   best_target.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iez-zagh <iez-zagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 13:23:46 by iez-zagh          #+#    #+#             */
/*   Updated: 2024/03/13 11:29:26 by iez-zagh         ###   ########.fr       */
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
	t_list	*_stack;
	int		size;

	size = ft_lstsize(stack->top);
	_stack = stack->top;
	while (_stack)
	{
		if (_stack->index_to_m == 1)
		{
			_stack->cost = _stack->index;
			_stack->cost2 = _stack->index;
		}
		else
		{
			_stack->cost = size - _stack->index;
			_stack->cost2 = size - _stack->index;
		}
		_stack = _stack->next;
	}
}

int	reducing(t_stack *stack_a, t_stack *stack_b, t_list **tmp)
{
	int	j;

	if ((*tmp)->target->cost == (*tmp)->cost2)
	{
		j = (*tmp)->cost2;
		while (j > 0)
		{
			ft_rrr(stack_a, stack_b);
			j--;
		}
		return (1);
	}
	else
		moving(stack_a, stack_b, tmp);
	return (0);
}

void	moving(t_stack *stack_a, t_stack *stack_b, t_list **tmp)
{
	int	j;

	if ((*tmp)->cost2 < (*tmp)->target->cost)
	{
		j = (*tmp)->index;
		while (j < stack_b->size)
		{
			ft_rrr(stack_a, stack_b);
			j++;
		}
		(*tmp)->index = 0;
		(*tmp)->index_to_m = 0;
	}
	else
	{
		j = (*tmp)->target->index;
		while (j < stack_a->size)
		{
			ft_rrr(stack_a, stack_b);
			j++;
		}
		(*tmp)->target->index = 0;
		(*tmp)->target->index_to_m = 0;
	}
}
