/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siwonlee <tldnjs0821222@naver.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 11:27:52 by siwonlee          #+#    #+#             */
/*   Updated: 2023/01/14 15:17:53 by siwonlee         ###   ########.fr       */
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
			if ((a == 0 || a == x - 1) && (b == 0 || b == y - 1))
				ft_putchar('o');
			else if ((a != 0 || a != x - 1) && (b == 0 || b == y - 1))
				ft_putchar('-');
			else if ((a == 0 || a == x - 1) && (b != 0 || b != y - 1))
				ft_putchar('|');
			else if ((a != 0 || a != x - 1) && (b != 0 || b != y - 1))
				ft_putchar(' ');
		}
		ft_putchar('\n');
	}
}
