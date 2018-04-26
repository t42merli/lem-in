/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmerli <tmerli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 13:06:02 by tmerli            #+#    #+#             */
/*   Updated: 2017/11/16 13:57:59 by tmerli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *n;
	t_list *tmp;

	if (!lst || !f)
		return (NULL);
	if (lst->next)
	{
		tmp = f(lst);
		if (!(n = ft_lstnew(tmp->content, tmp->content_size)))
			return (NULL);
		if (!(n->next = ft_lstmap(lst->next, f)))
			return (NULL);
		return (n);
	}
	else
	{
		tmp = f(lst);
		if (!(n = ft_lstnew(tmp->content, tmp->content_size)))
			return (NULL);
		return (n);
	}
}
