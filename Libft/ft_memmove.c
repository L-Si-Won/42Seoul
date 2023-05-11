/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siwonlee <siwonlee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 02:49:14 by siwonlee          #+#    #+#             */
/*   Updated: 2023/05/04 03:04:52 by siwonlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	void	*temp;

	if (dst == NULL && src == NULL)
		return (0);
	temp = dst;
	if (src < dst)
	{
		src += len;
		dst += len;
		while (len--)
			*((char *)--dst) = *((char *)--src);
	}
	else
		while (len--)
			*((char *)dst++) = *((char *)src++);
	return (temp);
}
