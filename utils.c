/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmerli <tmerli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 16:06:27 by tmerli            #+#    #+#             */
/*   Updated: 2018/05/15 17:25:02 by tmerli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	free_nods(t_nod **nods)
{
	t_nod *tmp;

	while (*nods)
	{
		tmp = nods[0]->next;
		free(*nods);
		*nods = tmp;
	}
}

void	free_map2(t_map *map)
{
	void	*tmp;
	int		i;

	i = 0;
	while (map->paths)
	{
		free_nods(&map->paths->path);
		tmp = map->paths->next;
		free(map->paths);
		map->paths = tmp;
	}
	while (map->a_list && map->a_list[i])
	{
		free_nods(&map->a_list[i]->nods);
		free(map->a_list[i]);
		i++;
	}
}

void	free_map(t_map *map)
{
	void	*tmp;

	while (map->boites)
	{
		free(map->boites->name);
		tmp = map->boites->next;
		free(map->boites);
		map->boites = tmp;
	}
	while (map->tubes)
	{
		tmp = map->tubes->next;
		free(map->tubes);
		map->tubes = tmp;
	}
	free_map2(map);
	free(map->a_list);
	free(map);
}

void	print_map(t_map *map)
{
	t_line *tmp;

	while (map->lines)
	{
		tmp = map->lines;
		ft_putendl(map->lines->line);
		free(map->lines->line);
		map->lines = map->lines->next;
		free(tmp);
	}
	ft_putchar('\n');
}

void	print_path(t_map *map, t_path *paths)
{
	t_nod *tmp;

	ft_putendl("paths :");
	while (paths)
	{
		tmp = paths->path;
		ft_putstr(map->start->name);
		while (tmp)
		{
			ft_putstr("->");
			ft_putstr(map->a_list[tmp->pos]->boite->name);
			tmp = tmp->next;
		}
		ft_putstr(" | path length = ");
		ft_putnbrdl(paths->len);
		paths = paths->next;
	}
	ft_putchar('\n');
}
