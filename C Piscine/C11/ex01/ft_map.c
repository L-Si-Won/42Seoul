/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siwonlee <tldnjs0821222@naver.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 14:59:24 by siwonlee          #+#    #+#             */
/*   Updated: 2023/01/25 15:09:57 by siwonlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_map(int *tab, int length, int (*f)(int))
{
	int	idx;
	int	*arr;

	idx = 0;
	arr = (int *)malloc(sizeof(int) * (length));
	while (idx < length)
	{
		arr[idx] = f(tab[idx]);
		idx++;
	}
	return (arr);
}
