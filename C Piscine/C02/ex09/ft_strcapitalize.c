/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siwonlee <tldnjs0821222@naver.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 18:16:08 by siwonlee          #+#    #+#             */
/*   Updated: 2023/01/14 18:49:25 by siwonlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	check_letter(char c)
{
	int	flag;

	if (c >= 'a' && c <= 'z')
		flag = 1;
	else if (c >= 'A' && c <= 'Z')
		flag = 1;
	else if (c >= '0' && c <= '9')
		flag = 1;
	else
		flag = 0;
	return (flag);
}

char	*ft_strcapitalize(char *str)
{
	char	*temp;
	int		first;

	temp = str;
	first = 1;
	while (*str)
	{
		if (first == 1)
		{
			if (*str >= 'a' && *str <= 'z')
				*str -= 32;
			if (check_letter(*str) == 1)
				first = 0;
		}
		else
		{
			if (*str >= 'A' && *str <= 'Z')
				*str += 32;
			if (check_letter(*str) == 0)
				first = 1;
		}
		str++;
	}
	return (temp);
}
