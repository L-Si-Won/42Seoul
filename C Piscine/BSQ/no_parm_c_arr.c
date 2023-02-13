/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   no_parm_c_arr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihshin <jihshin@student.42.seoul.>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 22:13:01 by jihshin           #+#    #+#             */
/*   Updated: 2023/02/02 01:30:19 by jihshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_h.h"

void	cal_col_size_nop(t_map_info *m, char s[10000])
{
	char	c;
	int		count;

	count = 0;
	while (1)
	{
		if (read(0, &c, 1) == 0)
			eof_exit(m);
		if (c == '\n')
			break ;
		s[count] = c;
		count++;
	}
	s[count] = '\0';
	m->col = count;
}

int	c_array_insert_first_row(t_map_info *m, char s[10000])
{
	int	i;

	m->c_arr[0] = (char *)malloc(sizeof(char) * (m->col + 1));
	ft_strcpy(m->c_arr[0], s);
	i = 0;
	while (i < m->col)
	{
		if (!(m->c_arr[0][i] == m->empty
			|| m->c_arr[0][i] == m->obst))
		{
			c_arr_free(m->c_arr);
			ft_putstr("map error\n");
			return (-1);
		}
		i++;
	}
	return (1);
}

int	c_array_insert_value_nop(t_map_info *map_info, int fd, char s[10000])
{
	int	i;
	int	j;

	map_info->c_arr = (char **)malloc(sizeof(char *) * (map_info->row + 1));
	c_array_init(map_info->c_arr, map_info->row);
	if (c_array_insert_first_row(map_info, s) == -1)
		return (-1);
	i = 0;
	while (++i < map_info->row)
	{
		if (c_array_insert_row(map_info, i, fd, -1) == -1)
			return (-1);
		j = -1;
		while (++j < map_info->col)
		{
			if (!(map_info->c_arr[i][j] == map_info->empty
				|| map_info->c_arr[i][j] == map_info->obst))
			{
				c_arr_free(map_info->c_arr);
				ft_putstr("map error\n");
				return (-1);
			}
		}
	}
	return (1);
}
