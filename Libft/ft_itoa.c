/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siwonlee <siwonlee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 05:16:03 by siwonlee          #+#    #+#             */
/*   Updated: 2023/05/14 15:40:39 by siwonlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_numlen(int n)
{
	int	count;

	count = 0;
	if (n <= 0)
		++count;
	while (n && ++count)
		n /= 10;
	return (count);
}

char	*ft_itoa(int n)
{
	int			len;
	char		*ret;
	const char	*digits = "0123456789";

	len = ft_numlen(n);
	ret = malloc(sizeof(char) * (len + 1));
	if (!ret)
		return (0);
	ret[len] = 0;
	if (n == 0)
		ret[0] = '0';
	if (n < 0)
		ret[0] = '-';
	while (n)
	{
		if (n > 0)
			ret[--len] = digits[n % 10];
		else
			ret[--len] = digits[n % 10 * -1];
		n /= 10;
	}
	return (ret);
}
