/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmerli <tmerli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 15:20:17 by tmerli            #+#    #+#             */
/*   Updated: 2017/11/15 17:03:18 by tmerli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t i;
	size_t j;

	i = 0;
	j = 0;
	while (big[i] && little[j] && i < len)
	{
		if (big[i] == little[j])
		{
			while (little[j] && big[i + j] && big[i + j] == little[j]
					&& i + j < len)
				j++;
			if (!little[j])
				return ((char*)&big[i]);
			j = 0;
		}
		i++;
	}
	if (big[i] && i < len)
		return ((char*)big);
	else
		return (NULL);
}
