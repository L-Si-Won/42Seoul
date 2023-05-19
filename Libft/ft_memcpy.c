/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siwonlee <siwonlee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 02:40:47 by siwonlee          #+#    #+#             */
/*   Updated: 2023/05/11 02:26:19 by siwonlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	idx;

	if (src == NULL && dst == NULL)
		return (NULL);
	idx = 0;
	while (idx < n)
	{
		((char *)dst)[idx] = ((char *)src)[idx];
		idx++;
	}
	return (dst);
}
