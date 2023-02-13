/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_program_name.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siwonlee <tldnjs0821222@naver.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 20:31:30 by siwonlee          #+#    #+#             */
/*   Updated: 2023/01/18 17:22:31 by siwonlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int argc, char *argv[])
{
	char	temp;

	temp = argc;
	while (*argv[0])
	{
		temp = *argv[0];
		write(1, &temp, 1);
		argv[0]++;
	}
	write(1, "\n", 1);
	return (0);
}
