/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmerli <tmerli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 15:20:17 by tmerli            #+#    #+#             */
/*   Updated: 2017/11/15 14:24:03 by tmerli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *big, const char *little)
{
	int i;
	int j;

	i = 0;
	j = 0;
	if (*big == '\0' && *little == '\0')
		return ((char*)big);
	while (big[i] && little[j])
	{
		if (big[i] == little[j])
		{
			while (little[j] && big[i + j] && big[i + j] == little[j])
				j++;
			if (!little[j])
				return ((char*)&big[i]);
			j = 0;
		}
		i++;
	}
	if (big[i])
		return ((char*)big);
	else
		return (NULL);
}
