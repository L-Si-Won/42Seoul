/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siwonlee <tldnjs0821222@naver.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 17:14:02 by siwonlee          #+#    #+#             */
/*   Updated: 2023/02/02 02:32:34 by siwonlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_h.h"

void	map_struct_init(t_map_info *map_info)
{
	map_info->row = -1;
	map_info->col = -1;
	map_info->row_size[0] = 0;
	map_info->empty = -1;
	map_info->obst = -1;
	map_info->full = -1;
	map_info->inform[0] = 0;
	map_info->c_arr = NULL;
	map_info->i_arr = NULL;
	map_info->max_row = -1;
	map_info->max_col = -1;
	map_info->max_value = 0;
}

void	map_insert_value(t_map_info *map_info, int i)
{
	map_info->inform[i] = '\0';
	while (--i >= 0)
	{
		if (i == ft_strlen(map_info->inform) - 1)
			map_info->full = map_info->inform[i];
		else if (i == ft_strlen(map_info->inform) - 2)
				map_info->obst = map_info->inform[i];
		else if (i == ft_strlen(map_info->inform) - 3)
		{
			map_info->empty = map_info->inform[i];
			map_info->row_size[i] = '\0';
		}
		else
			map_info->row_size[i] = map_info->inform[i];
	}
}

void	eof_exit(t_map_info *m)
{
	write(1, "adsf", 4);
	c_arr_free(m->c_arr);
	ft_putstr("map error\n");
	exit(0);
}

void	first_line_init(char line[10000])
{
	int	i;

	i = 0;
	while (i < 10000)
	{
		line[i] = 0;
		i++;
	}
}

void	trash_free(t_map_info *map_info)
{
	c_arr_free(map_info->c_arr);
	ft_putstr("map error\n");
}
