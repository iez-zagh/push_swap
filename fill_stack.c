/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iez-zagh <iez-zagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 19:57:00 by iez-zagh          #+#    #+#             */
/*   Updated: 2024/02/17 20:57:59 by iez-zagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*fill_stack_a(char *str, int size)
{
	int				i;
	static t_list	*stack_a;

	i = 0;
	while (str[i])
	{
		i++;
		size--;
	}
	return (stack_a);
}
