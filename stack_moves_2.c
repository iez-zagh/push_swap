/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_moves_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iez-zagh <iez-zagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 17:25:58 by iez-zagh          #+#    #+#             */
/*   Updated: 2024/03/04 18:14:27 by iez-zagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_pa(t_list **stack_a, t_list **stack_b)
{
	t_list	*tmp;

	if (!stack_b || !*stack_b)
		return (NULL);
	tmp = *stack_b;
	(*stack_b) = (*stack_b)->next;
	tmp->next = NULL;
	ft_lstadd_front(stack_a, tmp);
	write(1, "pa\n", 3);
	return (*stack_a);
}

void	ft_rra(t_stack *sstack, char a_or_b)
{
	t_list	*tmp;
	int		swap;
	t_list	*list;
	t_list	*stack;

	stack = sstack->top;
	tmp = ft_lstlast(stack);
	swap = tmp->data;
	ft_before_last(stack)->next = NULL;
	free(tmp);
	list = malloc(sizeof(t_list));
	list->data = swap;
	ft_lstadd_front(&stack, list);
	if (a_or_b == 'a')
		write(1, "rra\n", 4);
	else if (a_or_b == 'b')
		write(1, "rrb\n", 4);
	sstack->top = list;
}

void	ft_rrr(t_stack *stack_a, t_stack *stack_b)
{
	ft_rra(stack_a, 'y');
	ft_rra(stack_b, 'w');
	write(1, "rrr\n", 4);
}

t_list	*ft_pb(t_list **stack_a, t_list **stack_b)
{
	t_list	*tmp;

	if (!stack_a || !*stack_a)
		return (NULL);
	tmp = *stack_a;
	*stack_a = (*stack_a)->next;
	tmp->next = NULL;
	ft_lstadd_front(stack_b, tmp);
	write(1, "pb\n", 3);
	return (*stack_b);
}

t_list	*ft_ra(t_list **stack, char a_or_b)
{
	t_list	*first;
	t_list	*last;
	t_list	*second;

	first = *stack;
	second = first->next;
	last = ft_lstlast(*stack);
	last->next = first;
	*stack = second;
	first->next = NULL;
	if (a_or_b == 'a')
		write(1, "ra\n", 3);
	else if (a_or_b == 'b')
		write(1, "rb\n", 3);
	return (*stack);
}
