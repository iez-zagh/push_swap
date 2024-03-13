/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iez-zagh <iez-zagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 19:57:00 by iez-zagh          #+#    #+#             */
/*   Updated: 2024/03/11 23:31:16 by iez-zagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	filling(char **res)
{
	t_list	*node;
	t_stack	*stack_a;
	int		i;

	i = 1;
	node = malloc(sizeof(t_list));
	if (!node)
		return ;
	node->data = ft_atoi(res[0]);
	node->next = NULL;
	stack_a = malloc (sizeof(t_stack));
	if (!stack_a)
		return ;
	stack_a->top = node;
	free (res[0]);
	while (res[i])
	{
		check_duplicate(node, ft_atoi(res[i]));
		ft_lstadd_back(&node, ft_lstnew(ft_atoi(res[i])));
		free (res[i++]);
	}
	sort0(stack_a);
}

void	sort0(t_stack *stack_a)
{
	if (!check_if_sorted(stack_a->top))
		exit (0);
	indexing(stack_a);
	if (stack_a->size <= 5)
		sort2_3(stack_a);
	else
		move_to_b(stack_a);
}
