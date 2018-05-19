/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmerli <tmerli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/20 01:26:15 by tmerli            #+#    #+#             */
/*   Updated: 2018/05/16 17:22:14 by tmerli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIN_H
# define LEMIN_H
# include "libft/libft.h"
# include "get_next_line.h"
# include <stdio.h>

typedef struct	s_boite
{
	char			*name;
	int				x;
	int				y;
	struct s_boite	*next;
	int				pos;
}				t_boite;

typedef struct	s_tube
{
	t_boite			*from;
	t_boite			*to;
	struct s_tube	*next;
}				t_tube;

typedef struct	s_line
{
	char			*line;
	struct s_line	*next;
}				t_line;

typedef struct	s_nod
{
	int				ant;
	int				pos;
	struct s_nod	*next;
}				t_nod;

typedef struct	s_head
{
	int		used;
	int		from;
	t_boite	*boite;
	t_nod	*nods;
}				t_head;

typedef struct	s_path
{
	int				len;
	t_nod			*path;
	struct s_path	*next;
}				t_path;

typedef struct	s_map
{
	int		nb_ants;
	t_boite	*boites;
	t_tube	*tubes;
	t_line	*lines;
	t_boite	*start;
	t_boite	*end;
	t_head	**a_list;
	t_path	*paths;
}				t_map;

int				is_boite(char *line, t_boite *boites);
int				is_tube(t_map *map, char *line, t_boite *boites);
int				get_tubes(t_map *map, t_boite *from, t_boite *to);
void			print_path(t_map *map, t_path *paths);
t_nod			*bfs(t_map *map, t_head **al, int start, int end);
int				move_ants(t_path *paths);
void			create_adjency_list(t_map *map);
void			add_line(char *line, t_map *map);
void			get_boite(char *line, t_map *map, int *ext);
void			lemin(int ants, t_head **al, t_path *paths);
void			free_nods(t_nod **nods);
void			get_paths(t_map *map);
void			put_al(t_head **al);
void			print_map(t_map *map);
void			free_map(t_map *map);
int				check_map(t_map *map);
void			parse(t_map *map);
int				is_nb_ant(char *line);
int				commentaire(char *line, int *ext);

#endif
