/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siwonlee <tldnjs0821222@naver.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 21:43:32 by siwonlee          #+#    #+#             */
/*   Updated: 2023/01/11 22:07:49 by siwonlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchars(int i, int j)
{
	char	a;
	char	b;
	char	c;
	char	d;

	if (i < 10)
		a = '0';
	else
		a = i / 10 + '0';
	b = i % 10 + '0';
	if (j < 10)
		c = '0';
	else
		c = j / 10 + '0';
	d = j % 10 + '0';
	write(1, &a, 1);
	write(1, &b, 1);
	write(1, " ", 1);
	write(1, &c, 1);
	write(1, &d, 1);
	if (i != 98 || j != 99)
		write(1, ", ", 2);
}

void	ft_print_comb2(void)
{
	int		i;
	int		j;

	i = 0;
	while (i <= 99)
	{
		j = i + 1;
		while (j <= 99)
		{
			if (i != j)
				ft_putchars(i, j);
			j++;
		}
		i++;
	}
}
