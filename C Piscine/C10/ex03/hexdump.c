/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hexdump.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siwonlee <tldnjs0821222@naver.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 17:21:28 by siwonlee          #+#    #+#             */
/*   Updated: 2023/01/31 22:36:41 by siwonlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_h.h"

int	file_size(char *file_name)
{
	int		temp_fd;
	char	c;
	int		cnt;

	temp_fd = open(file_name, O_RDONLY);
	cnt = 0;
	while (read(temp_fd, &c, 1))
		cnt++;
	close(temp_fd);
	return (cnt);
}

void	hexdump(int argc, char *argv[])
{
	int	fd;
	int	idx;

	idx = 0;
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
			print_file(fd);
		global_init();
		close(fd);
	}
}

void	temp_buf_init(char buf[17], char **temp_buf)
{
	goinfre(*temp_buf);
	*temp_buf = ft_strdup(buf);
	g_flag = 1;
}

void	print_addr_and_hex(char buf[17], int idx)
{
	print_address(idx);
	print_hex(buf);
}

void	print_file(int fd)
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
			print_addr_and_hex(buf, idx);
		idx += 16;
		buf_init(buf);
	}
	goinfre(temp_buf);
	print_address(idx - (16 - g_cnt));
	write(1, "\n", 1);
}
