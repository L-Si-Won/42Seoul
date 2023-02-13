/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexdump.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siwonlee <tldnjs0821222@naver.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 16:50:04 by siwonlee          #+#    #+#             */
/*   Updated: 2023/01/31 23:03:41 by siwonlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_h.h"

int	main(int argc, char *argv[])
{
	if (argc >= 2)
	{
		if (argv[1][0] == '-' && argv[1][1] == 'C' && argv[1][2] == '\0')
		{
			g_len = 8;
			if (argc >= 3)
				hexdump_c(argc, argv);
			else if (argc == 2)
				infinite_input(1);
		}
		else
		{
			g_len = 7;
			hexdump(argc, argv);
		}
	}
	else if (argc == 1)
	{
		g_len = 7;
		infinite_input(0);
	}
	return (0);
}
