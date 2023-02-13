/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush03.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siwonlee <tldnjs0821222@naver.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 16:42:21 by siwonlee          #+#    #+#             */
/*   Updated: 2023/01/21 17:00:28 by siwonlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	four_one_if1(char **arr, int i, int j);
void	four_one_if2(char **arr, int j);
void	four_one_if3(char **arr, int i);

void	four_one(char **arr)
{
	int	i;
	int	j;

	i = 1;
	while (i <= 4)
	{
		j = 1;
		while (j <= 4)
		{
			four_one_if1(arr, i, j);
			four_one_if2(arr, j);
			four_one_if3(arr, i);
			j++;
		}
		i++;
	}
}

void	pos_visit_init(char **arr, int pos[2], int visit[6][6])
{
	int	i;
	int	j;

	pos[0] = 1;
	pos[1] = 1;
	i = 1;
	while (i < 6)
	{
		j = 1;
		while (j < 6)
		{
			if (arr[i][j] != '0')
				visit[i][j] = 1;
			else
				visit[i][j] = 0;
			j++;
		}
		i++;
	}
}

void	print_answer(char **arr)
{
	int	i;
	int	j;

	i = 1;
	while (i < 5)
	{
		j = 1;
		while (j < 5)
		{
			write(1, &arr[i][j], 1);
			if (j != 4)
				write(1, " ", 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
}

int	check_num(char **arr, int pos[2])
{
	int	i;

	i = 1;
	while (i < 5)
	{
		if (i != pos[0] && arr[i][pos[1]] == arr[pos[0]][pos[1]])
			return (0);
		i++;
	}
	i = 1;
	while (i < 5)
	{
		if (i != pos[1] && arr[pos[0]][i] == arr[pos[0]][pos[1]])
			return (0);
		i++;
	}
	return (1);
}

int	up_down(char **arr, int idx)
{
	int	i;
	int	cnt;
	int	temp;

	i = 2;
	cnt = 1;
	temp = arr[1][idx + 1];
	while (i <= 4)
	{
		if (temp < arr[i][idx + 1])
		{
			cnt++;
			temp = arr[i][idx + 1];
		}
		i++;
	}
	return (cnt);
}
