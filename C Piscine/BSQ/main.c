/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siwonlee <tldnjs0821222@naver.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 14:30:11 by siwonlee          #+#    #+#             */
/*   Updated: 2023/02/02 02:30:48 by siwonlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_h.h"

int	real_main(t_map_info *map_info, char **argv, int idx, int fd)
{
	int	i;

	i = 0;
	if (is_no_file(fd) == 1)
		return (-1);
	while (read(fd, &map_info->inform[i], 1) && map_info->inform[i] != '\n')
		i++;
	if (is_empty_file(i) == 1)
		return (-1);
	map_insert_value(map_info, i);
	if (is_invalid_file_size(*map_info) == 1)
		return (-1);
	if (is_duplicate_char(*map_info) == 1)
		return (-1);
	map_info->row = ft_atoi(map_info->row_size);
	if (is_row_size_zero(map_info->row) == 1)
		return (-1);
	if (cal_col_size(map_info, argv[idx]) == -1)
		return (-1);
	if (c_array_insert_value(map_info, fd) == -1)
		return (-1);
	return (1);
}

void	mamury(t_map_info *map_info, int fd)
{
	convert_print(map_info);
	c_arr_free(map_info->c_arr);
	i_arr_free(map_info->i_arr, map_info->row);
	close(fd);
}

int	main_algorithm(t_map_info *map_info)
{
	i_arr_insert_value(map_info);
	square(map_info->i_arr, map_info->col, map_info->row);
	cal_square_max(map_info);
	return (map_info->max_value);
}
#include <stdio.h>
void	leaks(void)
{
	system("leaks bsq");
}
int	main(int argc, char *argv[])
{
	int			fd;
	int			idx;
	t_map_info	map_info;

	atexit(leaks);
	idx = 0;
	map_struct_init(&map_info);
	if (argc == 1)
		no_parm(map_info, 0, 0);
	while (++idx < argc)
	{
		map_struct_init(&map_info);
		fd = open(argv[idx], O_RDONLY);
		if (real_main(&map_info, argv, idx, fd) == -1)
		{
			close(fd);
			continue ;
		}
		if (main_algorithm(&map_info) == 0)
		{
			close(fd);
			continue ;
		}
		mamury(&map_info, fd);
	}
	return (0);
}
