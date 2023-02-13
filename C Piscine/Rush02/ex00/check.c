/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonglim <seonglim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 07:06:50 by seonglim          #+#    #+#             */
/*   Updated: 2023/01/29 07:09:55 by seonglim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int	num_check(char **argv, int *flag)
{
	while (*argv[1] == ' ' || (*argv[1] >= 9 && *argv[1] <= 13))
		argv[1]++;
	if (*argv[1] == '+' || *argv[1] == '-')
	{
		if (*argv[1] == '-')
		{
			if (argv[1][1] < '0' || argv[1][1] > '9')
			{
				write(1, "Error\n", 6);
				return (-1);
			}
			*flag = 0;
		}
		argv[1]++;
	}
	if (check_char(argv[1]) == 1 || !*argv[1])
	{
		write(1, "Error\n", 6);
		return (-1);
	}
	return (1);
}

int	check_duplicate(char **key)
{
	int	i;

	i = -1;
	while (key[++i + 1])
		if (str_cmp2(key[i], key[i + 1]) == 0)
			return (1);
	return (-1);
}

void	check_size(int *size)
{
	if (*size > 37)
		*size = 37;
	if (*size >= 4 && *size <= 37)
	{
		if (*size % 3 == 0)
			*size -= 2;
		else if (*size % 3 == 2)
			*size -= 1;
	}
}

int	check_zero(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
		if (str[i] != '0')
			return (-1);
	return (1);
}

int	check_char(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
		if (str[i] < '0' || str[i] > '9')
			return (1);
	return (-1);
}
