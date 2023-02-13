/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siwonlee <tldnjs0821222@naver.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 17:38:19 by siwonlee          #+#    #+#             */
/*   Updated: 2023/01/31 22:18:15 by siwonlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_h.h"

void	ft_putstr(char *str)
{
	while (*str)
	{
		write(1, str, 1);
		str++;
	}
}

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (*str)
	{
		len++;
		str++;
	}
	return (len);
}

int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 || *s2)
	{
		if (*s1 != *s2)
			return (*s1 - *s2);
		s1++;
		s2++;
	}
	return (0);
}

char	*ft_strdup(char *str)
{
	char	*result;
	int		idx;

	result = (char *)malloc(sizeof(char) * (ft_strlen(str) + 1));
	if (!(result))
		return (0);
	idx = 0;
	while (*str)
	{
		result[idx] = *str;
		idx++;
		str++;
	}
	result[idx] = '\0';
	return (result);
}
