/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tail.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siwonlee <tldnjs0821222@naver.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 13:23:11 by siwonlee          #+#    #+#             */
/*   Updated: 2023/01/27 20:24:39 by siwonlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_h.h"

void	no_file_print(char *argv[], int errnum, int idx)
{
	ft_putstr(basename(argv[0]));
	ft_putstr(": ");
	ft_putstr(argv[idx]);
	ft_putstr(": ");
	ft_putstr(strerror(errnum));
	ft_putstr("\n");
}

void	content_print(char *file_name, int fd, int byte_size)
{
	int		temp_fd;
	int		cur;
	char	c;
	int		i;

	i = 0;
	while (read(fd, &c, 1))
		i++;
	cur = 0;
	temp_fd = open(file_name, O_RDONLY);
	while (read(temp_fd, &c, 1))
	{
		if (cur >= i - byte_size)
			write(1, &c, 1);
		cur++;
	}
	close(temp_fd);
}

void	file_print(int argc, char *argv[], int idx, int fd)
{
	int		byte_size;

	byte_size = ft_atoi(argv[2]);
	if (byte_size < 0)
		byte_size *= -1;
	if (argc > 4)
	{
		if (g_flag == 1)
			write(1, "\n", 1);
		else
			g_flag = 1;
		ft_putstr("==> ");
		ft_putstr(argv[idx]);
		ft_putstr(" <==\n");
	}
	content_print(argv[idx], fd, byte_size);
}

int	main(int argc, char *argv[])
{
	int	idx;
	int	fd;

	if (exception(argc, argv) == 1)
		return (0);
	idx = 2;
	while (++idx < argc)
	{
		fd = open(argv[idx], O_RDONLY);
		if (fd < 0)
			no_file_print(argv, errno, idx);
		else
			file_print(argc, argv, idx, fd);
		close(fd);
	}
}
