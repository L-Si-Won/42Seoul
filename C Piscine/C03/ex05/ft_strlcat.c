/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siwonlee <tldnjs0821222@naver.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 10:59:06 by siwonlee          #+#    #+#             */
/*   Updated: 2023/01/16 14:41:58 by siwonlee         ###   ########.fr       */
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

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	d_len;
	unsigned int	s_len;
	unsigned int	idx;

	d_len = ft_strlen(dest);
	s_len = ft_strlen(src);
	idx = 0;
	while (*dest)
		dest++;
	while (*src && d_len + idx + 1 < size)
	{
		*dest = *src;
		dest++;
		src++;
		idx++;
	}
	*dest = '\0';
	if (d_len < size)
		return (d_len + s_len);
	else
		return (size + s_len);
}
