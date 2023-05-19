/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siwonlee <siwonlee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 04:35:38 by siwonlee          #+#    #+#             */
/*   Updated: 2023/05/11 03:27:24 by siwonlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void				*result;
	unsigned long long	idx;

	result = (void *)malloc((unsigned long long)size * count);
	if (result == NULL)
		return (NULL);
	idx = 0;
	while (idx < (unsigned long long)size * count)
	{
		((char *)result)[idx] = 0;
		idx++;
	}
	return (result);
}
