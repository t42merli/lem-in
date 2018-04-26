/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmerli <tmerli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/20 02:00:05 by tmerli            #+#    #+#             */
/*   Updated: 2018/04/25 20:17:25 by tmerli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int		check_map(t_map *map)
{
	if (!map->start)
	{
		ft_putendl("ERROR");
		return (0);
	}
	if (!map->end)
	{
		ft_putendl("ERROR");
		return (0);
	}
	if (!map->nb_ants)
	{
		ft_putendl("ERROR");
		return (0);
	}
	if (map->end == map->start)
	{
		ft_putendl("ERROR Nothing to be done: start is end");
		return (0);
	}
	return (1);
}

int		main(int argc, const char *argv[])
{
	t_map *map;

	map = (t_map*)ft_memalloc(sizeof(t_map));
	parse(map);
	print_map(map);
	if (!check_map(map))
	{
		free_map(map);
		return (0);
	}
	get_paths(map);
	if (!map->paths)
	{
		free_map(map);
		ft_putendl("ERROR No path");
		return (0);
	}
	if (argc > 1 && !ft_strcmp(argv[1], "-p"))
		print_path(map, map->paths);
	lemin(map->nb_ants, map->a_list, map->paths);
	free_map(map);
	return (0);
}
