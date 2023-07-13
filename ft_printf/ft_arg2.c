/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arg2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siwonlee <siwonlee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 18:14:12 by siwonlee          #+#    #+#             */
/*   Updated: 2023/06/19 20:49:41 by siwonlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_u(va_list *vl)
{
	unsigned int	u;
	char			*s;
	int				ret;

	u = va_arg(*vl, unsigned int);
	s = ft_utoa(u);
	ft_putstr(s);
	ret = ft_strlen(s);
	if (s != NULL)
		free(s);
	return (ret);
}

int	ft_x(va_list *vl)
{
	unsigned int	x;
	int				ret;

	x = va_arg(*vl, unsigned int);
	if (x == 0)
	{
		write(1, "0", 1);
		ret = 1;
	}
	else
		ret = dec_to_hex(x);
	return (ret);
}

int	ft_upper_x(va_list *vl)
{
	unsigned int	upper_x;
	int				ret;

	upper_x = va_arg(*vl, unsigned int);
	if (upper_x == 0)
	{
		write(1, "0", 1);
		ret = 1;
	}
	else
		ret = dec_to_hex_upper(upper_x);
	return (ret);
}
