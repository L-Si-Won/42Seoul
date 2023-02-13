/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siwonlee <tldnjs0821222@naver.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 22:15:17 by siwonlee          #+#    #+#             */
/*   Updated: 2023/01/12 11:14:16 by siwonlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_init(int n, int num[9])
{
	int		temp;

	num[0] = 0;
	temp = 1;
	while (temp < n)
	{
		num[temp] = num[temp - 1] + 1;
		temp++;
	}
}

void	ft_putchars(int n, int num[9])
{
	char	temp;
	int		idx;

	idx = 0;
	while (idx < n)
	{
		temp = num[idx] + '0';
		write(1, &temp, 1);
		idx++;
	}
}

void	ft_add(int n, int num[9])
{
	int		i;
	int		max;

	i = n - 1;
	max = 9;
	while (num[i] == max)
	{
		i--;
		max--;
	}
	num[i]++;
	while (i++ < n)
	{
		num[i] = num[i - 1] + 1;
	}
}

void	ft_print_combn(int n)
{
	int		num[9];

	ft_init(n, num);
	ft_putchars(n, num);
	while (num[0] != 9 - n + 1 || num[n - 1] != 9)
	{
		ft_add(n, num);
		write(1, ", ", 2);
		ft_putchars(n, num);
	}
}
