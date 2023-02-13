/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siwonlee <tldnjs0821222@naver.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 17:02:24 by siwonlee          #+#    #+#             */
/*   Updated: 2023/01/12 22:12:32 by siwonlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *str)
{
	int		cnt;

	cnt = 0;
	while (1)
	{
		if (str[cnt] == '\0')
			break ;
		else
			cnt++;
	}
	return (cnt);
}
