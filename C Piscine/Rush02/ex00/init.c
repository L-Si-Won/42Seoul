/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonglim <seonglim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 07:14:54 by seonglim          #+#    #+#             */
/*   Updated: 2023/01/29 07:35:56 by seonglim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int	count_new_line(char *filename)
{
	int		fd;
	int		count;
	char	c;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (-1);
	count = 0;
	while (read(fd, &c, 1))
	{
		if (c == '\n')
			++count;
	}
	close(fd);
	return (count);
}

void	null_init(char ***key, char ***value, int size)
{
	int	i;

	i = -1;
	while (++i < size)
	{
		(*key)[i] = NULL;
		(*value)[i] = NULL;
	}
}

void	data_init(t_mem_manage *data, char **key, char *str, int size)
{
	data->key_index = find_key_index(key, size);
	data->front_size = size - str_len(key[data->key_index]) + 1;
	data->front_str = (char *)malloc(data->front_size + 1);
	data->back_str = (char *)malloc(size - data->front_size + 1);
	str_ncpy(data->front_str, str, data->front_size);
	str_ncpy(data->back_str, str + data->front_size, size - data->front_size);
}

int	alloc_dictionary(char ***key, char ***value, char *filename)
{
	int	count;

	count = count_new_line(filename);
	if (-1 == count)
		return (-100);
	*key = (char **)malloc(sizeof(char *) * (count + 1));
	*value = (char **)malloc(sizeof(char *) * (count + 1));
	null_init(key, value, count + 1);
	return (dict_split_alloc(key, value, filename));
}

int	alloc_with_argv(char ***key, char ***value, int argc, char **argv)
{
	int	flag;

	flag = -5000;
	if (argc == 3)
	{
		flag = alloc_dictionary(key, value, argv[1]);
		argv[1] = argv[2];
	}
	else
		flag = alloc_dictionary(key, value, "numbers.dict");
	return (flag);
}
