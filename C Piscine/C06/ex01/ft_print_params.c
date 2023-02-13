/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_params.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siwonlee <tldnjs0821222@naver.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 20:36:37 by siwonlee          #+#    #+#             */
/*   Updated: 2023/01/18 10:41:07 by siwonlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int argc, char *argv[])
{
	int	idx;
	int	argv_idx;

	idx = 1;
	while (idx < argc)
	{
		argv_idx = 0;
		while (argv[idx][argv_idx] != 0)
		{
			write(1, &argv[idx][argv_idx], 1);
			argv_idx++;
		}
		write(1, "\n", 1);
		idx++;
	}
	return (0);
}
