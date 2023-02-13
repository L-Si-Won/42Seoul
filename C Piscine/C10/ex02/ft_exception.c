/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exception.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siwonlee <tldnjs0821222@naver.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 16:22:23 by siwonlee          #+#    #+#             */
/*   Updated: 2023/01/27 20:08:27 by siwonlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_h.h"

void	ft_putstr(char *str);
int		ft_atoi(char *str);

int	byte_check(char *byte)
{
	if (*byte == '-')
		byte++;
	while (*byte)
	{
		if (!(*byte >= '0' && *byte <= '9'))
			return (0);
		byte++;
	}
	return (1);
}

void	infinite_input(int argc, char *argv[], int idx, int cur)
{
	char		buf[100000];
	long long	byte_size;

	if (argc == 1)
	{
		while (read(0, &buf[idx], 1))
			idx++;
		buf[idx] = '\0';
		ft_putstr(buf);
	}
	else if (argc == 3)
	{
		while (read(0, &buf[idx], 1))
			idx++;
		buf[idx] = '\0';
		byte_size = ft_atoi(argv[2]);
		if (byte_size < 0)
			byte_size *= -1;
		cur = idx - byte_size;
		if (cur < 0)
			cur = 0;
		while (buf[cur] != 0)
			write(1, &buf[cur++], 1);
	}
}

int	exception(int argc, char *argv[])
{
	if (argc == 2)
	{
		ft_putstr(basename(argv[0]));
		ft_putstr(": option requires an argument -- c\n");
		ft_putstr("usage: tail [-F | -f | -r]");
		ft_putstr(" [-q] [-b # | -c # | -n #] [file ...]\n");
		return (1);
	}
	if (argc == 3 && byte_check(argv[2]) == 0)
	{
		ft_putstr(basename(argv[0]));
		ft_putstr(": illegal offset -- ");
		ft_putstr(argv[2]);
		write(1, "\n", 1);
		return (1);
	}
	if (argc == 1 || (argc == 3 && byte_check(argv[2]) == 1))
	{
		infinite_input(argc, argv, 0, 0);
		return (1);
	}
	return (0);
}
