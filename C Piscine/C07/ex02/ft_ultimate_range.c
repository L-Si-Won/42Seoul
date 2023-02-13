/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siwonlee <tldnjs0821222@naver.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 17:52:46 by siwonlee          #+#    #+#             */
/*   Updated: 2023/01/19 17:45:15 by siwonlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	*arr;
	int	idx;
	int	temp;

	if (min >= max)
		return (0);
	arr = (int *)malloc(sizeof(int) * (max - min));
	if (!(arr))
		return (-1);
	idx = 0;
	temp = min;
	while (idx < max - min)
	{
		arr[idx] = temp;
		idx++;
		temp++;
	}
	*range = arr;
	return (max - min);
}
