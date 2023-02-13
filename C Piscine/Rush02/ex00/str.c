/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonglim <seonglim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 07:10:26 by seonglim          #+#    #+#             */
/*   Updated: 2023/01/29 07:11:14 by seonglim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int	str_cmp2(char *s1, char *s2)
{
	while (*s1 && *s2 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

int	str_cmp(char *s1, char *s2)
{
	int	s1_size;
	int	s2_size;

	s1_size = str_len(s1);
	s2_size = str_len(s2);
	if (s1_size != s2_size)
		return (s1_size - s2_size);
	return (str_cmp2(s1, s2));
}

void	str_cpy(char *dest, char *src)
{
	while (*src)
		*dest++ = *src++;
	*dest = *src;
}

void	str_ncpy(char *dest, char *src, int n)
{
	int	i;

	i = -1;
	while (++i < n && src[i])
		dest[i] = src[i];
	dest[i] = '\0';
}

int	str_len(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
		;
	return (i);
}
