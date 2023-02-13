/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoyu <yoyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 15:32:35 by yoyu              #+#    #+#             */
/*   Updated: 2023/01/14 17:23:31 by siwonlee         ###   ########.fr       */
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

void	side(const int x, const int y, const int a, const int b)
{
	if ((a == 0) && (b == 0))
		ft_putchar('/');
	else if (y == 1 || (x == 1 && y > 1))
		ft_putchar('\\');
	else if ((a == x -1) && (b == y -1))
		ft_putchar('/');
	else if ((b == y -1) && (a == 0))
		ft_putchar('\\');
	else if ((a == x -1) && (b == 0))
		ft_putchar('\\');
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
			if ((a == 0 || a == x -1) && (b == 0 || b == y -1))
				side(x, y, a, b);
			else if ((a != 0 || a != x - 1) && (b == 0 || b == y - 1))
				ft_putchar('*');
			else if ((a == 0 || a == x - 1) && (b != 0 || b != y - 1))
				ft_putchar('*');
			else if ((a != 0 || a != x - 1) && (b != 0 || b != y - 1))
				ft_putchar(' ');
		}
		ft_putchar('\n');
	}
}
