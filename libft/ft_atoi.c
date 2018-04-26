/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmerli <tmerli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 17:08:43 by tmerli            #+#    #+#             */
/*   Updated: 2017/11/20 10:51:05 by tmerli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_atoi(const char *str)
{
	unsigned long	nb;
	int				i;
	int				deb;

	i = 0;
	nb = 0;
	while (str[i] && (str[i] == '\t' || str[i] == '\r' || str[i] == '\v'
				|| str[i] == '\n' || str[i] == '\f' || str[i] == ' '))
		i++;
	deb = i;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		nb = nb * 10;
		nb = nb + (int)str[i] - 48;
		i++;
		if (nb > 9223372036854775807 && str[deb] != '-')
			return (-1);
		else if (nb > 9223372036854775807 && str[deb] == '-')
			return (0);
	}
	if (str[deb] == '-')
		return (-(int)nb);
	return ((int)nb);
}
