/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_ins_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iez-zagh <iez-zagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 22:37:09 by iez-zagh          #+#    #+#             */
/*   Updated: 2024/03/12 13:26:39 by iez-zagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	apply(t_list **ins, t_stack *stack_a)
{
	int		u;
	char	*res;
	t_list	*tmp;

	res = get_next_line(0);
	while (res)
	{
		u = checking(res);
		free(res);
		if (u == 0)
		{
			print_error2();
			free(stack_a);
			exit (1);
		}
		ft_lstadd_back2(ins, ft_lstnew2(u));
		res = get_next_line(0);
	}
	tmp = *ins;
	(*ins) = (*ins)->next;
	free (tmp);
}

int	checking(char *res)
{
	if (res[0] == 'r' && res[1] == 'r' && res[2] == 'a' && ft_strlen2(res) == 4)
		return (1);
	if (res[0] == 'r' && res[1] == 'r' && res[2] == 'b' && ft_strlen2(res) == 4)
		return (2);
	if (res[0] == 'r' && res[1] == 'r' && res[2] == 'r' && ft_strlen2(res) == 4)
		return (3);
	if (res[0] == 'r' && res[1] == 'a' && ft_strlen2(res) == 3)
		return (4);
	if (res[0] == 'r' && res[1] == 'b' && ft_strlen2(res) == 3)
		return (5);
	if (res[0] == 'r' && res[1] == 'r' && ft_strlen2(res) == 3)
		return (6);
	if (res[0] == 's' && res[1] == 'a' && ft_strlen2(res) == 3)
		return (7);
	if (res[0] == 's' && res[1] == 'b' && ft_strlen2(res) == 3)
		return (8);
	if (res[0] == 's' && res[1] == 's' && ft_strlen2(res) == 3)
		return (9);
	if (res[0] == 'p' && res[1] == 'a' && ft_strlen2(res) == 3)
		return (10);
	if (res[0] == 'p' && res[1] == 'b' && ft_strlen2(res) == 3)
		return (11);
	return (0);
}

void	sort(t_list *ins, t_stack *stack_a)
{
	t_stack	*stack_b;
	t_list	*sstack_b;
	t_list	*tmp;

	tmp = ins;
	sstack_b = NULL;
	stack_b = malloc(sizeof(t_stack));
	if (!stack_b)
		return ;
	stack_b->top = sstack_b;
	while (ins)
	{
		sorting(stack_a, stack_b, ins->data);
		ins = ins->next;
	}
	if (!check_if_sorted2(stack_a->top) && ft_lstsize2(stack_b->top) == 0
		&& ft_lstsize2(stack_a->top) > 0)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	free_list2(stack_a);
	free_list2(stack_b);
	free_list3(tmp);
}

void	free_list2(t_stack *node)
{
	t_list	*tmp;
	t_list	*tmp2;

	tmp2 = node->top;
	while (tmp2)
	{
		tmp = tmp2;
		tmp2 = tmp2->next;
		free(tmp);
	}
	free(node);
}

void	sorting(t_stack *stack_a, t_stack *stack_b, int ins)
{
	if (ins == 1)
		ft_rra2(stack_a);
	else if (ins == 2)
		ft_rra2(stack_b);
	else if (ins == 3)
		ft_rrr2(stack_a, stack_b);
	else if (ins == 4)
		stack_a->top = ft_ra2(stack_a->top);
	else if (ins == 5)
		stack_b->top = ft_ra2(stack_b->top);
	else if (ins == 6)
	{
		stack_a->top = ft_ra2(stack_a->top);
		stack_b->top = ft_ra2(stack_b->top);
	}
	else if (ins == 7)
		ft_sa2(&stack_a->top);
	else if (ins == 8)
		ft_sa2(&stack_b->top);
	else if (ins == 9)
		ft_ss2(&stack_a->top, &stack_b->top);
	else if (ins == 10)
		stack_a->top = ft_pa2(&stack_a->top, &stack_b->top);
	else if (ins == 11)
		stack_b->top = ft_pb2(&stack_a->top, &stack_b->top);
}
