/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siwonlee <tldnjs0821222@naver.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 17:21:32 by siwonlee          #+#    #+#             */
/*   Updated: 2023/01/12 22:13:07 by siwonlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_rev_int_tab(int *ab, int size)
{
	int	idx;
	int	temp;

	idx = 0;
	while (idx < size / 2)
	{
		temp = ab[idx];
		ab[idx] = ab[size - idx - 1];
		ab[size - idx - 1] = temp;
		idx++;
	}
}
