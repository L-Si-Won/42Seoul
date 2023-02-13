/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_c.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siwonlee <tldnjs0821222@naver.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 14:42:28 by siwonlee          #+#    #+#             */
/*   Updated: 2023/01/28 16:14:48 by siwonlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_h.h"

void	print_address_c(int idx)
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
	write(1, " ", 1);
}

void	print_real_hex_c(char buf, int i)
{
	unsigned char	temp;

	if (buf >= 0 && buf <= 15)
		write(1, "0", 1);
	temp = buf;
	print_real_address(temp);
	if (i == 7)
		write(1, " ", 1);
}

void	print_hex_c(char *buf)
{
	int	i;
	int	temp;

	i = 0;
	while (buf[i] != '\0' && i < 16)
	{
		write(1, " ", 1);
		print_real_hex_c(buf[i], i);
		i++;
	}
	temp = i;
	if (temp != 16)
	{
		if (temp < 7)
			write(1, " ", 1);
		while (temp < 16)
		{
			write(1, "   ", 3);
			temp++;
		}
	}
	g_cnt = i;
}

void	print_ascii_c(char *buf)
{
	int	idx;

	idx = 0;
	write(1, "  |", 3);
	while (buf[idx] != 0 && idx < 16)
	{
		if (buf[idx] >= 32 && buf[idx] <= 127)
			write(1, &buf[idx], 1);
		else
			write(1, ".", 1);
		idx++;
	}
	write(1, "|\n", 2);
}
