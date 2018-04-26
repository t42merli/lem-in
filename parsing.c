/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmerli <tmerli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 11:35:26 by tmerli            #+#    #+#             */
/*   Updated: 2018/04/25 19:54:55 by tmerli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	delete_double_tubes(t_tube *tubes)
{
	t_tube *tmp;
	t_tube *tmp2;

	tmp = tubes;
	while (tmp)
	{
		tmp2 = tmp;
		tubes = tmp->next;
		while (tubes)
		{
			if ((tubes->from == tmp->from && tubes->to == tmp->to) ||
					(tubes->to == tmp->from && tubes->from == tmp->to))
			{
				tmp2->next = tubes->next;
				free(tubes);
				tubes = tmp2->next;
			}
			else
			{
				tmp2 = tubes;
				tubes = tubes->next;
			}
		}
		tmp = tmp->next;
	}
}

void	add_nod(t_nod **list, t_nod *to_add)
{
	if (*list)
		to_add->next = *list;
	*list = to_add;
}

void	make_adjency_list(t_map *map, t_tube *tubes)
{
	t_nod *from;
	t_nod *to;

	delete_double_tubes(tubes);
	while (tubes)
	{
		from = (t_nod*)ft_memalloc(sizeof(t_nod));
		from->pos = tubes->from->pos;
		to = (t_nod*)ft_memalloc(sizeof(t_nod));
		to->pos = tubes->to->pos;
		add_nod(&map->a_list[tubes->from->pos]->nods, to);
		add_nod(&map->a_list[tubes->to->pos]->nods, from);
		tubes = tubes->next;
	}
}

int		parse2(t_map *map, char *line, int *ordre, int *ext)
{
	if (!*ordre && is_nb_ant(line, ordre))
		map->nb_ants = ft_atoi(line);
	else if (*ordre == 1 && is_boite(line, map->boites))
		get_boite(line, map, ext);
	else if (*ordre == 1)
	{
		*ordre = 2;
		create_adjency_list(map);
	}
	if (*ordre == 2 && is_tube(line, map->boites))
		get_tubes(line, map);
	else if (*ordre == 2)
		return (0);
	return (1);
}

void	parse(t_map *map)
{
	char	*line;
	int		ext[2];
	int		ordre;

	ordre = 0;
	ext[0] = 0;
	ext[1] = 0;
	while (get_next_line(0, &line))
	{
		if (line[0] == '#')
			commentaire(line, ext);
		else if (!parse2(map, line, &ordre, ext))
			break ;
		add_line(line, map);
	}
	free(line);
	make_adjency_list(map, map->tubes);
}
