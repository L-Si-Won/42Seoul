/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siwonlee <tldnjs0821222@naver.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 19:59:21 by siwonlee          #+#    #+#             */
/*   Updated: 2023/01/15 22:32:35 by siwonlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	unsigned int	idx;
	char			*temp;

	temp = dest;
	while (*dest)
		dest++;
	idx = 0;
	while (idx < nb)
	{
		if (*src == '\0')
			break ;
		*dest = *src;
		dest++;
		src++;
		idx++;
	}
	*dest = '\0';
	return (temp);
}
