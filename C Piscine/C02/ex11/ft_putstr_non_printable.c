/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siwonlee <tldnjs0821222@naver.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 20:22:36 by siwonlee          #+#    #+#             */
/*   Updated: 2023/01/15 15:32:31 by siwonlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr_non_printable(char *str)
{
	char			hex[2];
	char			*sixteen;
	unsigned char	temp;

	sixteen = "0123456789abcdef";
	hex[0] = '0';
	hex[1] = '0';
	while (*str)
	{
		temp = *str;
		if (temp >= 32 && temp <= 126)
			write(1, str, 1);
		else
		{
			write(1, "\\", 1);
			hex[0] = sixteen[temp / 16];
			hex[1] = sixteen[temp % 16];
			write(1, &hex[0], 1);
			write(1, &hex[1], 1);
		}
		str++;
	}
}
