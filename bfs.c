/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_finding2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmerli <tmerli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 18:11:31 by tmerli            #+#    #+#             */
/*   Updated: 2018/04/20 16:31:46 by tmerli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

t_nod	*bactrack(t_head **al, int start, int end)
{
	t_nod *path;
	t_nod *tmp;

	path = NULL;
	if (al[end]->from == -1)
		return (NULL);
	while (end != start)
	{
		tmp = (t_nod*)ft_memalloc(sizeof(t_nod));
		tmp->pos = end;
		tmp->next = path;
		path = tmp;
		end = al[end]->from;
	}
	return (path);
}

void	queue(t_nod **q_end, int pos)
{
	q_end[0]->next = (t_nod*)ft_memalloc(sizeof(t_nod));
	*q_end = q_end[0]->next;
	q_end[0]->pos = pos;
}

t_nod	*bfs(t_map *map, t_head **al, int start, int end)
{
	t_nod *q;
	t_nod *q_end;
	t_nod *tmp;

	q = (t_nod*)ft_memalloc(sizeof(t_nod));
	q->pos = start;
	q_end = q;
	while (q)
	{
		tmp = al[q->pos]->nods;
		while (tmp)
		{
			if (!(tmp->pos == end && q->pos == start && map->paths)
					&& !al[tmp->pos]->used && al[tmp->pos]->from == -1)
			{
				queue(&q_end, tmp->pos);
				al[tmp->pos]->from = q->pos;
			}
			tmp = tmp->next;
		}
		tmp = q->next;
		free(q);
		q = tmp;
	}
	return (bactrack(al, start, end));
}
