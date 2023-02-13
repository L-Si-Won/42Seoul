/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siwonlee <tldnjs0821222@naver.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 20:55:27 by siwonlee          #+#    #+#             */
/*   Updated: 2023/01/17 11:41:15 by siwonlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	dec_to_hex(unsigned long addr)
{
	char	*sixteen;
	char	hex[16];
	int		idx;

	sixteen = "0123456789abcdef";
	idx = 0;
	while (addr > 0)
	{
		hex[idx] = sixteen[addr % 16];
		addr /= 16;
		idx++;
	}
	while (--idx >= 0)
		write(1, &hex[idx], 1);
}

void	print_addr(unsigned long addr)
{
	unsigned int	non_zero;
	unsigned long	temp;

	non_zero = 0;
	temp = addr;
	while (temp > 0)
	{
		temp /= 16;
		non_zero++;
	}
	while (temp < 16 - non_zero)
	{
		write(1, "0", 1);
		temp++;
	}
	dec_to_hex(addr);
	write(1, ":", 1);
}

void	print_hex(unsigned char *addr, unsigned int len)
{
	unsigned int	idx;
	char			*sixteen;

	idx = 0;
	sixteen = "0123456789abcdef";
	while (idx < len)
	{
		if (idx % 2 == 0)
			write(1, " ", 1);
		write(1, &sixteen[addr[idx] / 16], 1);
		write(1, &sixteen[addr[idx] % 16], 1);
		idx++;
	}
	while (idx < 16)
	{
		if (idx % 2 == 0)
			write(1, " ", 1);
		write(1, "  ", 2);
		idx++;
	}
	write(1, " ", 1);
}

void	print_char(unsigned char *addr, unsigned int len)
{
	unsigned int	idx;

	idx = 0;
	while (idx < len)
	{
		if (*(addr + idx) >= 32 && *(addr + idx) <= 126)
			write(1, addr + idx, 1);
		else
			write(1, ".", 1);
		idx++;
	}
	write(1, "\n", 1);
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	unsigned int	cur_size;
	unsigned int	idx;

	idx = 0;
	while (size > 0)
	{
		if (size >= 16)
			cur_size = 16;
		else
			cur_size = size;
		print_addr((unsigned long)addr + idx);
		print_hex(addr + idx, cur_size);
		print_char(addr + idx, cur_size);
		size -= cur_size;
		idx += 16;
	}
	return (addr);
}
