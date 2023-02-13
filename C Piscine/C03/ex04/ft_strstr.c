/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siwonlee <tldnjs0821222@naver.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 10:27:14 by siwonlee          #+#    #+#             */
/*   Updated: 2023/01/16 10:58:21 by siwonlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char *str, char *to_find)
{
	char	*pos;
	char	*find_pos;

	if (*to_find == '\0')
		return (str);
	while (*str)
	{
		if (*str == *to_find)
		{
			pos = str + 1;
			find_pos = to_find + 1;
			while (*pos && *find_pos && *pos == *find_pos)
			{
				pos++;
				find_pos++;
			}
			if (*find_pos == '\0')
				return (str);
			if (*pos == '\0')
				break ;
		}
		str++;
	}
	return ((char *) '\0');
}
