/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iez-zagh <iez-zagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 19:57:00 by iez-zagh          #+#    #+#             */
/*   Updated: 2024/03/01 16:14:24 by iez-zagh         ###   ########.fr       */
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
	stack_a = malloc (sizeof(t_list));
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
	if (!check_if_sorted(&stack_a->top))
		exit (0);
	indexing(stack_a);
	if (stack_a->size <= 5)
		sort2_3(stack_a);
	else
		move_to_b(stack_a);
}

void	bubblesort(t_stack *stack)
{
	t_list	*node;
	int		*arr;
	int		i;

	node = stack->top;
	i = 0;
	arr = malloc(sizeof(int) * stack->size);
	while (node)
	{
		arr[i++] = node->data;
		node = node->next;
	}
	arr = sort_arr(arr, stack->size);
	node = stack->top;
	while (node)
	{
		node->index_b = ft_search(node, arr, stack->size);;
		node = node->next;
	}
	free (arr);
}
