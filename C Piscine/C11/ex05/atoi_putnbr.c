/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putnbr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siwonlee <tldnjs0821222@naver.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 17:21:36 by siwonlee          #+#    #+#             */
/*   Updated: 2023/01/26 10:32:25 by siwonlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_div_print(int n[10], long long temp)
{
	int		cnt;
	char	cur;

	cnt = 0;
	while (temp != 0)
	{
		n[cnt] = temp % 10;
		cnt++;
		temp /= 10;
	}
	while (--cnt >= 0)
	{
		cur = n[cnt] + 48;
		write(1, &cur, 1);
	}
	write(1, "\n", 1);
}

void	ft_putnbr(int nb)
{
	int			n[10];
	long long	temp;

	if (nb == 0)
	{
		write (1, "0\n", 2);
		return ;
	}
	temp = nb;
	if (temp < 0)
	{
		temp *= -1;
		write(1, "-", 1);
	}
	ft_div_print(n, temp);
}

int	ft_atoi(char *str)
{
	int	result;
	int	sign;

	result = 0;
	sign = 1;
	while (*str == 32 || (*str >= 9 && *str <= 13))
		str++;
	while (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	if (!(*str >= '0' && *str <= '9'))
		return (0);
	while (*str >= '0' && *str <= '9')
	{
		result = result * 10 + *str - '0';
		str++;
	}
	if (sign == -1)
		result *= -1;
	return (result);
}
