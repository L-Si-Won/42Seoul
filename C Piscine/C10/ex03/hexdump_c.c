/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hexdump_c.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siwonlee <tldnjs0821222@naver.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 17:52:46 by siwonlee          #+#    #+#             */
/*   Updated: 2023/01/31 22:39:18 by siwonlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_h.h"

void	hexdump_c(int argc, char *argv[])
{
	int	fd;
	int	idx;

	idx = 1;
	while (++idx < argc)
	{
		fd = open(argv[idx], O_RDONLY);
		if (fd < 0)
		{
			ft_putstr(basename(argv[0]));
			ft_putstr(": ");
			ft_putstr(argv[idx]);
			ft_putstr(": ");
			ft_putstr(strerror(errno));
			write(1, "\n", 1);
		}
		else if (file_size(argv[idx]) == 0)
			;
		else
			print_file_c(fd);
		global_init();
		close(fd);
	}
}

void	print_file_c(int fd)
{
	char	buf[17];
	char	*temp_buf;
	int		idx;

	buf_init(buf);
	idx = 0;
	temp_buf = NULL;
	while (read(fd, &buf, 16))
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
