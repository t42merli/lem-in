/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_finding.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmerli <tmerli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 18:10:02 by tmerli            #+#    #+#             */
/*   Updated: 2018/04/25 20:19:57 by tmerli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int		path_len(t_map *map, t_nod *path)
{
	int i;

	i = 0;
	while (path->next)
	{
		i++;
		map->a_list[path->pos]->used = 1;
		path = path->next;
	}
	return (i + 1);
}

void	add_path(t_map *map, t_nod *path)
{
	t_path			*new_p;
	static t_path	*tmp = NULL;
	int				i;

	i = 0;
	new_p = (t_path*)ft_memalloc(sizeof(t_path));
	new_p->path = path;
	new_p->len = path_len(map, path);
	if (tmp)
	{
		tmp->next = new_p;
		tmp = new_p;
	}
	else
	{
		tmp = new_p;
		map->paths = tmp;
	}
	while (map->a_list[i])
	{
		map->a_list[i]->from = -1;
		i++;
	}
}

void	get_paths(t_map *map)
{
	int		nb;
	t_nod	*path;

	if (!map->a_list)
		return;
	nb = map->nb_ants;
	while ((path = bfs(map, map->a_list, map->start->pos,
					map->end->pos)))
		add_path(map, path);
}
