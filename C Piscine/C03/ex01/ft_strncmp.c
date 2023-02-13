/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siwonlee <tldnjs0821222@naver.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 16:07:39 by siwonlee          #+#    #+#             */
/*   Updated: 2023/01/16 14:27:51 by siwonlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	cnt;

	cnt = 0;
	while ((cnt < n) && (*s1 || *s2))
	{
		if (*s1 != *s2)
			return (*s1 - *s2);
		else
		{
			s1++;
			s2++;
			cnt++;
		}
	}
	return (0);
}
