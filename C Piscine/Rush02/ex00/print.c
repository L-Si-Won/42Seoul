/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonglim <seonglim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 07:17:07 by seonglim          #+#    #+#             */
/*   Updated: 2023/01/29 18:00:02 by siwonlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int	find_key_index(char **key, int size)
{
	int	i;
	int	j;
	int	keysize;

	check_size(&size);
	i = -1;
	while (key[++i])
	{
		keysize = str_len(key[i]);
		if (size == keysize)
			return (i);
		if (size < keysize)
		{
			j = 0;
			while (str_len(key[j]) != str_len(key[i - 1]))
				++j;
			return (j);
		}
	}
	return (i - 1);
}

int	copy_key(char ***src, int i, char *dict_str)
{
	static int	index;
	int			k;
	int			j;

	j = i;
	while (dict_str[j] >= '0' && dict_str[j] <= '9')
		++j;
	(*src)[index] = (char *)malloc(j - i + 1);
	k = 0;
	while (i < j)
		(*src)[index][k++] = dict_str[i++];
	(*src)[index][k] = '\0';
	++index;
	return (j);
}

int	copy_value(char ***src, int i, char *dict_str)
{
	static int	index;
	int			k;
	int			j;

	j = i;
	while (dict_str[j] >= 32 && dict_str[j] <= 126)
		++j;
	(*src)[index] = (char *)malloc(j - i + 1);
	k = 0;
	while (i < j)
		(*src)[index][k++] = dict_str[i++];
	(*src)[index][k] = '\0';
	++index;
	return (j);
}

void	print_one_two_num(char **key, char **value, char *str, int i)
{
	while (++i >= 0 && i <= 19)
	{
		if (str_cmp2(str, key[i]) == 0)
		{
			put_str(value[i]);
			return ;
		}
	}
	if (str[0] >= '2' && str[1] == '0')
	{
		while (key[i])
		{
			if (str_cmp2(key[i], str) == 0)
			{
				put_str(value[i]);
				return ;
			}
			i++;
		}
	}
	print_one_two_num(key, value, give_tmp(str), -1);
	write(1, " ", 1);
	print_one_two_num(key, value, ++str, -1);
}

void	print_num(char **key, char **value, char *str, int size)
{
	t_mem_manage	data;

	while (*str == '0')
	{
		++str;
		if (0 == --size)
			return ;
	}
	if (size < 3)
	{
		print_one_two_num(key, value, str, -1);
		return ;
	}
	data_init(&data, key, str, size);
	print_num(key, value, data.front_str, data.front_size);
	write(1, " ", 1);
	put_str(value[data.key_index]);
	if (check_zero(data.back_str) == -1)
		write(1, " ", 1);
	print_num(key, value, data.back_str, size - data.front_size);
	free(data.front_str);
	free(data.back_str);
}
