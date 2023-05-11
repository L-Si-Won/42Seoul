/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siwonlee <siwonlee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 03:05:34 by siwonlee          #+#    #+#             */
/*   Updated: 2023/05/04 03:17:40 by siwonlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_sstrlen(const char *str)
{
	size_t	len;

	len = 0;
	while (str[len] != '\0')
	{
		len++;
	}
	return (len);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	src_len;
	size_t	idx;

	src_len = ft_sstrlen(src);
	idx = 0;
	if (dstsize == 0)
		return (src_len);
	while (idx < dstsize - 1)
	{
		if (src[idx] == '\0')
		{
			dst[idx] = '\0';
			break ;
		}
		dst[idx] = src[idx];
		idx++;
	}
	if (idx == dstsize - 1)
		dst[dstsize - 1] = '\0';
	return (src_len);
}
