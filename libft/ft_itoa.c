/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmerli <tmerli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 11:43:35 by tmerli            #+#    #+#             */
/*   Updated: 2017/11/15 14:15:21 by tmerli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count(int n)
{
	int i;

	i = 1;
	while (n != 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char		*ft_itoa(int n)
{
	char	*str;
	int		i;
	long	tmp;
	int		j;
	long	nb;

	i = ft_count(n);
	nb = n;
	if (!(str = ft_strnew(i)))
		return (NULL);
	j = 0;
	if (n < 0)
	{
		str[j++] = '-';
		nb = nb * -1;
	}
	else if (n > 0)
		i--;
	tmp = 1;
	while (i > j)
	{
		str[i-- - 1] = (char)((nb % (tmp * 10) / tmp) + 48);
		tmp = tmp * 10;
	}
	return (str);
}
