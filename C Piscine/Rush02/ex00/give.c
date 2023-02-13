/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   give_buf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonglim <seonglim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 08:00:04 by seonglim          #+#    #+#             */
/*   Updated: 2023/01/29 18:00:09 by siwonlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

char	*give_buf(void)
{
	int			idx;
	static char	buf[10000];

	idx = 0;
	while (read(0, &buf[idx], 1))
	{
		if (buf[idx] == '\n')
			break ;
		idx++;
	}
	buf[idx] = '\0';
	return (buf);
}

char	*give_tmp(char *str)
{
	static char	tmp[3];

	tmp[0] = str[0];
	tmp[1] = '0';
	tmp[2] = '\0';
	return (tmp);
}
