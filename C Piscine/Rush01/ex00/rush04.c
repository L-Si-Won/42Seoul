/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush04.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siwonlee <tldnjs0821222@naver.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 16:44:55 by siwonlee          #+#    #+#             */
/*   Updated: 2023/01/21 16:55:27 by siwonlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	up_down(char **arr, int idx);

int	down_up(char **arr, int idx)
{
	int	i;
	int	cnt;
	int	temp;

	i = 3;
	cnt = 1;
	temp = arr[4][idx - 4 + 1];
	while (i >= 1)
	{
		if (temp < arr[i][idx - 4 + 1])
		{
			cnt++;
			temp = arr[i][idx - 4 + 1];
		}
		i--;
	}
	return (cnt);
}

int	left_right(char **arr, int idx)
{
	int	i;
	int	cnt;
	int	temp;

	i = 2;
	cnt = 1;
	temp = arr[idx - 8 + 1][1];
	while (i <= 4)
	{
		if (temp < arr[idx - 8 + 1][i])
		{
			cnt++;
			temp = arr[idx - 8 + 1][i];
		}
		i++;
	}
	return (cnt);
}

int	right_left(char **arr, int idx)
{
	int	i;
	int	cnt;
	int	temp;

	i = 3;
	cnt = 1;
	temp = arr[idx - 12 + 1][4];
	while (i >= 1)
	{
		if (temp < arr[idx - 12 + 1][i])
		{
			cnt++;
			temp = arr[idx - 12 + 1][i];
		}
		i--;
	}
	return (cnt);
}

int	right(char **arr, char input[16])
{
	int	idx;
	int	cnt;

	idx = 0;
	while (idx < 16)
	{
		if (idx >= 0 && idx <= 3)
			cnt = up_down(arr, idx);
		else if (idx >= 4 && idx <= 7)
			cnt = down_up(arr, idx);
		else if (idx >= 8 && idx <= 11)
			cnt = left_right(arr, idx);
		else
			cnt = right_left(arr, idx);
		if (cnt != input[idx] - 48)
			return (0);
		idx++;
	}
	return (1);
}

void	pos_plus(int pos[2])
{
	if (pos[1] == 4)
	{
		pos[0]++;
		pos[1] = 1;
	}
	else
		pos[1]++;
}
