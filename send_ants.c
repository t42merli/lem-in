/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send_ants.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmerli <tmerli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/10 16:34:56 by tmerli            #+#    #+#             */
/*   Updated: 2018/04/20 16:34:04 by tmerli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int		print_ants(t_path *paths, t_head **al)
{
	t_nod	*tmp;
	int		move;

	move = 0;
	while (paths)
	{
		tmp = paths->path;
		while (tmp)
		{
			if (tmp->ant)
			{
				if (move)
					ft_putchar(' ');
				move = 1;
				ft_putstr("L");
				ft_putnbr(tmp->ant);
				ft_putstr("-");
				ft_putstr(al[tmp->pos]->boite->name);
			}
			tmp = tmp->next;
		}
		paths = paths->next;
	}
	return (move);
}

void	print_fisrt_ants(t_path *paths, t_head **al, int space)
{
	while (paths)
	{
		if (paths->path->ant)
		{
			if (space)
				ft_putchar(' ');
			space = 1;
			ft_putstr("L");
			ft_putnbr(paths->path->ant);
			ft_putstr("-");
			ft_putstr(al[paths->path->pos]->boite->name);
		}
		paths = paths->next;
	}
	ft_putchar('\n');
}

void	send_ants(int ants_tmp, int *ants, t_path *paths)
{
	int smallest;
	int send;

	send = 1;
	smallest = paths->len;
	while (paths)
	{
		if (send)
		{
			paths->path->ant = ants_tmp - *ants;
			*ants = *ants - 1;
			if (paths->next && *ants / send + paths->len >= paths->next->len)
				send++;
			else
				send = 0;
		}
		else
			break ;
		paths = paths->next;
	}
}

void	lemin(int ants, t_head **al, t_path *paths)
{
	t_path	*tmp;
	int		ants_tmp;
	int		first;

	ants_tmp = ants + 1;
	tmp = paths;
	while (ants > 0)
	{
		move_ants(tmp);
		first = 0;
		if (print_ants(tmp, al))
			first = 1;
		send_ants(ants_tmp, &ants, paths);
		print_fisrt_ants(tmp, al, first);
		paths = tmp;
	}
	while (move_ants(tmp))
	{
		print_ants(tmp, al);
		ft_putchar('\n');
	}
}
