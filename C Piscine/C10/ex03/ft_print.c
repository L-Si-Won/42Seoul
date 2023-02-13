/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siwonlee <tldnjs0821222@naver.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 13:16:49 by siwonlee          #+#    #+#             */
/*   Updated: 2023/01/28 15:06:26 by siwonlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_h.h"

void	print_real_address(int idx)
{
	unsigned char	temp;

	if (idx < 10)
	{
		temp = idx + 48;
		write(1, &temp, 1);
	}
	else if (idx >= 10 && idx <= 15)
	{
		temp = idx + 87;
		write(1, &temp, 1);
	}
	else if (idx >= 16)
	{
		print_real_address(idx / 16);
		if (idx % 16 >= 10)
			temp = idx % 16 + 87;
		else
			temp = idx % 16 + 48;
		write(1, &temp, 1);
	}
}

void	print_address(int idx)
{
	int	cnt;
	int	i;
	int	temp;

	cnt = 0;
	temp = idx;
	while (temp != 0)
	{
		temp /= 16;
		cnt++;
	}
	i = 0;
	while (i < g_len - cnt)
	{
		write(1, "0", 1);
		i++;
	}
	if (idx != 0)
		print_real_address(idx);
}

void	print_real_hex(char buf)
{
	unsigned char	temp;

	if (buf >= 0 && buf <= 15)
		write(1, "0", 1);
	temp = buf;
	print_real_address(temp);
}

void	print_hex(char *buf)
{
	int	i;
	int	temp;

	i = 0;
	while (buf[i] != '\0' && i < 16)
	{
		write(1, " ", 1);
		print_real_hex(buf[i]);
		i++;
	}
	temp = i;
	if (temp != 16)
	{
		while (temp < 16)
		{
			write(1, "   ", 3);
			temp++;
		}
	}
	write(1, "\n", 1);
	g_cnt = i;
}
