/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prepare_stack_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iez-zagh <iez-zagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 18:31:02 by iez-zagh          #+#    #+#             */
/*   Updated: 2024/03/05 19:09:56 by iez-zagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

t_stack	*prepare_stack2(int ac, char **av)
{
	int				i;
	static char		*numbers;
	char			**res;

	i = 1;
	while (i < ac)
	{
		if_just_spaces2(av[i]);
		checker2(av[i]);
		numbers = ft_strjoin2(numbers, av[i], ac, i);
		i++;
	}
	res = ft_split2(numbers);
	free (numbers);
	return (filling2(res));
}

void	if_just_spaces2(char *s)
{
	int	i;

	i = 0;
	while (s[i] && s[i] == ' ')
		i++;
	if (ft_strlen2(s) == i)
	{
		print_error2();
		exit (1);
	}
}

void	checker2(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '-' || str[i] == '+')
		{
			if (!(str[i + 1] >= '0' && str[i + 1] <= '9')
				|| (str[i - 1] >= '0' && str[i - 1] <= '9'))
			{
				print_error2();
				exit (1);
			}
		}
		else if (!(str[i] >= '0' && str[i] <= '9') && (str[i] != ' '))
		{
			print_error2();
			exit (1);
		}
		i++;
	}
}
