/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siwonlee <tldnjs0821222@naver.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 17:36:51 by siwonlee          #+#    #+#             */
/*   Updated: 2023/01/14 19:37:12 by siwonlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_printable(char *str)
{
	int	flag;

	flag = 1;
	while (*str)
	{
		if (!(*str >= 32 && *str <= 126))
			flag = 0;
		str++;
	}
	return (flag);
}
