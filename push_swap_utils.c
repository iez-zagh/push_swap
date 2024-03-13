/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iez-zagh <iez-zagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 17:39:51 by iez-zagh          #+#    #+#             */
/*   Updated: 2024/03/12 00:25:50 by iez-zagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_the_smallest(char	*s)
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

long	ft_atoi(char *s)
{
	int		sign;
	long	res;
	int		i;

	if (!check_the_smallest(s))
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
			print_error();
			exit (1);
		}
	}
	return (res * sign);
}

void	if_just_spaces(char *s)
{
	int	i;

	i = 0;
	while (s[i] && s[i] == ' ')
		i++;
	if (ft_strlen(s) == i)
	{
		print_error();
		exit (1);
	}
}

void	checker(const char *str)
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
				print_error();
				exit (1);
			}
		}
		else if (!(str[i] >= '0' && str[i] <= '9') && (str[i] != ' '))
		{
			print_error();
			exit (1);
		}
		i++;
	}
}

void	prepare_stack(int ac, char **av)
{
	int				i;
	static char		*numbers;
	char			**res;

	i = 1;
	while (i < ac)
	{
		if_just_spaces(av[i]);
		checker(av[i]);
		numbers = ft_strjoin(numbers, av[i], ac, i);
		i++;
	}
	res = ft_split(numbers);
	free (numbers);
	filling(res);
	free (res);
}
