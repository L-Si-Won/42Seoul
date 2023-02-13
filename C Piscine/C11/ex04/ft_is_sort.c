/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siwonlee <tldnjs0821222@naver.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 15:19:49 by siwonlee          #+#    #+#             */
/*   Updated: 2023/01/26 10:20:15 by siwonlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	asc(int *tab, int length, int (*f)(int, int))
{
	int	idx;

	idx = 0;
	while (idx < length - 1)
	{
		if (f(tab[idx], tab[idx + 1]) > 0)
			return (0);
		idx++;
	}
	return (1);
}

int	dec(int *tab, int length, int (*f)(int, int))
{
	int	idx;

	idx = 0;
	while (idx < length - 1)
	{
		if (f(tab[idx], tab[idx + 1]) < 0)
			return (0);
		idx++;
	}
	return (1);
}

int	ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	if (asc(tab, length, f) == 1 || dec(tab, length, f) == 1)
		return (1);
	return (0);
}
