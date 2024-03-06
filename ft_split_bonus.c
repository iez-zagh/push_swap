/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iez-zagh <iez-zagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 12:16:04 by iez-zagh          #+#    #+#             */
/*   Updated: 2024/03/04 21:20:12 by iez-zagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	count_count(const char *str)
{
	int		i;
	int		j;
	int		word;

	i = 0;
	j = 0;
	word = 0;
	while (str[i])
	{
		if (str[i] != ' ' && j == 0)
		{
			j = 1;
			word++;
		}
		else if (str[i] == ' ')
		{
			j = 0;
		}
		i++;
	}
	return (word);
}

void	ft_int(int *a, int *b, int *c)
{
	*a = 0;
	*b = 0;
	*c = 0;
}

char	**ft_free2(char **p, int j)
{
	int	i;

	i = 0;
	while (i < j)
	{
		free(p[i]);
		p[i] = NULL;
		i++;
	}
	free(p);
	p = 0;
	return (NULL);
}

char	**fill(char const *str, char **p, int num_words)
{
	int	douz;
	int	len;
	int	j;

	ft_int(&douz, &len, &j);
	while (j < num_words)
	{
		if (*str != ' ' && douz == 0)
		{
			douz = 1;
			len = 0;
		}
		else if ((*str == ' ' || *str == '\0') && douz == 1)
		{
			p[j] = ft_substr2(str - len, 0, len);
			if (!p[j])
				return (ft_free2(p, j));
			douz = 0;
			j++;
		}
		len++;
		str++;
	}
	return (&p[j]);
}

char	**ft_split2(char const *s)
{
	char	**p;
	char	**tmp;
	int		kalimat;

	if (!s)
		return (NULL);
	kalimat = count_count(s);
	p = malloc((kalimat + 1) * sizeof(char *));
	if (!p)
		return (NULL);
	tmp = fill(s, p, kalimat);
	if (tmp == NULL)
		return (NULL);
	*tmp = 0;
	return (p);
}
