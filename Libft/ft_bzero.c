/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siwonlee <siwonlee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 02:25:35 by siwonlee          #+#    #+#             */
/*   Updated: 2023/05/04 02:31:29 by siwonlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t	idx;

	if (n == 0)
		return ;
	idx = 0;
	while (idx < n)
	{
		((char *)s)[idx] = 0;
		idx++;
	}
}
