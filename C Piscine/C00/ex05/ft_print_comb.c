/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siwonlee <tldnjs0821222@naver.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 21:32:32 by siwonlee          #+#    #+#             */
/*   Updated: 2023/01/11 21:42:11 by siwonlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchars(int i, int j, int k)
{
	char	a;
	char	b;
	char	c;

	a = i + '0';
	b = j + '0';
	c = k + '0';
	write(1, &a, 1);
	write(1, &b, 1);
	write(1, &c, 1);
	if (i != 7 || j != 8 || k != 9)
		write(1, ", ", 2);
}

void	ft_print_comb(void)
{
	int		i;
	int		j;
	int		k;

	i = 0;
	while (i <= 9)
	{
		j = i + 1;
		while (j <= 9)
		{
			k = j + 1;
			while (k <= 9)
			{
				if (i != j && j != k && k != i)
					ft_putchars(i, j, k);
				k++;
			}
			j++;
		}
		i++;
	}
}
