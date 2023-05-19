/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siwonlee <siwonlee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 21:19:03 by siwonlee          #+#    #+#             */
/*   Updated: 2023/05/04 01:31:13 by siwonlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_div_print(char n[11], int temp)
{
	int		cnt;
	int		n_cnt;
	char	temp_n[11];

	cnt = 0;
	while (temp != 0)
	{
		temp_n[cnt] = temp % 10 + '0';
		cnt++;
		temp /= 10;
	}
	n_cnt = 0;
	while (--cnt >= 0)
	{
		n[n_cnt++] = temp_n[cnt];
	}
	n[n_cnt] = '\0';
}

static int	ft_sstrlen(char num[11])
{
	int	idx;

	idx = 0;
	while (num[idx] != '\0')
	{
		idx++;
	}
	return (idx);
}

void	ft_putnbr_fd(int n, int fd)
{
	char	num[11];
	int		temp;

	if (n == 0)
	{
		write(fd, "0", 1);
		return ;
	}
	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return ;
	}
	temp = n;
	if (temp < 0)
	{
		temp *= -1;
		write(fd, "-", 1);
	}
	ft_div_print(num, temp);
	write(fd, num, ft_sstrlen(num));
}
