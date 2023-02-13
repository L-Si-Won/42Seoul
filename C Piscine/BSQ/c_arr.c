/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_arr.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihshin <jihshin@student.42.seoul.>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 20:35:57 by jihshin           #+#    #+#             */
/*   Updated: 2023/02/02 01:29:34 by jihshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_h.h"

int	c_array_insert_value(t_map_info *map_info, int fd)
{
	long long	i;
	long long	j;

	map_info->c_arr = (char **)malloc(sizeof(char *) * (map_info->row + 1));
	c_array_init(map_info->c_arr, map_info->row);
	i = 0;
	while (i < map_info->row)
	{
		if (c_array_insert_row(map_info, i, fd, -1) == -1)
			return (-1);
		j = 0;
		while (j < map_info->col)
		{
			if (!(map_info->c_arr[i][j] == map_info->empty
				|| map_info->c_arr[i][j] == map_info->obst))
			{
				c_arr_free(map_info->c_arr);
				ft_putstr("map error\n");
				return (-1);
			}
			j++;
		}
		i++;
	}
	return (1);
}

int	c_array_insert_row(t_map_info *map_info, int i, int fd, int j)
{
	char	c;

	map_info->c_arr[i] = (char *)malloc(map_info->col + 1);
	while (1)
	{
		if (read(fd, &map_info->c_arr[i][++j], 1) == 0)
			eof_exit(map_info);
		if (map_info->c_arr[i][j] == '\n' || j >= map_info->col)
			break ;
	}
	if (j < map_info->col)
	{
		trash_free(map_info);
		return (-1);
	}
	if (map_info->c_arr[i][j] != '\n')
	{
		while (read(fd, &c, 1) && c != '\n')
			;
		trash_free(map_info);
		return (-1);
	}
	map_info->c_arr[i][j] = '\0';
	return (1);
}

int	cal_col_size(t_map_info *map_info, char *filename)
{
	int		fd;
	char	c;
	int		count;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		ft_putstr("map error\n");
		return (-1);
	}
	count = 0;
	while (read(fd, &c, 1) && c != '\n')
		;
	while (read(fd, &c, 1) && c != '\n')
		count++;
	close(fd);
	map_info->col = count;
	return (0);
}

void	c_array_init(char **arr, long long row)
{
	long long	i;

	i = 0;
	while (i <= row)
	{
		arr[i] = 0;
		i++;
	}
}

void	c_arr_free(char **arr)
{
	long long	i;

	i = 0;
	while (arr[i] != 0)
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}
