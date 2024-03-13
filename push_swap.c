/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iez-zagh <iez-zagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 17:39:43 by iez-zagh          #+#    #+#             */
/*   Updated: 2024/03/12 12:28:10 by iez-zagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	if (ac == 1)
		return (0);
	prepare_stack(ac, av);
}

t_list	*get_min_top(t_stack *stack, t_list *tmp)
{
	int	j;

	j = tmp->index;
	while (j < stack->size && tmp->index_to_m < 0)
	{
		ft_rra(stack, 'a');
		j++;
	}
	while (j > 0 && tmp->index_to_m > 0)
	{
		ft_ra(&stack->top, 'a');
		j--;
	}
	return (stack->top);
}

t_list	*ft_before_last(t_list *begin)
{
	if (!begin)
		return (NULL);
	while (begin->next->next)
		begin = begin->next;
	return (begin);
}
