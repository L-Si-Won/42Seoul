/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonglim <seonglim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 07:04:23 by seonglim          #+#    #+#             */
/*   Updated: 2023/01/29 22:55:21 by siwonlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int	goinfre(char **key, char **value, int flag)
{
	int	i;

	i = -1;
	while (key[++i])
	{
		free(key[i]);
		free(value[i]);
	}
	free(key);
	free(value);
	return (flag);
}

char	*str_arr(char *filename)
{
	int		fd;
	int		i;
	char	c;
	char	*str;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (NULL);
	i = 0;
	while (read(fd, &c, 1))
		++i;
	str = (char *)malloc(i + 1);
	if (!(str))
		return (NULL);
	str[i] = '\0';
	close(fd);
	i = 0;
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (NULL);
	while (read(fd, &str[i++], 1))
		;
	close(fd);
	return (str);
}

void	put_str(char *str)
{
	while (*str)
		write(1, str++, 1);
}

int	real_main(char **key, char **value, char **argv, int *flag)
{
	sort_dict(key, value);
	if (check_duplicate(key) == 1)
	{
		write(1, "Dict Error\n", 11);
		return (-1);
	}
	if (num_check(argv, flag) == -1)
		return (-1);
	if (check_zero(argv[1]) == 1)
		argv[1][1] = '\0';
	else if (*flag == 0)
		write(1, "minus ", 6);
	if (3 > str_len(argv[1]))
		print_one_two_num(key, value, argv[1], -1);
	else
		print_num(key, value, argv[1], str_len(argv[1]));
	write(1, "\n", 1);
	return (0);
}

int	main(int argc, char **argv)
{
	char	**key;
	char	**value;
	int		flag;
	char	*av[2];

	if (argc <= 3)
	{
		if (argc == 1)
		{
			av[1] = give_buf();
			argv = av;
		}
		flag = alloc_with_argv(&key, &value, argc, argv);
	}
	else
		return (-1);
	if (-1 == flag || -100 == flag)
	{
		write(1, "Dict Error\n", 11);
		if (-1 == flag)
			return (goinfre(key, value, -1));
		return (-1);
	}
	return (goinfre(key, value, real_main(key, value, argv, &flag)));
}
