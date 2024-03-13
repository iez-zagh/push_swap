/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iez-zagh <iez-zagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 12:16:04 by iez-zagh          #+#    #+#             */
/*   Updated: 2024/03/10 20:50:33 by iez-zagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	ft_int(int *n1, int *n2, int *n3)
{
	*n1 = 0;
	*n2 = 0;
	*n3 = 0;
}

char	**ft_free(char **p, int j)
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
	int	skip;
	int	len;
	int	j;

	ft_int(&skip, &len, &j);
	while (j < num_words)
	{
		if (*str != ' ' && skip == 0)
		{
			skip = 1;
			len = 0;
		}
		else if ((*str == ' ' || *str == '\0') && skip == 1)
		{
			p[j] = ft_substr(str - len, 0, len);
			if (!p[j])
				return (ft_free(p, j));
			skip = 0;
			j++;
		}
		len++;
		str++;
	}
	return (&p[j]);
}

char	**ft_split(char const *s)
{
	char	**p;
	char	**tmp;
	int		words;

	if (!s)
		return (NULL);
	words = count_count(s);
	p = malloc((words + 1) * sizeof(char *));
	if (!p)
		return (NULL);
	tmp = fill(s, p, words);
	if (tmp == NULL)
		return (NULL);
	*tmp = 0;
	return (p);
}
