/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siwonlee <tldnjs0821222@naver.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 20:47:58 by siwonlee          #+#    #+#             */
/*   Updated: 2023/01/27 18:18:47 by siwonlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>

void	ft_putstr(char *str)
{
	while (*str)
	{
		write(1, str, 1);
		str++;
	}
}

void	file_print(int fd)
{
	char	c;

	while (read(fd, &c, 1))
		write(1, &c, 1);
}

int	main(int argc, char *argv[])
{
	int		fd;

	if (argc < 2)
		ft_putstr("File name missing.\n");
	else if (argc > 2)
		ft_putstr("Too many arguments.\n");
	else
	{
		fd = open(argv[1], O_RDONLY);
		if (fd < 0)
		{
			ft_putstr("Cannot read file.\n");
			return (0);
		}
		file_print(fd);
		close(fd);
	}
	return (0);
}
