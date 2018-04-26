/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmerli <tmerli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/17 18:23:38 by tmerli            #+#    #+#             */
/*   Updated: 2018/04/24 18:55:05 by tmerli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	get_boite(char *line, t_map *map, int *ext)
{
	t_boite	*boite;
	int		i;

	i = 0;
	boite = (t_boite*)ft_memalloc(sizeof(t_boite));
	while (line[i] != ' ')
		i++;
	i++;
	boite->name = ft_strsub(line, 0, i - 1);
	boite->x = ft_atoi(&line[i]);
	while (line[i] != ' ')
		i++;
	boite->y = ft_atoi(&line[i + 1]);
	if (ext[0])
		map->start = boite;
	if (ext[1])
		map->end = boite;
	ext[0] = 0;
	ext[1] = 0;
	boite->next = map->boites;
	if (!map->boites)
		boite->pos = 0;
	else
		boite->pos = map->boites->pos + 1;
	map->boites = boite;
}

void	get_tubes(char *line, t_map *map)
{
	t_boite	*boite;
	char	*names[2];
	t_tube	*tube;
	int		i;

	i = 0;
	while (line[i] != '-')
		i++;
	names[0] = ft_strsub(line, 0, i);
	names[1] = ft_strdup(&line[i + 1]);
	tube = (t_tube*)ft_memalloc(sizeof(t_tube));
	boite = map->boites;
	while (boite && (!tube->from || !tube->to))
	{
		if (!ft_strcmp(boite->name, names[0]))
			tube->from = boite;
		if (!ft_strcmp(boite->name, names[1]))
			tube->to = boite;
		boite = boite->next;
	}
	tube->next = map->tubes;
	map->tubes = tube;
	free(names[0]);
	free(names[1]);
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
