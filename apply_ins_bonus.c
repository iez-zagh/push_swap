/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_ins_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iez-zagh <iez-zagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 22:37:09 by iez-zagh          #+#    #+#             */
/*   Updated: 2024/03/06 20:40:44 by iez-zagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	apply(t_list **ins)
{
	int		u;
	char	*res;
	t_list	*tmp;

	*ins = malloc(sizeof(t_list));
	(*ins)->data = -100;
	(*ins)->next = NULL;
	res = get_next_line(0);
	while (res)
	{
		u = checking(res);
		if (u == 0)
		{
			write(2, "Error\n", 6);
			exit (0);
		}
		ft_lstadd_back2(ins, ft_lstnew2(u));
		free(res);
		res = get_next_line(0);
	}
	tmp = *ins;
	(*ins) = (*ins)->next;
	free (tmp);
	print_list2(*ins);
	exit (0);
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
	t_stack	*sstack_b;
	t_list	*stack_b;

	sstack_b = malloc(sizeof(t_stack));
	stack_b = malloc(sizeof(t_list));
	stack_b->next = NULL;
	sstack_b->top = stack_b;
	while (ins)
	{
		if(ins->data == 1)
			ft_rra2(stack_a);
		else if (ins->data == 2)
			ft_rra2(stack_a);
		else if (ins->data == 3)
			ft_rrr2(stack_a, sstack_b);
		else if (ins->data == 4)
			stack_a->top = ft_ra2(&stack_a->top);
		else if (ins->data == 5)
			sstack_b->top = ft_ra2(&sstack_b->top);
		else if (ins->data == 6)
		{
			stack_a->top = ft_ra2(&stack_a->top);
			sstack_b->top = ft_ra2(&sstack_b->top);
		}
		else if (ins->data == 7)
			ft_sa2(&stack_a->top);
		else if (ins->data == 8)
			ft_sa2(&sstack_b->top);
		else if (ins->data == 9)
			ft_ss2(&stack_a->top, &sstack_b->top);
		else if (ins->data == 10)
			stack_a->top = ft_pa2(&stack_a->top, &sstack_b->top);
		else if (ins->data == 11)
			sstack_b->top = ft_pa2(&stack_a->top, &sstack_b->top);
		ins = ins->next;
	}
	if (!check_if_sorted2(&stack_a->top))
	{
		free(stack_a);
		free(sstack_b);
		write(1, "OK\n", 3);
	}
	else
		write(1, "KO\n", 3);
}