/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmerli <tmerli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 15:42:51 by tmerli            #+#    #+#             */
/*   Updated: 2017/11/16 13:16:48 by tmerli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_calclen(const char *s)
{
	unsigned int i;
	unsigned int len;

	i = 0;
	len = 0;
	while (s[i] && (s[i] == ' ' || s[i] == '\n' || s[i] == '\t'))
	{
		i++;
		len++;
	}
	if (len < ft_strlen(s))
	{
		i = ft_strlen(s) - 1;
		while (i > 0 && (s[i] == ' ' || s[i] == '\n' || s[i] == '\t'))
		{
			i--;
			len++;
		}
		len = ft_strlen(s) - len;
		return (len);
	}
	else
		return (0);
}

char			*ft_strtrim(char const *s)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	len;
	char			*str;

	if (!s)
		return (NULL);
	i = 0;
	j = 0;
	len = ft_calclen(s);
	while (s[j] && (s[j] == ' ' || s[j] == '\n' || s[j] == '\t'))
		j++;
	if (!(str = ft_strnew(len)))
		return (NULL);
	while (i < len)
		str[i++] = s[j++];
	return (str);
}
