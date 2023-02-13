/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonglim <seonglim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 07:13:21 by seonglim          #+#    #+#             */
/*   Updated: 2023/01/29 23:06:56 by siwonlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int	dict_split_check(char ***key, char ***value, char *dict_str, int i)
{
	while (dict_str[++i])
	{
		if (dict_str[i] == '\n')
			continue ;
		if (dict_str[i] >= '0' && dict_str[i] <= '9')
		{
			i = copy_key(key, i, dict_str);
			while (dict_str[i] == ' ')
				++i;
			if (dict_str[i++] != ':')
				return (-1);
			while (dict_str[i] == ' ')
				++i;
			if (dict_str[i] == '\n')
				return (-1);
			if (dict_str[i] >= 32 && dict_str[i] <= 126)
				i = copy_value(value, i, dict_str);
			if (dict_str[i] != '\n')
				return (-1);
		}
		else
			return (-1);
	}
	return (1);
}

int	dict_split_alloc(char ***key, char ***value, char *filename)
{
	int		i;
	char	*dict_str;

	dict_str = str_arr(filename);
	if (!dict_str)
		return (-1);
	i = dict_split_check(key, value, dict_str, -1);
	free(dict_str);
	return (i);
}

int	size_dict(char **key)
{
	int	i;

	i = -1;
	while (key[++i])
		;
	return (i);
}

void	sort_dict(char **key, char **value)
{
	int	size;
	int	i;
	int	j;

	size = size_dict(key);
	i = -1;
	while (++i < size - 1)
	{
		j = -1;
		while (++j < size - 1 - i)
		{
			if (str_cmp(key[j], key[j + 1]) > 0)
				swap_ptr(key, value, j);
		}
	}
}

void	swap_ptr(char **key, char **value, int j)
{
	char	*tmp;

	tmp = key[j];
	key[j] = key[j + 1];
	key[j + 1] = tmp;
	tmp = value[j];
	value[j] = value[j + 1];
	value[j + 1] = tmp;
}
