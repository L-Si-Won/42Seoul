/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siwonlee <tldnjs0821222@naver.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 16:39:20 by siwonlee          #+#    #+#             */
/*   Updated: 2023/01/21 17:00:00 by siwonlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	arr_input(char input[16], char **arr)
{
	int	idx;
	int	arr_idx;

	idx = -1;
	arr_idx = 1;
	while (++idx < 16)
	{
		if (idx == 4 || idx == 8 || idx == 12)
			arr_idx = 1;
		if (idx >= 0 && idx <= 3)
			arr[0][arr_idx++] = input[idx];
		else if (idx >= 4 && idx <= 7)
			arr[5][arr_idx++] = input[idx];
		else if (idx >= 8 && idx <= 11)
			arr[arr_idx++][0] = input[idx];
		else
			arr[arr_idx++][5] = input[idx];
	}
}

void	arr_init(char **arr)
{
	int	i;
	int	j;

	i = 0;
	while (i < 6)
	{
		j = 0;
		while (j < 6)
		{
			arr[i][j] = '0';
			j++;
		}
		i++;
	}
}

void	four_one_if1(char **arr, int i, int j)
{
	if (arr[i][0] == '1')
		arr[i][1] = '4';
	if (arr[i][5] == '1')
		arr[i][4] = '4';
	if (arr[0][j] == '1')
		arr[1][j] = '4';
	if (arr[5][j] == '1')
		arr[4][j] = '4';
}

void	four_one_if2(char **arr, int j)
{
	if (arr[0][j] == '4')
	{
		arr[1][j] = '1';
		arr[2][j] = '2';
		arr[3][j] = '3';
		arr[4][j] = '4';
	}
	if (arr[5][j] == '4')
	{
		arr[4][j] = '1';
		arr[3][j] = '2';
		arr[2][j] = '3';
		arr[1][j] = '4';
	}
}

void	four_one_if3(char **arr, int i)
{
	if (arr[i][0] == '4')
	{
		arr[i][1] = '1';
		arr[i][2] = '2';
		arr[i][3] = '3';
		arr[i][4] = '4';
	}
	if (arr[i][5] == '4')
	{
		arr[i][4] = '4';
		arr[i][3] = '3';
		arr[i][2] = '2';
		arr[i][1] = '1';
	}
}
