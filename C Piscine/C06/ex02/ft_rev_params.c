/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siwonlee <tldnjs0821222@naver.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 10:41:42 by siwonlee          #+#    #+#             */
/*   Updated: 2023/01/18 10:46:45 by siwonlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int argc, char *argv[])
{
	int		idx;
	char	*temp;

	idx = argc - 1;
	while (idx > 0)
	{
		temp = argv[idx];
		while (*temp)
		{
			write(1, temp, 1);
			temp++;
		}
		write(1, "\n", 1);
		idx--;
	}
	return (0);
}
