/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanbkang <hanbkang@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 15:30:48 by hanbkang          #+#    #+#             */
/*   Updated: 2023/01/14 16:13:25 by siwonlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(const char c);

void	putstr(const char *str)
{
	while (*str != '\0')
	{
		ft_putchar(*str);
		str++;
	}
}

void	rush(const int x, const int y)
{
	int	a;
	int	b;

	if ((x <= 0 || y <= 0))
	{
		putstr("Please, enter a positive integer.\n");
		return ;
	}
	b = -1;
	while (++b < y)
	{
		a = -1;
		while (++a < x)
		{
			if ((a == 0 || a == x - 1) && b == 0)
				ft_putchar('A');
			else if ((a == 0 || a == x - 1) && b == y - 1)
				ft_putchar('C');
			else if (a == 0 || a == x - 1 || b == 0 || b == y - 1)
				ft_putchar('B');
			else
				ft_putchar(' ');
		}
		ft_putchar('\n');
	}
}
