/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iez-zagh <iez-zagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 20:11:45 by iez-zagh          #+#    #+#             */
/*   Updated: 2024/03/11 23:31:57 by iez-zagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	check_the_smallest2(char	*s)
{
	char	*d;
	int		i;

	i = 0;
	d = "-2147483648";
	while (d[i] || s[i])
	{
		if (d[i] != s[i])
			return (1);
		i++;
	}
	return (0);
}

long	ft_atoi2(char *s)
{
	int		sign;
	long	res;
	int		i;

	if (!check_the_smallest2(s))
		return (-2147483648);
	sign = 1;
	res = 0;
	i = 0;
	if (s[i] == '-' || s[i] == '+')
	{
		if (s[i++] == '-')
			sign *= -1;
	}
	while (s[i])
	{
		res = res * 10 + s[i++] - '0';
		if (res < 0 || res > 2147483647)
		{
			print_error2();
			exit (1);
		}
	}
	return (res * sign);
}

int	check_if_sorted2(t_list *begin)
{
	while (begin && begin->next)
	{
		if (begin->data > begin->next->data)
			return (1);
		begin = begin->next;
	}
	return (0);
}

t_list	*ft_before_last2(t_list *begin)
{
	if (!begin)
		return (NULL);
	while (begin->next->next)
		begin = begin->next;
	return (begin);
}
