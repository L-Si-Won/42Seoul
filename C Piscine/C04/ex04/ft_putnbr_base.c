/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siwonlee <tldnjs0821222@naver.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 17:54:53 by siwonlee          #+#    #+#             */
/*   Updated: 2023/01/21 22:15:28 by siwonlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (*str)
	{
		str++;
		len++;
	}
	return (len);
}

int	invalid_base(char *str)
{
	int	check[300];
	int	i;
	int	len;

	i = -1;
	len = ft_strlen(str);
	while (++i < 300)
		check[i] = 0;
	if (*str == '\0' || len == 1)
		return (1);
	while (*str)
	{
		if (*str == '-' || *str == '+')
			return (1);
		if (check[(int)*str] == 0)
			check[(int)*str] = 1;
		else if (check[(int)*str] == 1)
			return (1);
		str++;
	}
	return (0);
}

void	convert_print(long long nbr, char *base, char arr[40], int len)
{
	int	idx;

	idx = 0;
	while (nbr != 0)
	{
		arr[idx] = base[nbr % len];
		nbr /= len;
		idx++;
	}
	while (--idx >= 0)
		write(1, &arr[idx], 1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int			len;
	char		arr[40];
	int			idx;
	long long	temp;

	if (invalid_base(base) == 1)
		return ;
	len = ft_strlen(base);
	idx = 0;
	temp = nbr;
	if (temp == 0)
	{
		write(1, "0", 1);
		return ;
	}
	if (temp < 0)
	{
		write(1, "-", 1);
		temp *= -1;
	}
	convert_print(temp, base, arr, len);
}
