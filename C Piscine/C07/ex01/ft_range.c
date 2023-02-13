/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siwonlee <tldnjs0821222@naver.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 16:49:29 by siwonlee          #+#    #+#             */
/*   Updated: 2023/01/19 17:25:08 by siwonlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	*arr;
	int	idx;
	int	temp;

	if (min >= max)
		return (0);
	arr = (int *)malloc(sizeof(int) * (max - min));
	if (!(arr))
		return (0);
	idx = 0;
	temp = min;
	while (idx < (max - min))
	{
		arr[idx] = temp;
		idx++;
		temp++;
	}
	return (arr);
}
