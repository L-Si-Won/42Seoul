/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siwonlee <tldnjs0821222@naver.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 11:59:56 by siwonlee          #+#    #+#             */
/*   Updated: 2023/01/22 00:16:57 by siwonlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	check_sep(char c, char *charset)
{
	while (*charset)
	{
		if (c == *charset)
			return (1);
		charset++;
	}
	return (0);
}

int	wc(char *str, char *charset)
{
	int	str_idx;
	int	cnt;

	cnt = 0;
	str_idx = 0;
	while (str[str_idx] != '\0')
	{
		if (str_idx == 0 && check_sep(str[str_idx], charset) == 0)
			cnt++;
		else if (str_idx != 0 && check_sep(str[str_idx], charset) == 0
			&& check_sep(str[str_idx - 1], charset) == 1)
			cnt++;
		str_idx++;
	}
	return (cnt);
}

int	*wl(char *str, char *charset, int word_cnt)
{
	int	*word_len;
	int	len_idx;
	int	str_idx;

	word_len = (int *)malloc(sizeof(int) * word_cnt);
	if (!(word_len))
		return (0);
	len_idx = -1;
	while (++len_idx < word_cnt)
		word_len[len_idx] = 1;
	len_idx = 0;
	str_idx = -1;
	while (str[++str_idx] != '\0')
	{
		if (check_sep(str[str_idx], charset) == 0)
			word_len[len_idx]++;
		else if (str_idx != 0 && check_sep(str[str_idx - 1], charset) == 0)
			len_idx++;
	}
	return (word_len);
}

void	str_split(char *str, char *charset, int *word_len, char **result)
{
	int	str_idx;
	int	i;
	int	j;

	str_idx = -1;
	i = 0;
	j = 0;
	while (str[++str_idx] != '\0')
	{
		if (check_sep(str[str_idx], charset) == 0)
		{
			if (str_idx == 0
				|| (str_idx != 0 && check_sep(str[str_idx - 1], charset) == 1))
				result[i] = (char *)malloc(sizeof(char) * word_len[i]);
			result[i][j++] = str[str_idx];
			result[i][j] = '\0';
		}
		else if (str_idx != 0 && check_sep(str[str_idx - 1], charset) == 0)
		{
			i++;
			j = 0;
		}
	}
}

char	**ft_split(char *str, char *charset)
{
	char	**result;
	int		word_cnt;
	int		*word_len;

	word_cnt = wc(str, charset);
	word_len = wl(str, charset, word_cnt);
	result = (char **)malloc(sizeof(char *) * (word_cnt + 1));
	str_split(str, charset, word_len, result);
	*(result + word_cnt) = 0;
	return (result);
}
