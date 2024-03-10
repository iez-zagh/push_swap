/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iez-zagh <iez-zagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 18:25:35 by iez-zagh          #+#    #+#             */
/*   Updated: 2024/03/10 16:53:29 by iez-zagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	f(void)
{
	system("leaks checker");
}

int	main(int ac, char **av)
{
	t_list	*instrucs;
	t_stack	*stack_a;

	if (ac == 1)
		return (1);
	instrucs = NULL;
	stack_a = prepare_stack2(ac, av);
	apply(&instrucs, stack_a);
	sort(instrucs, stack_a);
}

void	print_error2(void)
{
	write(2, RED_TEXT, sizeof(RED_TEXT) - 1);
	write(2, "Error\n", 6);
	write(2, RESET_TEXT, sizeof(RESET_TEXT) - 1);
}

void	free_list3(t_list *list)
{
	t_list	*tmp;

	while (list)
	{
		tmp = list;
		list = list->next;
		free(tmp);
	}
}
