/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siwonlee <tldnjs0821222@naver.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 10:20:23 by siwonlee          #+#    #+#             */
/*   Updated: 2023/01/17 15:34:26 by siwonlee         ###   ########.fr       */
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
		if (*str == 32 || (*str >= 9 && *str <= 13))
			return (1);
		if (check[(int)*str] == 0)
			check[(int)*str] = 1;
		else if (check[(int)*str] == 1)
			return (1);
		str++;
	}
	return (0);
}

void	base_to_num(char *str, char *base, int arr[40])
{
	int	str_idx;
	int	base_idx;
	int	str_len;
	int	base_len;

	str_idx = 0;
	base_idx = 0;
	str_len = ft_strlen(str);
	base_len = ft_strlen(base);
	while (str_idx < str_len)
	{
		base_idx = 0;
		while (base_idx < base_len)
		{
			if (str[str_idx] == base[base_idx])
			{
				arr[str_idx] = base_idx;
				break ;
			}
			base_idx++;
		}
		str_idx++;
	}
}

int	ft_atoi_base(char *str, char *base)
{
	int	result;
	int	str_len;
	int	base_len;
	int	arr[40];
	int	power;

	if (invalid_base(base) == 1)
		return (0);
	base_to_num(str, base, arr);
	str_len = ft_strlen(str);
	base_len = ft_strlen(base);
	result = 0;
	power = 1;
	while (--str_len >= 0)
	{
		result += arr[str_len] * power;
		power *= base_len;
	}
	return (result);
}
