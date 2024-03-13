/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iez-zagh <iez-zagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 20:58:53 by iez-zagh          #+#    #+#             */
/*   Updated: 2024/03/11 23:31:23 by iez-zagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort2_3(t_stack *stack)
{
	if (stack->size == 1)
		exit(0);
	if (stack->size == 3)
		sort3(stack);
	else if (stack->size == 2)
	{
		if (stack->top->data > stack->top->next->data)
			ft_sa(stack->top, 'a');
	}
	else if (stack->size == 4)
		sort_4(stack);
	else
		sort_5(stack);
	free_list(stack->top);
	free(stack);
}

void	sort3(t_stack *stack_a)
{
	int	b;
	int	c;

	b = stack_a->top->next->data;
	c = stack_a->top->next->next->data;
	if (stack_a->top->data > b && b > c)
	{
		ft_ra(&stack_a->top, 'a');
		ft_sa(stack_a->top, 'a');
	}
	else if (stack_a->top->data > b && stack_a->top->data > c && c > b)
		ft_ra(&stack_a->top, 'a');
	else if (stack_a->top->data > b
		&& stack_a->top->data < c && c > stack_a->top->data)
		ft_sa(stack_a->top, 'a');
	else if (stack_a->top->data < b && stack_a->top->data > c && b > c)
		ft_rra(stack_a, 'a');
	else if (stack_a->top->data < b && stack_a->top->data < c && b > c)
	{
		ft_sa(stack_a->top, 'a');
		ft_ra(&stack_a->top, 'a');
	}
}

void	sort_4(t_stack *stack)
{
	t_list	*stack_b;
	t_list	*tmp;

	stack_b = NULL;
	tmp = ft_min(stack->top);
	get_min_top(stack, tmp);
	if (!check_if_sorted(stack->top))
		return ;
	stack_b = ft_pb(&stack->top, &stack_b);
	indexing(stack);
	sort3(stack);
	stack->top = ft_pa(&stack->top, &stack_b);
}

void	get_min_top2(t_stack *stack_a, t_stack *stack_b, t_list *tmp)
{
	int	j;

	if (tmp->index_to_m == -1 && tmp->target->index_to_m == -1
		&& tmp->cost != 0 && tmp->target->cost != 0)
	{
		if (reducing(stack_a, stack_b, &tmp) == 1)
			return ;
		indexing(stack_b);
		indexing(stack_a);
	}
	j = tmp->target->index;
	sort_the_rest(stack_a, stack_b, j, tmp);
}

void	sort_5(t_stack *stack)
{
	t_list	*stack_b;
	t_list	*tmp;

	stack_b = NULL;
	tmp = ft_min(stack->top);
	get_min_top(stack, tmp);
	stack_b = ft_pb(&stack->top, &stack_b);
	indexing(stack);
	sort_4(stack);
	stack->top = ft_pa(&stack->top, &stack_b);
}
