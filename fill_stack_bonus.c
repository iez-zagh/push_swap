/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_stack_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iez-zagh <iez-zagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 20:09:22 by iez-zagh          #+#    #+#             */
/*   Updated: 2024/03/10 11:42:52 by iez-zagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

t_stack	*filling2(char **res)
{
	t_list	*node;
	t_stack	*stack_a;
	int		i;

	i = 1;
	node = malloc(sizeof(t_list));
	if (!node)
		return (NULL);
	node->data = ft_atoi2(res[0]);
	node->next = NULL;
	stack_a = malloc (sizeof(t_stack));
	if (!stack_a)
		return (NULL);
	stack_a->top = node;
	free (res[0]);
	while (res[i])
	{
		check_duplicate2(node, ft_atoi2(res[i]));
		ft_lstadd_back2(&node, ft_lstnew2(ft_atoi2(res[i])));
		free(res[i++]);
	}
	free (res);
	return (stack_a);
}

int	ft_lstsize2(t_list *node)
{
	int	size;

	if (!node)
		return (0);
	size = 0;
	while (node)
	{
		size++;
		node = node->next;
	}
	return (size);
}
