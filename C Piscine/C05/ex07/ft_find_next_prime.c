/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siwonlee <tldnjs0821222@naver.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 16:50:52 by siwonlee          #+#    #+#             */
/*   Updated: 2023/01/18 10:13:02 by siwonlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	check_prime(int nb)
{
	int	n;

	n = 2;
	while (n * n <= nb)
	{
		if (nb % n == 0)
			return (0);
		if (n >= 46341)
			return (1);
		n++;
	}
	return (1);
}

int	ft_find_next_prime(int nb)
{
	int	temp;

	if (nb <= 1)
		return (2);
	temp = nb;
	while (1)
	{
		if (check_prime(temp) == 1)
			return (temp);
		temp++;
	}
}
