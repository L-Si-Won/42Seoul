/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_h.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siwonlee <tldnjs0821222@naver.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 15:55:50 by siwonlee          #+#    #+#             */
/*   Updated: 2023/02/02 01:29:44 by jihshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_H_H
# define FT_H_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

typedef long long	t_ll;

typedef struct s_map_info
{
	long long	row;
	int			col;
	char		row_size[1000];
	char		empty;
	char		obst;
	char		full;
	char		inform[1000];
	char		**c_arr;
	int			**i_arr;
	long long	max_row;
	int			max_col;
	int			max_value;
}	t_map_info;

int		real_main(t_map_info *map_info, char **argv, int dix, int fd);
int		main_algorithm(t_map_info *map_info);
void	mamury(t_map_info *map_info, int fd);

int		ft_strlen(char *str);
int		ft_strcmp(char *s1, char *s2);
void	ft_putstr(char *str);
t_ll	ft_atoi(char *str);
void	ft_strcpy(char *s1, char *s2);

void	map_struct_init(t_map_info *map_info);
void	map_insert_value(t_map_info *map_info, int i);
void	eof_exit(t_map_info *m);
void	first_line_init(char line[10000]);
void	trash_free(t_map_info *map_info);

int		is_no_file(int fd);
int		is_empty_file(int i);
int		is_invalid_file_size(t_map_info map_info);
int		is_duplicate_char(t_map_info map_info);
int		is_row_size_zero(int size);

int		c_array_insert_value(t_map_info *map_info, int fd);
int		c_array_insert_row(t_map_info *map_info, int i, int fd, int j);
int		cal_col_size(t_map_info *map_info, char *filename);
void	c_array_init(char **arr, long long row);
void	c_arr_free(char **arr);

void	i_array_init(int **arr, int row);
void	i_arr_insert_value(t_map_info *map_info);
void	i_arr_free(int **arr, int row);

void	square(int **arr, int col, int row);
void	cal_square_max(t_map_info *map_info);
int		ft_min(int a, int b);
int		ft_max(int a, int b);
void	convert_print(t_map_info *map_info);

int		no_parm(t_map_info m, char c, int i);
void	real_no_parm(t_map_info *m, int i, char first_line[10000]);
void	while_inform_no_parm(t_map_info *m, char c, int *i);

void	cal_col_size_nop(t_map_info *m, char s[10000]);
int		c_array_insert_first_row(t_map_info *m, char s[10000]);
int		c_array_insert_value_nop(t_map_info *map_info, int fd, char s[10000]);

#endif
