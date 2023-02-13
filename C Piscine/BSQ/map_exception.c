/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_exception.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siwonlee <tldnjs0821222@naver.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 17:09:25 by siwonlee          #+#    #+#             */
/*   Updated: 2023/01/30 17:58:40 by jihshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_h.h"

int	is_no_file(int fd)
{
	if (fd < 0)
	{
		ft_putstr("map error\n");
		return (1);
	}
	return (0);
}

int	is_empty_file(int i)
{
	if (i == 0)
	{
		ft_putstr("map error\n");
		return (1);
	}
	return (0);
}

int	is_invalid_file_size(t_map_info map_info)
{
	int	i;

	i = -1;
	while (map_info.row_size[++i] != 0)
	{
		if (!(map_info.row_size[i] >= '0' && map_info.row_size[i] <= '9'))
		{
			ft_putstr("map error\n");
			return (1);
		}
	}
	return (0);
}

int	is_duplicate_char(t_map_info map_info)
{
	if (map_info.empty == map_info.obst || map_info.empty == map_info.full
		|| map_info.obst == map_info.full)
	{
		ft_putstr("map error\n");
		return (1);
	}
	return (0);
}

int	is_row_size_zero(int size)
{
	if (size == 0)
	{
		ft_putstr("map error\n");
		return (1);
	}
	return (0);
}
