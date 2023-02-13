/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siwonlee <tldnjs0821222@naver.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 17:30:22 by siwonlee          #+#    #+#             */
/*   Updated: 2023/01/17 20:05:46 by siwonlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	g_queen[10];
int	g_cur_queen;
int	g_answer;

int	check(void)
{
	int	idx;
	int	abs_diff;

	idx = 0;
	while (idx < g_cur_queen)
	{
		abs_diff = g_queen[g_cur_queen] - g_queen[idx];
		if (abs_diff < 0)
			abs_diff *= -1;
		if (g_queen[idx] == g_queen[g_cur_queen])
			return (0);
		if (g_cur_queen - idx == abs_diff)
			return (0);
		idx++;
	}
	return (1);
}

void	print(void)
{
	int		print_idx;
	char	temp;

	print_idx = 0;
	while (print_idx < 10)
	{
		temp = g_queen[print_idx] + 48;
		write(1, &temp, 1);
		print_idx++;
	}
	write(1, "\n", 1);
	g_answer++;
	g_cur_queen--;
}

int	ft_ten_queens_puzzle(void)
{
	int	idx;

	if (g_cur_queen == 10)
	{
		print();
		return (g_answer);
	}
	idx = 0;
	while (idx < 10)
	{
		g_queen[g_cur_queen] = idx;
		if (check() == 1)
		{
			g_cur_queen++;
			ft_ten_queens_puzzle();
		}
		idx++;
	}
	g_cur_queen--;
	return (g_answer);
}
