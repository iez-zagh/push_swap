/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_ins_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iez-zagh <iez-zagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 22:37:09 by iez-zagh          #+#    #+#             */
/*   Updated: 2024/03/05 22:55:21 by iez-zagh         ###   ########.fr       */
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
	while (1)
	{
		res = get_next_line(0);
		if (!res)
			break ;
		u = checking(res);
		free(res);
		if (u == 0)
		{
			write(2, "Error\n", 6);
			exit (0);
		}
		ft_lstadd_back2(ins, ft_lstnew2(u));
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
