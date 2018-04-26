/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmerli <tmerli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 11:38:43 by tmerli            #+#    #+#             */
/*   Updated: 2017/11/15 14:44:37 by tmerli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	unsigned char		*dest;
	const unsigned char	*srce;

	dest = dst;
	srce = src;
	if (src < dst)
	{
		srce = &src[n - 1];
		dest = &dst[n - 1];
		while (n > 0)
		{
			*dest = *srce;
			dest--;
			srce--;
			n--;
		}
	}
	else
		ft_memcpy(dst, src, n);
	return (dst);
}
