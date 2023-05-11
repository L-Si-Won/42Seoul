/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siwonlee <siwonlee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 21:12:38 by siwonlee          #+#    #+#             */
/*   Updated: 2023/05/04 01:31:32 by siwonlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_sstrlen(char const *s)
{
	int	len;

	len = 0;
	while (s[len] != '\0')
	{
		len++;
	}
	return (len);
}

static char	*case_null(char *str)
{
	str = (char *)malloc(1);
	if (str != NULL)
		str[0] = '\0';
	return (str);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*str;
	unsigned int	cnt;
	unsigned int	str_len;

	str_len = ft_sstrlen(s);
	str = NULL;
	if (str_len <= start)
		return (case_null(str));
	if (str_len < len)
		str = (char *)malloc(sizeof(char) * (str_len - start + 1));
	else
	{
		if (str_len - start < len)
			str = (char *)malloc(sizeof(char) * (str_len - start + 1));
		else
			str = (char *)malloc(sizeof(char) * (len + 1));
	}
	if (str == NULL)
		return (NULL);
	cnt = -1;
	while (s[start + ++cnt] != '\0' && cnt < len)
		str[cnt] = s[start + cnt];
	str[cnt] = '\0';
	return (str);
}
