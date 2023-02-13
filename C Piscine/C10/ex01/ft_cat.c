/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cat.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siwonlee <tldnjs0821222@naver.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 10:55:51 by siwonlee          #+#    #+#             */
/*   Updated: 2023/01/27 23:26:10 by siwonlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>
#include <libgen.h>

void	ft_putstr(char *str)
{
	while (*str)
	{
		write(1, str, 1);
		str++;
	}
}

void	no_file_print(char *argv[], int errnum, int argc_temp)
{
	ft_putstr(basename(argv[0]));
	write(1, ": ", 2);
	ft_putstr(argv[argc_temp]);
	write(1, ": ", 2);
	ft_putstr(strerror(errnum));
	write(1, "\n", 1);
}

void	infinite_input(void)
{
	char	c;

	while (read(0, &c, 1))
		write(1, &c, 1);
}

int	main(int argc, char *argv[])
{
	char	c;
	int		argc_temp;
	int		fd;

	if (argc == 1 || (argv[1][0] == '-' && argv[1][1] == '\0')
		|| (argv[1][0] == '-' && argv[1][1] == '-' && argv[1][2] == '\0'))
	{
		infinite_input();
		return (0);
	}
	argc_temp = 0;
	while (++argc_temp < argc)
	{
		fd = open(argv[argc_temp], O_RDONLY);
		if (fd < 0)
			no_file_print(argv, errno, argc_temp);
		else
			while (read(fd, &c, 1))
				write(1, &c, 1);
		close(fd);
	}
	return (0);
}
