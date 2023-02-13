/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siwonlee <tldnjs0821222@naver.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 21:50:40 by siwonlee          #+#    #+#             */
/*   Updated: 2023/01/20 22:55:58 by siwonlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str);
int	invalid_base(char *str);
int	ignore_cnt(char *nbr);

int	check_base(char *nbr, char *base)
{
	int	nbr_idx;
	int	base_idx;
	int	base_len;
	int	flag;

	nbr_idx = ignore_cnt(nbr);
	if (nbr_idx < 0)
		nbr_idx *= -1;
	nbr_idx--;
	base_len = ft_strlen(base);
	while (nbr[nbr_idx] != '\0')
	{
		base_idx = 0;
		flag = 0;
		while (base_idx < base_len)
		{
			if (nbr[nbr_idx] == base[base_idx])
				flag = 1;
			base_idx++;
		}
		if (flag == 0)
			return (0);
		nbr_idx++;
	}
	return (1);
}

long long	add_sum(int idx, char *nbr, char *base)
{
	long long	sum;
	int			base_idx;
	int			flag;

	sum = 0;
	while (*(nbr + idx))
	{
		base_idx = 0;
		flag = 0;
		while (base_idx < ft_strlen(base))
		{
			if (*(nbr + idx) == *(base + base_idx))
			{
				sum = sum * ft_strlen(base) + base_idx;
				flag = 1;
			}
			base_idx++;
		}
		if (flag == 0)
			break ;
		idx++;
	}
	return (sum);
}

long long	base_to_dec(char *result, char *nbr, char *base)
{
	long long	sum;
	int			idx;

	sum = 0;
	idx = ignore_cnt(nbr);
	if (idx < 0)
	{
		*result = '-';
		*(result + 1) = '\0';
		idx *= -1;
	}
	idx--;
	sum = add_sum(idx, nbr, base);
	return (sum);
}

void	dec_to_base(long long temp, char *base, char *result)
{
	char	arr[40];
	int		idx;

	while (*result)
		result++;
	idx = 0;
	while (temp != 0)
	{
		arr[idx] = base[temp % ft_strlen(base)];
		idx++;
		temp /= ft_strlen(base);
	}
	idx--;
	while (idx >= 0)
	{
		*result = arr[idx];
		idx--;
		result++;
	}
	*result = '\0';
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	char		*result;
	long long	temp;

	if (invalid_base(base_from) == 1 || invalid_base(base_to) == 1)
		return ((char *) '\0');
	result = (char *)malloc(sizeof(char) * 40);
	if (!(result))
		return (0);
	*result = '\0';
	temp = base_to_dec(result, nbr, base_from);
	if (temp == 0)
	{
		*result = *base_to;
		*(result + 1) = '\0';
		return (result);
	}
	dec_to_base(temp, base_to, result);
	return (result);
}
