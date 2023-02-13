/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siwonlee <tldnjs0821222@naver.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 16:30:01 by siwonlee          #+#    #+#             */
/*   Updated: 2023/01/21 17:08:32 by siwonlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

void	print_str(char *str)
{
	while (*str)
	{
		write(1, str, 1);
		str++;
	}
}

void	main_input(char input[16], char *argv[])
{
	int	idx;
	int	input_idx;

	idx = 0;
	input_idx = 0;
	while (idx <= 30)
	{
		if (idx % 2 == 0)
		{
			input[input_idx] = argv[1][idx];
			input_idx++;
		}
		idx++;
	}
}

int	check_input(int argc, char *argv[])
{
	int	cnt;
	int	idx;

	if (argc > 2)
		return (0);
	cnt = 0;
	idx = 0;
	while (argv[1][idx] != 0)
	{
		if (idx <= 30)
		{
			if (idx % 2 == 0 && !(argv[1][idx] >= '1' && argv[1][idx] <= '4'))
				return (0);
			else if (idx % 2 == 0
				&& (argv[1][idx] >= '1' && argv[1][idx] <= '4'))
				cnt++;
			else if (idx % 2 != 0 && argv[1][idx] != ' ')
				return (0);
		}
		idx++;
	}
	if (cnt != 16)
		return (0);
	return (1);
}

char	**mallocation(void)
{
	char	**arr;
	int		idx;

	arr = (char **)malloc(sizeof(char *) * 6);
	if (!(arr))
		return (0);
	idx = 0;
	while (idx < 6)
	{
		arr[idx] = (char *)malloc(sizeof(char) * 6);
		if (!(arr[idx]))
			return (0);
		idx++;
	}
	return (arr);
}

void	goinfre(char **arr)
{
	int		idx;

	idx = 0;
	while (idx < 6)
	{
		free(arr[idx]);
		idx++;
	}
	free(arr);
}
