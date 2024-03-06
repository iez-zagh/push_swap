/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iez-zagh <iez-zagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 18:46:40 by iez-zagh          #+#    #+#             */
/*   Updated: 2024/03/04 20:06:13 by iez-zagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	ft_strlen2(const char *s)
{
	int	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
	{
		i++;
	}
	return (i);
}

char	*ft_strdup2(const char *s)
{
	int		i;
	char	*res;

	i = 0;
	res = malloc(ft_strlen2(s) + 2);
	if (!res)
		return (NULL);
	while (s[i])
	{
		res[i] = s[i];
		i++;
	}
	res[i++] = ' ';
	res[i] = '\0';
	return (res);
}

char	*ft_strjoin2(const char *s1, const char *s2, int ac, int i1)
{
	int		i;
	int		j;
	char	*res;

	if (!s1)
		return (ft_strdup2(s2));
	if (!s2)
		return (ft_strdup2(s1));
	i = 0;
	j = 0;
	res = malloc((ft_strlen2(s1) + ft_strlen2(s2) + 2));
	if (!res)
		return (NULL);
	while (s1[i])
		res[i++] = s1[j++];
	j = 0;
	while (s2[j])
		res[i++] = s2[j++];
	res[i++] = ' ';
	if (ac == i1)
		res[i++] = ' ';
	res[i] = '\0';
	free((char *)s1);
	return (res);
}

char	*ft_substr2(char const *s, unsigned int start, size_t len)
{
	size_t		i;
	size_t		len_s;
	char		*res;

	i = 0;
	if (!s)
		return (NULL);
	if (start >= (unsigned int)ft_strlen2(s))
		return (ft_strdup2(""));
	len_s = ft_strlen2(&s[start]);
	if (len_s < len)
		len = len_s;
	res = malloc(sizeof(char) * (len + 1));
	if (!res)
		return (NULL);
	s = s + start;
	while (s[i] != '\0' && len > 0)
	{
		res[i] = s[i];
		i++;
		len--;
	}
	res[i] = '\0';
	return (res);
}
