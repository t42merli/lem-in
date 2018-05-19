/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmerli <tmerli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/17 18:23:38 by tmerli            #+#    #+#             */
/*   Updated: 2018/05/15 19:59:48 by tmerli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	get_boite(char *line, t_map *map, int *ext)
{
	t_boite	*boite;
	int		i;

	boite = (t_boite*)ft_memalloc(sizeof(t_boite));
	i = ft_strlen(line);
	i--;
	while (i != 0 && line[i] != ' ')
		i--;
	boite->y = ft_atoi(&line[i + 1]);
	i--;
	while (i != 0 && line[i] != ' ')
		i--;
	boite->x = ft_atoi(&line[i + 1]);
	if (map->boites)
		boite->pos = map->boites->pos + 1;
	boite->name = ft_strndup(line, i);
	boite->next = map->boites;
	map->boites = boite;
	if (ext[0])
		map->start = boite;
	if (ext[1])
		map->end = boite;
	ext[0] = 0;
	ext[1] = 0;
}

int		get_tubes(t_map *map, t_boite *from, t_boite *to)
{
	t_tube	*tube;

	tube = (t_tube*)ft_memalloc(sizeof(t_tube));
	tube->from = from;
	tube->to = to;
	tube->next = map->tubes;
	map->tubes = tube;
	return (1);
}

void	add_line(char *line, t_map *map)
{
	t_line *tmp;
	t_line *newline;

	newline = (t_line*)ft_memalloc(sizeof(t_line));
	newline->line = line;
	tmp = map->lines;
	if (!tmp)
		map->lines = newline;
	else
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = newline;
	}
}

void	create_adjency_list(t_map *map)
{
	t_head	**a_list;
	t_boite	*tmp;
	int		i;

	i = 0;
	tmp = map->boites;
	if (!map->boites)
		return ;
	a_list = (t_head**)ft_memalloc(sizeof(t_head*) * (map->boites->pos + 2));
	while (i <= map->boites->pos)
	{
		a_list[i] = (t_head*)ft_memalloc(sizeof(t_head));
		a_list[i]->from = -1;
		i++;
	}
	while (tmp)
	{
		a_list[tmp->pos]->boite = tmp;
		tmp = tmp->next;
	}
	map->a_list = a_list;
}
