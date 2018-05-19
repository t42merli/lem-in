/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmerli <tmerli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/02 07:28:45 by tmerli            #+#    #+#             */
/*   Updated: 2018/05/16 17:37:16 by tmerli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int		commentaire(char *line, int *ext)
{
	if (!ft_strcmp(line, "##start"))
		ext[0] = 1;
	else if (!ft_strcmp(line, "##end"))
		ext[1] = 1;
	return (1);
}

int		box_exist(char *boite1, char *boite2, t_boite *boites)
{
	int check1;
	int check2;

	check1 = 0;
	check2 = 0;
	while (boites && (!check1 || !check2))
	{
		if (!ft_strcmp(boites->name, boite1))
			check1 = 1;
		if (!ft_strcmp(boites->name, boite2))
			check2 = 1;
		boites = boites->next;
	}
	free(boite1);
	free(boite2);
	if (check1 && check2)
		return (1);
	return (0);
}

int		is_tube2(t_boite *boite1, t_boite *boites, char *line, t_map *map)
{
	char *boite;

	while (boites)
	{
		if ((boite = ft_strstr(line, boites->name)))
		{
			if (boite == line && ft_strlen(line) == ft_strlen(boites->name))
				return (get_tubes(map, boite1, boites));
		}
		boites = boites->next;
	}
	return (0);
}

int		is_tube(t_map *map, char *line, t_boite *boites)
{
	int		i;
	t_boite	*tmp;
	char	*boite;

	tmp = boites;
	while (boites)
	{
		i = 0;
		if ((boite = ft_strstr(line, boites->name)))
		{
			i = ft_strlen(boites->name);
			if (line[i] == '-' && boite == line)
			{
				if (is_tube2(boites, tmp, &line[i + 1], map))
					return (1);
			}
		}
		boites = boites->next;
	}
	return (0);
}
