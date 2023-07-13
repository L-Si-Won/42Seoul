/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siwonlee <siwonlee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 18:22:51 by siwonlee          #+#    #+#             */
/*   Updated: 2023/06/19 20:00:34 by siwonlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_strlen(char *s)
{
	int	len;

	len = 0;
	while (*(s++))
		len++;
	return (len);
}

void	ft_putstr(char *s)
{
	while (*s)
	{
		write(1, s, 1);
		s++;
	}
}

int	dec_to_hex(unsigned long addr)
{
	char	*sixteen;
	char	hex[16];
	int		idx;
	int		ret;

	sixteen = "0123456789abcdef";
	idx = 0;
	while (addr > 0)
	{
		hex[idx] = sixteen[addr % 16];
		addr /= 16;
		idx++;
	}
	ret = idx;
	while (--idx >= 0)
		write(1, &hex[idx], 1);
	return (ret);
}

int	dec_to_hex_upper(unsigned long addr)
{
	char	*sixteen;
	char	hex[16];
	int		idx;
	int		ret;

	sixteen = "0123456789ABCDEF";
	idx = 0;
	while (addr > 0)
	{
		hex[idx] = sixteen[addr % 16];
		addr /= 16;
		idx++;
	}
	ret = idx;
	while (--idx >= 0)
		write(1, &hex[idx], 1);
	return (ret);
}

int	ft_putaddr(unsigned long addr)
{
	int				non_zero;
	unsigned long	temp;

	non_zero = 0;
	temp = addr;
	while (temp > 0)
	{
		temp /= 16;
		non_zero++;
	}
	write(1, "0x", 2);
	dec_to_hex(addr);
	return (non_zero + 2);
}
