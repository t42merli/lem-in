/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmerli <tmerli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 17:51:28 by tmerli            #+#    #+#             */
/*   Updated: 2018/04/25 20:25:01 by tmerli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int		is_nb_ant(char *line, int *ordre)
{
	int i;

	*ordre = 1;
	i = 0;
	while (line[i])
	{
		if (!ft_isdigit(line[i]))
			return (0);
		i++;
	}
	return (1);
}

int		already_exist(char *line, t_boite *boites)
{
	int		x;
	int		y;
	char	*name;
	int		error;

	error = 1;
	y = 0;
	while (line[y] != ' ')
		y++;
	y++;
	name = ft_strsub(line, 0, y - 1);
	x = ft_atoi(&line[y]);
	while (line[y] != ' ')
		y++;
	y = ft_atoi(&line[y + 1]);
	while (boites && error)
	{
		if (boites->x == x && boites->y == y)
			error = 0;
		if (!ft_strcmp(name, boites->name))
			error = 0;
		boites = boites->next;
	}
	free(name);
	return (error);
}

int		is_boite2(char *line, t_boite *boites, int i)
{
	if (!(line[i] == ' ') || !ft_isdigit(line[i - 1]))
		return (0);
	i++;
	while (line[i])
	{
		if (!ft_isdigit(line[i]))
			return (0);
		i++;
	}
	if (!already_exist(line, boites))
		return (0);
	return (1);
}

int		is_boite(char *line, t_boite *boites)
{
	int i;

	i = 0;
	if (line[0] == 'L' || ft_strchr(line, '-'))
		return (0);
	while (line[i] && line[i] != ' ')
		i++;
	if (!(line[i] == ' '))
		return (0);
	i++;
	while (line[i] && line[i] != ' ')
	{
		if (!ft_isdigit(line[i]))
			return (0);
		i++;
	}
	return (is_boite2(line, boites, i));
}
