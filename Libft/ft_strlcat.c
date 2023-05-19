/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siwonlee <siwonlee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 03:18:47 by siwonlee          #+#    #+#             */
/*   Updated: 2023/05/04 03:24:04 by siwonlee         ###   ########.fr       */
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

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	d_len;
	size_t	s_len;
	size_t	idx;

	d_len = ft_sstrlen(dst);
	s_len = ft_sstrlen(src);
	idx = 0;
	while (*dst)
		dst++;
	while (*src && d_len + idx + 1 < dstsize)
	{
		*dst = *src;
		dst++;
		src++;
		idx++;
	}
	*dst = '\0';
	if (d_len < dstsize)
		return (d_len + s_len);
	else
		return (dstsize + s_len);
}
