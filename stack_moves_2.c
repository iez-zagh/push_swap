/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_moves_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iez-zagh <iez-zagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 17:25:58 by iez-zagh          #+#    #+#             */
/*   Updated: 2024/03/01 12:27:03 by iez-zagh         ###   ########.fr       */
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

t_list	*ft_rra(t_list **stack, char a_or_b)
{
	t_list		*tmp;
	int			swap;
	t_list		*list;

	tmp = ft_lstlast(*stack);
	swap = tmp->data;
	ft_before_last(*stack)->next = NULL;
	free (tmp);
	list = malloc(sizeof(t_list));
	list->data = swap;
	ft_lstadd_front(stack, list);
	if (a_or_b == 'a')
		write(1, "rra\n", 4);
	else if (a_or_b == 'b')
		write(1, "rrb\n", 4);
	return (list);
}

void	ft_rrr(t_list **stack_a, t_list **stack_b)
{
	ft_rra(stack_a, 'a');
	ft_rra(stack_b, 'b');
	write(1, "rrr\n", 4);
}

t_list	*ft_pb(t_list **stack_a, t_list **stack_b)
{
	t_list		*tmp;

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

t_list	*ft_before_last(t_list *begin)
{
	if (!begin)
		return (NULL);
	while (begin->next->next)
		begin = begin->next;
	return (begin);
}
