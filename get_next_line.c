/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmerli <tmerli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 13:33:02 by tmerli            #+#    #+#             */
/*   Updated: 2017/12/12 13:33:08 by tmerli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft/libft.h"

static int		ft_add_last(char **line, char **last)
{
	int i;

	i = 0;
	if (!(*line = ft_strnew(BUFF_SIZE)))
		return (-1);
	if (*last)
	{
		while (last[0][i] && last[0][i] != '\n')
		{
			line[0][i] = last[0][i];
			i++;
		}
		line[0][i] = '\0';
		if (last[0][i] == '\n')
		{
			ft_strcpy(*last, &last[0][i + 1]);
			return (2);
		}
		else
			ft_memdel((void**)last);
	}
	else
		return (0);
	return (1);
}

static int		ft_add(char **line, char *buf)
{
	char	*tmp;
	int		size;

	if (!(tmp = ft_strdup(*line)))
		return (-1);
	free(*line);
	size = ft_strlen(tmp) + ft_strlen(buf) + 1;
	if (!(*line = (char*)malloc(sizeof(char) * size)))
		return (-1);
	ft_strcpy(*line, tmp);
	free(tmp);
	ft_strcat(*line, buf);
	return (1);
}

int				get_next_line(const int fd, char **line)
{
	static char	*last = NULL;
	int			ret;
	int			tmp;
	char		buf[BUFF_SIZE + 1];
	char		*nl;

	if (fd < 0 || !line || (ret = ft_add_last(line, &last)) == -1)
		return (-1);
	if (ret == 2)
		return (1);
	while ((tmp = read(fd, buf, BUFF_SIZE)) && ret != -1 && tmp != -1)
	{
		buf[tmp] = '\0';
		if ((nl = ft_strchr(buf, '\n')))
		{
			*nl = '\0';
			if (!(last = ft_strdup(++nl)) || ft_add(line, buf) == -1)
				return (-1);
			return (1);
		}
		ret = ft_add(line, buf);
	}
	if (line[0][0])
		return (ret);
	return (tmp);
}
