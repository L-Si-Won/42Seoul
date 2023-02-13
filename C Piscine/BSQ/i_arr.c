/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   i_arr.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihshin <jihshin@student.42.seoul.>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 21:23:19 by jihshin           #+#    #+#             */
/*   Updated: 2023/01/30 22:29:45 by jihshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_h.h"

void	i_array_init(int **arr, int row)
{
	int	i;

	i = 0;
	while (i <= row)
	{
		arr[i] = 0;
		i++;
	}
}

void	i_arr_insert_value(t_map_info *map_info)
{
	int	i;
	int	j;

	map_info->i_arr = (int **)malloc(sizeof(int *) * map_info->row);
	i_array_init(map_info->i_arr, map_info->row);
	i = 0;
	while (i < map_info->row)
	{
		j = 0;
		map_info->i_arr[i] = (int *)malloc(sizeof(int) * map_info->col);
		while (j < map_info->col)
		{
			if (map_info->c_arr[i][j] == map_info->empty)
				map_info->i_arr[i][j] = 1;
			else if (map_info->c_arr[i][j] == map_info->obst)
				map_info->i_arr[i][j] = 0;
			j++;
		}
		i++;
	}
}

void	i_arr_free(int **arr, int row)
{
	int	i;

	i = 0;
	while (i < row)
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}
