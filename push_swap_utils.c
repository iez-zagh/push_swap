/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iez-zagh <iez-zagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 17:39:51 by iez-zagh          #+#    #+#             */
/*   Updated: 2024/02/17 16:17:22 by iez-zagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	checker(const char *str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i] && (str[i] == ' ' || str[i] == '\t'))
		i++;
	while (str[i])
	{
		if (str[i] == '-' || str[i] == '+')
		{
			if (!(str[i + 1] >= '0' && str[i + 1] <= '9')
				|| (str[i - 1] >= '0' && str[i - 1] <= '9'))
			{
				printf("Error\n");
				exit (1);
			}
		}
		else if (!(str[i] >= '0' && str[i] <= '9')
			&& (str[i] != ' ' && str[i] != '\t'))
		{
			printf("Error\n");
			exit (1);
		}
		i++;
	}
}

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		i++;
	}
	return (i);
}

void	prepare_stack(int ac, char **av)
{
	int	i;
	static	int	numbers;

	i = 1;
	numbers = 0;
	while (i < ac)
	{
		checker(av[i]);
		i++;
	}
}

int	count_words(const char *str)
{
	int	i;
	int	k;
	int	counter;

	i = 0;
	k = 0;
	counter = 0;
	while (str[i])
	{
		if (str[i] != ' ' && str[i] != '\t')
		{
			counter++;
			while (str[i] && str[i] != ' ' && str[i] != '\t')
			{
				i++;
			}
			i--;
		}
		i++;
	}
	return (counter);
}

// void	ft_split(char *str)
// {
// 	int		n_words;
// 	int		index;
// 	int		i;
// 	char	**res;
// 	char	res1;
// 	int 	j;

// 	i = 0;
// 	index = 0;
// 	n_words = count_words(str);
// 	res = malloc(sizeof(char *) * n_words);
// 	while (str[i])
// 	{
// 		if (str[i] != ' ' && str[i] != '\t')
// 		{
// 			while(str[i] && str[i] != ' ' && str[i] != '\t')
// 			{
// 				index++;
// 				i++;
// 			}
// 			i--;
// 		}
// 		i++;
// 	}
// }
