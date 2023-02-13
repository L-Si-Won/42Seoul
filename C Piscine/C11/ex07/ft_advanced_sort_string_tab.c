/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_advanced_sort_string_tab.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siwonlee <tldnjs0821222@naver.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 19:39:18 by siwonlee          #+#    #+#             */
/*   Updated: 2023/01/25 20:59:29 by siwonlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_advanced_sort_string_tab(char **tab, int (*cmp)(char *, char *))
{
	int		i;
	int		flag;
	char	*temp;

	i = 0;
	flag = 1;
	while (flag == 1)
	{
		i = 1;
		flag = 0;
		while (tab[i] != 0)
		{
			if (cmp(tab[i - 1], tab[i]) > 0)
			{
				temp = tab[i - 1];
				tab[i - 1] = tab[i];
				tab[i] = temp;
				flag = 1;
			}
			i++;
		}
	}
}
