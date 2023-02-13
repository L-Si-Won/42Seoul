/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siwonlee <tldnjs0821222@naver.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 15:35:21 by siwonlee          #+#    #+#             */
/*   Updated: 2023/01/19 18:02:10 by siwonlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

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

char	*ft_strdup(char *src)
{
	char	*str;
	int		idx;

	str = (char *)malloc(sizeof(char) * (ft_strlen(src) + 1));
	if (!(str))
		return (0);
	idx = 0;
	while (*src)
	{
		str[idx] = *src;
		idx++;
		src++;
	}
	str[idx] = '\0';
	return (str);
}
