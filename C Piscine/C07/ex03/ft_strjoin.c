/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siwonlee <tldnjs0821222@naver.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 19:40:45 by siwonlee          #+#    #+#             */
/*   Updated: 2023/01/21 22:19:00 by siwonlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

unsigned int	strs_len(char **strs, int size)
{
	unsigned int	len;
	int				i;
	int				j;

	len = 0;
	i = 0;
	while (i < size)
	{
		j = 0;
		while (strs[i][j] != '\0')
		{
			len++;
			j++;
		}
		i++;
	}
	return (len);
}

unsigned int	sep_length(char *sep)
{
	unsigned int	len;

	len = 0;
	while (*sep)
	{
		sep++;
		len++;
	}
	return (len);
}

void	join(int size, char **strs, char *sep, char *result)
{
	int	result_idx;
	int	i;
	int	j;

	i = -1;
	result_idx = 0;
	while (++i < size)
	{
		j = 0;
		while (strs[i][j] != '\0')
		{
			result[result_idx] = strs[i][j];
			result_idx++;
			j++;
		}
		j = 0;
		while (i != size - 1 && sep[j] != '\0')
		{
			result[result_idx] = sep[j];
			result_idx++;
			j++;
		}
	}
	result[result_idx] = '\0';
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char			*result;
	unsigned int	total_len;
	unsigned int	sep_len;

	if (size == 0)
	{
		result = (char *)malloc(sizeof(char));
		*result = '\0';
		return (result);
	}
	total_len = strs_len(strs, size);
	sep_len = sep_length(sep);
	result = (char *)malloc(sizeof(char) * (total_len + sep_len * size));
	if (!(result))
		return (0);
	join(size, strs, sep, result);
	return (result);
}
