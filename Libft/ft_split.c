/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siwonlee <siwonlee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 21:01:34 by siwonlee          #+#    #+#             */
/*   Updated: 2023/05/11 02:28:03 by siwonlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	countn(char const *s, char c)
{
	size_t	count;
	size_t	len;

	if (!s[0])
		return (0);
	len = 0;
	count = 0;
	while (s[len] && s[len] == c)
		len++;
	while (s[len])
	{
		if (s[len] == c)
		{
			count++;
			while (s[len] && s[len] == c)
				len++;
			continue ;
		}
		len++;
	}
	if (s[len - 1] != c)
		count++;
	return (count);
}

static void	goinfre(char ***res, int count)
{
	int	idx;

	idx = 0;
	while (idx < count)
	{
		free((*res)[idx]);
		idx++;
	}
}

static int	ft_fill_matrix(char const *s, char c, size_t num, char **res)
{
	size_t	count;
	char	*start_str;
	int		lenword;

	count = 0;
	start_str = (char *)s;
	while (count < num)
	{
		lenword = 0;
		while (*start_str == c && *start_str != 0)
			++start_str;
		while (start_str[lenword] != c && start_str[lenword] != 0)
			lenword++;
		res[count] = ft_substr(start_str, 0, lenword);
		if (res[count] == NULL)
		{
			goinfre(&res, count);
			return (-1);
		}
		start_str += lenword;
		count++;
	}
	res[count] = 0;
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char	**res;
	size_t	num;

	res = NULL;
	if (!s)
		return (NULL);
	num = countn(s, c);
	res = (char **)malloc(sizeof(char *) * (num + 1));
	if (!res)
		return (NULL);
	if (ft_fill_matrix(s, c, num, res) == -1)
	{
		free(res);
		return (NULL);
	}
	return (res);
}
