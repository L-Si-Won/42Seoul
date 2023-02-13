/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siwonlee <tldnjs0821222@naver.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 19:29:45 by siwonlee          #+#    #+#             */
/*   Updated: 2023/01/15 17:47:40 by siwonlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlen(char *str)
{
	unsigned int	len;

	len = 0;
	while (*str)
	{
		str++;
		len++;
	}
	return (len);
}

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	len;
	unsigned int	idx;

	len = ft_strlen(src);
	idx = 0;
	if (size == 0)
		return (len);
	while (idx < size - 1)
	{
		if (src[idx] == '\0')
		{
			dest[idx] = '\0';
			break ;
		}
		dest[idx] = src[idx];
		idx++;
	}
	if (idx == size - 1)
		dest[size - 1] = '\0';
	return (len);
}
