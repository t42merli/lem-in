/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmerli <tmerli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 11:52:45 by tmerli            #+#    #+#             */
/*   Updated: 2017/11/16 12:07:57 by tmerli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *d, const void *s, int c, size_t n)
{
	size_t				i;
	const unsigned char	*src;
	unsigned char		*dst;

	src = s;
	dst = d;
	i = 0;
	while (i < n)
	{
		dst[i] = src[i];
		if (src[i] == (unsigned char)c)
		{
			dst[i] = src[i];
			i++;
			return (&d[i]);
		}
		i++;
	}
	return (NULL);
}
