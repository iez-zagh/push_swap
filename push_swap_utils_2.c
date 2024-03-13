/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iez-zagh <iez-zagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 17:27:09 by iez-zagh          #+#    #+#             */
/*   Updated: 2024/03/11 23:30:29 by iez-zagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_if_sorted(t_list *begin)
{
	while (begin && begin->next)
	{
		if (begin->data > begin->next->data)
			return (1);
		begin = begin->next;
	}
	return (0);
}
