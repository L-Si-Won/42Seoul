/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_if.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siwonlee <tldnjs0821222@naver.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 15:15:26 by siwonlee          #+#    #+#             */
/*   Updated: 2023/01/25 15:18:52 by siwonlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_count_if(char **tab, int length, int (*f)(char*))
{
	int	cnt;
	int	idx;

	cnt = 0;
	idx = 0;
	while (idx < length)
	{
		if (f(tab[idx]) != 0)
			cnt++;
		idx++;
	}
	return (cnt);
}
