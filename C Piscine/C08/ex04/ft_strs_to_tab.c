/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siwonlee <tldnjs0821222@naver.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 11:14:57 by siwonlee          #+#    #+#             */
/*   Updated: 2023/01/23 15:48:38 by siwonlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_stock_str.h"

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

void	ft_strcpy(char *s1, char *s2)
{
	while (*s2)
	{
		*s1 = *s2;
		s1++;
		s2++;
	}
	*s1 = '\0';
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	int					idx;
	struct s_stock_str	*result;

	result = (struct s_stock_str *)malloc(sizeof(struct s_stock_str)
			* (ac + 1));
	if (!(result))
		return (0);
	idx = 0;
	while (idx < ac && av[idx] != 0)
	{
		result[idx].str = (char *)malloc(sizeof(char)
				* (ft_strlen(av[idx]) + 1));
		result[idx].copy = (char *)malloc(sizeof(char)
				* (ft_strlen(av[idx]) + 1));
		result[idx].size = ft_strlen(av[idx]);
		ft_strcpy(result[idx].str, av[idx]);
		ft_strcpy(result[idx].copy, result[idx].str);
		idx++;
	}
	result[idx].size = 0;
	result[idx].str = 0;
	result[idx].copy = 0;
	return (result);
}
