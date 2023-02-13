/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siwonlee <tldnjs0821222@naver.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 10:30:05 by siwonlee          #+#    #+#             */
/*   Updated: 2023/01/22 10:54:04 by siwonlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

void	pos_dfs(char **arr, char input[16], int pos[2], int visit[6][6]);
void	main_input(char input[16], char *argv[]);
int		check_input(int argc, char *argv[]);
char	**mallocation(void);
void	goinfre(char **arr);
void	arr_input(char input[16], char **arr);
void	arr_init(char **arr);
void	four_one(char **arr);
void	pos_visit_init(char **arr, int pos[2], int visit[6][6]);
void	print_answer(char **arr);
int		check_num(char **arr, int pos[2]);
void	pos_plus(int pos[2]);
void	print_str(char *str);
int		right(char **arr, char input[16]);

void	pos_minus(int pos[2])
{
	if (pos[1] == 1)
	{
		pos[0]--;
		pos[1] = 4;
	}
	else
		pos[1]--;
}

void	dfs(char **arr, char input[16], int pos[2], int visit[6][6])
{
	char	num;

	if ((pos[0] == 5 && pos[1] == 1)
		&& (right(arr, input) == 1 && arr[0][0] == '0'))
	{
		print_answer(arr);
		arr[0][0] = '1';
	}
	if (pos[0] == 5 && pos[1] == 1)
		return ;
	if (visit[pos[0]][pos[1]] == 0)
	{
		num = '0';
		while (++num <= '4')
		{
			arr[pos[0]][pos[1]] = num;
			visit[pos[0]][pos[1]] = 1;
			if (check_num(arr, pos) == 1)
				pos_dfs(arr, input, pos, visit);
			arr[pos[0]][pos[1]] = '0';
			visit[pos[0]][pos[1]] = 0;
		}
	}
	else
		pos_dfs(arr, input, pos, visit);
}

void	pos_dfs(char **arr, char input[16], int pos[2], int visit[6][6])
{
	pos_plus(pos);
	dfs(arr, input, pos, visit);
	pos_minus(pos);
}

int	ft_strlen(char *str)
{
	int	idx;

	idx = 0;
	while (*str)
	{
		idx++;
		str++;
	}
	return (idx);
}

int	main(int argc, char *argv[])
{
	char	input[16];
	char	**arr;
	int		pos[2];
	int		visit[6][6];

	if (check_input(argc, argv) == 0 || ft_strlen(argv[1]) > 31)
	{
		print_str("Error\n");
		return (0);
	}
	main_input(input, argv);
	arr = mallocation();
	arr_init(arr);
	arr_input(input, arr);
	four_one(arr);
	pos_visit_init(arr, pos, visit);
	arr[0][0] = '0';
	dfs(arr, input, pos, visit);
	if (arr[0][0] == '0')
		print_str("Error\n");
	goinfre(arr);
	return (0);
}
