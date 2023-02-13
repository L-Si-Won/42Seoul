/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   no_parm.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihshin <jihshin@student.42.seoul.>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 17:55:47 by jihshin           #+#    #+#             */
/*   Updated: 2023/02/02 01:30:11 by jihshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_h.h"

void	real_no_parm(t_map_info *m, int i, char first_line[10000])
{
	map_insert_value(m, i);
	if (is_invalid_file_size(*m) == 1)
		return ;
	if (is_duplicate_char(*m) == 1)
		return ;
	m->row = ft_atoi(m->row_size);
	if (is_row_size_zero(m->row) == 1)
		return ;
	cal_col_size_nop(m, first_line);
	if (c_array_insert_value_nop(m, 0, first_line) == -1)
		return ;
	main_algorithm(m);
	if (m->max_value == 0)
		return ;
	convert_print(m);
	c_arr_free(m->c_arr);
	i_arr_free(m->i_arr, m->row);
}

void	while_inform_no_parm(t_map_info *m, char c, int *i)
{
	m->inform[(*i)++] = c;
	while (1)
	{
		if (read(0, &c, 1) == 0)
			eof_exit(m);
		if (c == '\n')
			return ;
		m->inform[(*i)++] = c;
	}
}

int	no_parm(t_map_info m, char c, int i)
{
	char	first_line[10000];

	while (1)
	{
		i = 0;
		if (read(0, &c, 1) == 0)
			exit(0);
		if (c >= '0' && c <= '9')
		{
			map_struct_init(&m);
			first_line_init(first_line);
			while_inform_no_parm(&m, c, &i);
			real_no_parm(&m, i, first_line);
		}
		else
		{
			while (read(0, &c, 1) && c != '\n')
				;
			ft_putstr("map error\n");
		}
	}
	return (1);
}
