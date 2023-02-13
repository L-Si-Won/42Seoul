/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonglim <seonglim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 22:30:49 by seonglim          #+#    #+#             */
/*   Updated: 2023/01/29 18:04:32 by siwonlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_H
# define FT_H

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>

typedef struct s_mem_manage{
	int		key_index;
	int		front_size;
	char	*front_str;
	char	*back_str;
}	t_mem_manage;

int		str_cmp2(char *s1, char *s2);
int		str_cmp(char *s1, char *s2);
void	str_cpy(char *dest, char *src);
void	str_ncpy(char *dest, char *src, int n);
int		str_len(char *str);

int		num_check(char **argv, int *flag);
int		check_duplicate(char **key);
void	check_size(int *size);
int		check_zero(char *str);
int		check_char(char *str);

int		goinfre(char **key, char **value, int flag);
char	*str_arr(char *filename);
void	put_str(char *str);
int		real_main(char **key, char **value, char **argv, int *flag);

int		count_new_line(char *filename);
int		dict_split_check(char ***key, char ***value, char *dict_str, int i);
int		dict_split_alloc(char ***key, char ***value, char *filename);

void	null_init(char ***key, char ***value, int size);
void	data_init(t_mem_manage *data, char **key, char *str, int size);
int		alloc_dictionary(char ***key, char ***value, char *filename);
int		alloc_with_argv(char ***key, char ***value, int argc, char **argv);

int		copy_key(char ***src, int i, char *dict_str);
int		copy_value(char ***src, int i, char *dict_str);
int		find_key_index(char **key, int size);
void	swap_ptr(char **key, char **value, int j);

int		size_dict(char **key);
void	sort_dict(char **key, char **value);
void	print_one_two_num(char **key, char **value, char *str, int i);
void	print_num(char **key, char **value, char *str, int size);

char	*give_buf(void);
char	*give_tmp(char *str);

#endif
