/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siwonlee <tldnjs0821222@naver.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 15:09:42 by siwonlee          #+#    #+#             */
/*   Updated: 2023/01/16 15:27:30 by siwonlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_div_print(int n[10], int temp)
{
	int		cnt;
	char	cur;

	cnt = 0;
	while (temp != 0)
	{
		n[cnt] = temp % 10;
		cnt++;
		temp /= 10;
	}
	while (--cnt >= 0)
	{
		cur = n[cnt] +48;
		write(1, &cur, 1);
	}
}

void	ft_putnbr(int nb)
{
	int	n[10];
	int	temp;

	if (nb == 0)
	{
		write (1, "0", 1);
		return ;
	}
	if (nb == -2147483648)
	{
		write (1, "-2147483648", 11);
		return ;
	}
	temp = nb;
	if (temp < 0)
	{
		temp *= -1;
		write(1, "-", 1);
	}
	ft_div_print(n, temp);
}
