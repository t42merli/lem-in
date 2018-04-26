/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmerli <tmerli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 10:52:29 by tmerli            #+#    #+#             */
/*   Updated: 2018/02/28 05:10:29 by tmerli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_words(const char *s, char c)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			j++;
			while (s[i] && s[i] != c)
				i++;
			i--;
		}
		i++;
	}
	return (j);
}

char		**ft_strsplit(char const *s, char c)
{
	int		i;
	int		j;
	char	**tab;
	int		k;

	if (!s || !(tab = (char**)ft_memalloc(sizeof(char*) * ft_count_words(s, c)
					+ 8)))
		return (NULL);
	i = 0;
	j = 0;
	k = 0;
	while (s[++i])
	{
		if (s[i] != c)
		{
			while (s[i + j] && s[i + j] != c)
				j++;
			if (!(tab[k] = ft_strsub(s, i, j + 1)))
				return (NULL);
			tab[k++][j] = '\0';
			i = i + j - 1;
			j = 0;
		}
	}
	return (tab);
}
