/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmerli <tmerli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/02 07:28:45 by tmerli            #+#    #+#             */
/*   Updated: 2018/04/24 18:52:56 by tmerli           ###   ########.fr       */
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

int		is_tube(char *line, t_boite *boites)
{
	char	*boite1;
	char	*boite2;
	int		i;

	i = 0;
	while (line[i] && line[i] != '-')
		i++;
	if (!line[i])
		return (0);
	boite1 = ft_strsub(line, 0, i);
	boite2 = ft_strdup(&line[i + 1]);
	return (box_exist(boite1, boite2, boites));
}
