/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmerli <tmerli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 17:51:28 by tmerli            #+#    #+#             */
/*   Updated: 2018/05/16 17:22:41 by tmerli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int		is_nb_ant(char *line)
{
	int i;

	i = 0;
	if (!line[i])
		return (0);
	while (line[i])
	{
		if (!ft_isdigit(line[i]))
			return (0);
		i++;
	}
	return (1);
}

int		already_exist(char *line, t_boite *boites, int i, int coord[2])
{
	if (i == 0 || line[0] == 'L')
		return (0);
	while (boites)
	{
		if (!ft_strncmp(line, boites->name, i))
		{
			if (ft_strlen(boites->name) == (size_t)i)
				return (0);
		}
		if (coord[0] == boites->x && coord[1] == boites->y)
			return (0);
		boites = boites->next;
	}
	return (1);
}

int		is_boite(char *line, t_boite *boites)
{
	int i;
	int coord[2];

	i = ft_strlen(line);
	i--;
	while (i != 0 && line[i] != ' ')
	{
		if (!(ft_isdigit(line[i]) || line[i] == ' '))
			return (0);
		i--;
	}
	if (!ft_isdigit(line[i + 1]))
		return (0);
	coord[1] = ft_atoi(&line[i + 1]);
	i--;
	while (i != 0 && line[i] != ' ')
	{
		if (!(ft_isdigit(line[i]) || line[i] == ' '))
			return (0);
		i--;
	}
	if (!ft_isdigit(line[i + 1]))
		return (0);
	coord[0] = ft_atoi(&line[i + 1]);
	return (already_exist(line, boites, i, coord));
}
