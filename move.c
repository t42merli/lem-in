/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmerli <tmerli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/17 19:41:03 by tmerli            #+#    #+#             */
/*   Updated: 2018/04/20 16:33:14 by tmerli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int		change_ant(t_nod *path, int *lastant)
{
	int tmp;

	tmp = path->ant;
	path->ant = *lastant;
	*lastant = tmp;
	return (1);
}

int		move_ants(t_path *paths)
{
	t_nod	*tmp;
	int		lastant;
	int		move;

	move = 0;
	while (paths)
	{
		tmp = paths->path;
		lastant = 0;
		while (tmp)
		{
			if (lastant)
				move = change_ant(tmp, &lastant);
			else if (tmp->ant)
			{
				lastant = tmp->ant;
				tmp->ant = 0;
			}
			tmp = tmp->next;
		}
		paths = paths->next;
	}
	return (move);
}
