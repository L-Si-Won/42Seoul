/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siwonlee <tldnjs0821222@naver.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 12:48:30 by siwonlee          #+#    #+#             */
/*   Updated: 2023/01/23 13:43:39 by siwonlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_stock_str.h"

void	ft_putstr(char *str)
{
	while (*str)
	{
		write(1, str, 1);
		str++;
	}
	write(1, "\n", 1);
}

void	ft_putnbr(int size)
{
	char	temp[10];
	int		idx;

	if (size == 0)
	{
		write(1, "0\n", 2);
		return ;
	}
	idx = 0;
	while (size != 0)
	{
		temp[idx] = size % 10 + 48;
		idx++;
		size /= 10;
	}
	idx--;
	while (idx >= 0)
	{
		write(1, &temp[idx], 1);
		idx--;
	}
	write(1, "\n", 1);
}

void	ft_show_tab(struct s_stock_str *par)
{
	while ((*par).str != 0)
	{
		ft_putstr((*par).str);
		ft_putnbr((*par).size);
		ft_putstr((*par).copy);
		par++;
	}
}
