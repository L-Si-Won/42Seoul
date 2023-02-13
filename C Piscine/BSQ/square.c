/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   square.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihshin <jihshin@student.42.seoul.>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 22:28:48 by jihshin           #+#    #+#             */
/*   Updated: 2023/01/31 14:22:41 by jihshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_h.h"

void	square(int **arr, int col, int row)
{
	int	i;
	int	j;

	i = 0;
	while (i < row)
	{
		j = 0;
		while (j < col)
		{
			if (i != 0 && j != 0 && arr[i][j] != 0)
				arr[i][j] = ft_min(arr[i - 1][j - 1],
						ft_min(arr[i - 1][j], arr[i][j - 1])) + 1;
			j++;
		}
		i++;
	}
	i = 0;
}

void	cal_square_max(t_map_info *map_info)
{
	int	i;
	int	j;

	i = -1;
	while (++i < map_info->row)
	{
		j = -1;
		while (++j < map_info->col)
		{
			if (map_info->max_value < map_info->i_arr[i][j])
			{
				map_info->max_value = map_info->i_arr[i][j];
				map_info->max_row = i;
				map_info->max_col = j;
			}
		}
	}
	if (map_info->max_value == 0)
	{
		ft_putstr("map error\n");
		c_arr_free(map_info->c_arr);
		i_arr_free(map_info->i_arr, map_info->row);
	}
}

int	ft_min(int a, int b)
{
	if (a > b)
		return (b);
	return (a);
}

int	ft_max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

void	convert_print(t_map_info *map_info)
{
	int	i;
	int	j;

	i = map_info->max_row - (map_info->max_value - 1);
	while (i <= map_info->max_row)
	{
		j = map_info->max_col - (map_info->max_value - 1);
		while (j <= map_info->max_col)
		{
			map_info->c_arr[i][j] = map_info->full;
			j++;
		}
		i++;
	}
	i = -1;
	while (++i < map_info->row)
	{
		j = 0;
		while (j < map_info->col)
		{
			write(1, &map_info->c_arr[i][j], 1);
			j++;
		}
		write(1, "\n", 1);
	}
}
