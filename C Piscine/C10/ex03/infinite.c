/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   infinite.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siwonlee <tldnjs0821222@naver.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 16:49:59 by siwonlee          #+#    #+#             */
/*   Updated: 2023/01/31 22:42:12 by siwonlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_h.h"

void	infinite_print(void)
{
	char	buf[17];
	char	*temp_buf;
	int		idx;

	buf_init(buf);
	idx = 0;
	temp_buf = NULL;
	while (read(0, &buf, 16))
	{
		duplicate_check(temp_buf, buf);
		if (g_flag == 0)
			temp_buf_init(buf, &temp_buf);
		if (g_flag == 1)
			print_addr_and_hex(buf, idx);
		idx += 16;
		buf_init(buf);
	}
	goinfre(temp_buf);
	print_address(idx - (16 - g_cnt));
	write(1, "\n", 1);
}

void	infinite_print_c(void)
{
	char	buf[17];
	char	*temp_buf;
	int		idx;

	buf_init(buf);
	idx = 0;
	temp_buf = NULL;
	while (read(0, &buf, 16))
	{
		duplicate_check(temp_buf, buf);
		if (g_flag == 0)
			temp_buf_init(buf, &temp_buf);
		if (g_flag == 1)
		{
			print_addr_and_hex(buf, idx);
			print_ascii_c(buf);
		}
		idx += 16;
		buf_init(buf);
	}
	goinfre(temp_buf);
	print_address(idx - (16 - g_cnt));
	write(1, "\n", 1);
}

void	infinite_input(int flag)
{
	if (flag == 0)
	{
		infinite_print();
	}
	else if (flag == 1)
	{
		infinite_print_c();
	}
}
