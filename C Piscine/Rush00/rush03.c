/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siwonlee <tldnjs0821222@naver.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 11:27:52 by siwonlee          #+#    #+#             */
/*   Updated: 2023/01/14 16:02:46 by siwonlee         ###   ########.fr       */
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

int	check_edge(const int x, const int y, const int a, const int b)
{
	int	flag;

	flag = 0;
	if ((a == 0 || a == x - 1) && (b != 0 && b != y - 1))
		flag = 1;
	else if ((a != 0 && a != x - 1) && (b == 0 || b == y - 1))
		flag = 1;
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
			if ((a == 0) && (b == 0 || b == y - 1))
				ft_putchar('A');
			else if ((a == x - 1) && (b == 0 || b == y - 1))
				ft_putchar('C');
			else if (check_edge(x, y, a, b) == 1)
				ft_putchar('B');
			else if ((a != 0 || a != x - 1) && (b != 0 || b != y - 1))
				ft_putchar(' ');
		}
		ft_putchar('\n');
	}
}
