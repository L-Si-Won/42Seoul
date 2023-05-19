/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siwonlee <siwonlee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 23:21:49 by siwonlee          #+#    #+#             */
/*   Updated: 2023/05/04 00:18:51 by siwonlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	int	idx;

	idx = 0;
	while (s[idx] != '\0')
	{
		write(fd, &s[idx], 1);
		idx++;
	}
	write(fd, "\n", 1);
}
