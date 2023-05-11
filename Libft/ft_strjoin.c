/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siwonlee <siwonlee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 04:50:27 by siwonlee          #+#    #+#             */
/*   Updated: 2023/05/04 04:56:21 by siwonlee         ###   ########.fr       */
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

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*result;
	int		len1;
	int		len2;
	int		idx;

	len1 = ft_sstrlen(s1);
	len2 = ft_sstrlen(s2);
	result = (char *)malloc(sizeof(char) * (len1 + len2 + 1));
	if (result == NULL)
		return (NULL);
	idx = 0;
	while (idx < len1 + len2)
	{
		if (idx < len1)
			result[idx] = s1[idx];
		else
			result[idx] = s2[idx - len1];
		idx++;
	}
	result[idx] = '\0';
	return (result);
}
