/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siwonlee <tldnjs0821222@naver.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 11:55:50 by siwonlee          #+#    #+#             */
/*   Updated: 2023/01/20 19:22:47 by siwonlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

int	same_check(char *str)
{
	int	check[300];
	int	i;
	int	j;

	i = 0;
	while (i < 300)
	{
		check[i] = 0;
		i++;
	}
	i = 0;
	while (i < ft_strlen(str))
	{
		j = i + 1;
		while (j < ft_strlen(str))
		{
			if (str[i] == str[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	invalid_base(char *str)
{
	int	i;
	int	len;

	i = -1;
	len = ft_strlen(str);
	if (*str == '\0' || len == 1)
		return (1);
	if (same_check(str) == 1)
		return (1);
	while (*str)
	{
		if (*str == '-' || *str == '+')
			return (1);
		if (*str == 32 || (*str >= 9 && *str <= 13))
			return (1);
		str++;
	}
	return (0);
}

int	ignore_cnt(char *nbr)
{
	int	idx;
	int	sign;

	idx = 1;
	while (*nbr == 32 || (*nbr >= 9 && *nbr <= 13))
	{
		nbr++;
		idx++;
	}
	sign = 1;
	while (*nbr == '+' || *nbr == '-')
	{
		if (*nbr == '-')
			sign *= -1;
		nbr++;
		idx++;
	}
	return (idx * sign);
}
