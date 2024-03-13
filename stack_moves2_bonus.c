/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_moves2_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iez-zagh <iez-zagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 09:46:18 by iez-zagh          #+#    #+#             */
/*   Updated: 2024/03/12 01:28:52 by iez-zagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

t_list	*ft_pa2(t_list **stack_a, t_list **stack_b)
{
	t_list	*tmp;

	if (!stack_b || !*stack_b || ft_lstsize2(*stack_b) == 0)
		return (*stack_a);
	tmp = *stack_b;
	(*stack_b) = (*stack_b)->next;
	tmp->next = NULL;
	ft_lstadd_front2(stack_a, tmp);
	return (*stack_a);
}

void	ft_rra2(t_stack *sstack)
{
	t_list	*tmp;
	t_list	*stack;

	if (!sstack || !sstack->top || ft_lstsize2(sstack->top) <= 1)
		return ;
	stack = sstack->top;
	tmp = ft_lstlast2(stack);
	ft_before_last2(stack)->next = NULL;
	ft_lstadd_front2(&stack, tmp);
	sstack->top = tmp;
}

void	ft_rrr2(t_stack *stack_a, t_stack *stack_b)
{
	ft_rra2(stack_a);
	ft_rra2(stack_b);
}

t_list	*ft_pb2(t_list **stack_a, t_list **stack_b)
{
	t_list	*tmp;

	if (!stack_a || !*stack_a || ft_lstsize2(*stack_a) == 0)
		return (NULL);
	tmp = *stack_a;
	*stack_a = (*stack_a)->next;
	tmp->next = NULL;
	ft_lstadd_front2(stack_b, tmp);
	return (*stack_b);
}

t_list	*ft_ra2(t_list *stack)
{
	t_list	*first;
	t_list	*last;
	t_list	*second;

	if (!stack || !stack->next || ft_lstsize2(stack) <= 1)
		return (stack);
	first = stack;
	second = first->next;
	last = ft_lstlast2(stack);
	last->next = first;
	stack = second;
	first->next = NULL;
	return (stack);
}
