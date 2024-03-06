/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_more_6.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iez-zagh <iez-zagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 11:57:49 by iez-zagh          #+#    #+#             */
/*   Updated: 2024/03/04 17:57:42 by iez-zagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move_to_b(t_stack *sstack_a)
{
	t_list	*stack_b;
	t_list	*stack_a;
	t_stack	*sstack_b;
	int		j;
	int		mid;

	sstack_b = malloc(sizeof(t_stack));
	if (!sstack_b)
		exit (0);
	j = sstack_a->size;
	stack_a = sstack_a->top;
	stack_b = NULL;
	mid = sstack_a->size;
	pushing_to_b(&sstack_a, &stack_a, &stack_b);
	sstack_b->top = stack_b;
	sstack_a->top = stack_a;
	sorting(sstack_a, sstack_b);
}

void	geting_targets(t_stack *sstack_a, t_stack *sstack_b)
{
	t_list	*stack_a;
	t_list	*stack_b;
	t_list	*tmp;

	stack_a = sstack_a->top;
	stack_b = sstack_b->top;
	while (stack_b)
	{
		tmp = find_target(stack_b->data, stack_a);
		if (!tmp)
			stack_b->target = ft_min(stack_a);
		else
			stack_b->target = tmp;
		stack_b = stack_b->next;
	}
}

t_list	*find_target(int y, t_list *stack)
{
	t_list	*tmp;

	tmp = NULL;
	while (stack)
	{
		if ((stack->data > y) && (!tmp || (stack->data < tmp->data)))
			tmp = stack;
		stack = stack->next;
	}
	if (!tmp)
		return (NULL);
	return (tmp);
}

void	sorting(t_stack *sstack_a, t_stack *sstack_b)
{
	t_list	*tmp;

	indexing(sstack_b);
	sort3(sstack_a);
	while (sstack_b->size > 0)
	{
		indexing(sstack_b);
		indexing(sstack_a);
		geting_targets(sstack_a, sstack_b);
		count_cost(sstack_b, sstack_a);
		tmp = ft_min_cost(sstack_b);
		get_min_top2(sstack_a, sstack_b, tmp);
		sstack_a->top = ft_pa(&sstack_a->top, &sstack_b->top);
		sstack_b->size--;
	}
	indexing(sstack_a);
	sstack_a->top = get_min_top(sstack_a, ft_min(sstack_a->top));
	free(sstack_b);
	free(sstack_a);
}

void	pushing_to_b(t_stack **sstack_a, t_list **stack_a, t_list **stack_b)
{
	int		j;
	int		mid;

	mid = (*sstack_a)->size;
	j = (*sstack_a)->size;
	while (mid > 0 && j > 3)
	{
		if ((*stack_a)->data > (*sstack_a)->mid_average)
			*stack_a = ft_ra(stack_a, 'a');
		else
		{
			*stack_b = ft_pb(stack_a, stack_b);
			j--;
		}
		mid--;
	}
	while (j > 3)
	{
		*stack_b = ft_pb(stack_a, stack_b);
		j--;
	}
}
