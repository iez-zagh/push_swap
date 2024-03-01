/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iez-zagh <iez-zagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 20:58:53 by iez-zagh          #+#    #+#             */
/*   Updated: 2024/03/01 15:22:58 by iez-zagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort2_3(t_stack *stack)
{
	if (stack->size == 1)
		exit (0);
	if (stack->size == 3)
		sort3(stack);
	else if (stack->size == 2)
	{
		if (stack->top->data > stack->top->next->data)
			ft_sa(&stack->top, 'a');
	}
	else if (stack->size == 4)
		sort_4(stack);
	else
		sort_5(stack);
	free (stack);
}

void	sort3(t_stack *stack_a)
{
	int		b;
	int		c;

	b = stack_a->top->next->data;
	c = stack_a->top->next->next->data;
	if (stack_a->top->data > b && b > c)
	{
		ft_ra(&stack_a->top, 'a');
		ft_sa(&stack_a->top, 'a');
	}
	else if (stack_a->top->data > b && stack_a->top->data > c && c > b)
		ft_ra(&stack_a->top, 'a');
	else if (stack_a->top->data > b && stack_a->top->data < c
		&& c > stack_a->top->data)
		ft_sa(&stack_a->top, 'a');
	else if (stack_a->top->data < b && stack_a->top->data > c && b > c)
		ft_rra(&stack_a->top, 'a');
	else if (stack_a->top->data < b && stack_a->top->data < c && b > c)
	{
		ft_sa(&stack_a->top, 'a');
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
	stack_b = ft_pb(&stack->top, &stack_b);
	indexing(stack);
	sort3(stack);
	stack->top = ft_pa(&stack->top, &stack_b);
}

t_list	*get_min_top(t_stack *stack, t_list *tmp)
{
	int	j;

	j = tmp->index;
	while (j < stack->size && tmp->index_to_m < 0)
	{
		stack->top = ft_rra(&stack->top, 'a');
		j++;
	}
	while (j > 0 && tmp->index_to_m > 0)
	{
		stack->top = ft_ra(&stack->top, 'a');
		j--;
	}
	return (stack->top);
}

t_list	*get_min_top2(t_stack *stack, t_list *tmp)
{
	int	j;

	j = tmp->index;
	while (j < stack->size && tmp->index_to_m < 0)
	{
		stack->top = ft_rra(&stack->top, 'b');
		j++;
	}
	while (j > 0 && tmp->index_to_m > 0)
	{
		stack->top = ft_ra(&stack->top, 'b');
		j--;
	}
	return (stack->top);
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
