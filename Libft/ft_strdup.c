/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siwonlee <siwonlee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 04:40:55 by siwonlee          #+#    #+#             */
/*   Updated: 2023/05/04 04:49:13 by siwonlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_sstrlen(char const *s)
{
	int	len;

	len = 0;
	while (s[len] != '\0')
	{
		len++;
	}
	return (len);
}

char	*ft_strdup(const char *s1)
{
	char	*result;
	int		idx;

	result = (char *)malloc(sizeof(char) * (ft_sstrlen(s1) + 1));
	if (result == NULL)
		return (NULL);
	idx = 0;
	while (s1[idx] != '\0')
	{
		result[idx] = s1[idx];
		idx++;
	}
	result[idx] = '\0';
	return (result);
}
