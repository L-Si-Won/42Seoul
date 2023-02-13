/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush04.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanbkang <hanbkang@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 15:48:39 by hanbkang          #+#    #+#             */
/*   Updated: 2023/01/14 16:12:02 by siwonlee         ###   ########.fr       */
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

int	should_print_a(int x, int y, int a, int b)
{
	int	flag;

	flag = ((a == 0 && b == 0) || (a == x - 1 && b == y - 1));
	if (b == 0 && a == x - 1 && x > 1 && y == 1)
		return (0);
	if (b == y - 1 && a == 0 && x == 1 && y > 1)
		return (0);
	return (flag);
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
			if (should_print_a(x, y, a, b))
				ft_putchar('A');
			else if ((a == 0 && b == y - 1) || (a == x - 1 && b == 0))
				ft_putchar('C');
			else if (a == 0 || a == x - 1 || b == 0 || b == y - 1)
				ft_putchar('B');
			else
				ft_putchar(' ');
		}
		ft_putchar('\n');
	}
}
