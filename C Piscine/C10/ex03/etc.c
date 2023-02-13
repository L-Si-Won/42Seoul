/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   etc.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siwonlee <tldnjs0821222@naver.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 12:42:25 by siwonlee          #+#    #+#             */
/*   Updated: 2023/01/31 22:27:37 by siwonlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_h.h"

void	global_init(void)
{
	g_flag = 0;
	g_star = 0;
	g_cnt = 0;
}

void	buf_init(char *buf)
{
	int	idx;

	idx = 0;
	while (idx < 17)
	{
		buf[idx] = 0;
		idx++;
	}
}

void	duplicate_check(char *temp_buf, char buf[17])
{
	if (g_flag == 1 || g_flag == -1)
	{
		if (ft_strcmp(temp_buf, buf) == 0)
		{
			if (g_star == 0)
			{
				write(1, "*\n", 2);
				g_star = 1;
			}
			g_flag = -1;
		}
		else
		{
			g_flag = 0;
			g_star = 0;
		}
	}
}

void	goinfre(char *ptr)
{
	free(ptr);
	ptr = NULL;
}
