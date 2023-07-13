/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siwonlee <siwonlee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 17:28:16 by siwonlee          #+#    #+#             */
/*   Updated: 2023/06/19 20:51:59 by siwonlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_arg_handler(char arg, va_list *vl)
{
	if (arg == 'c')
		return (ft_c(vl));
	else if (arg == 's')
		return (ft_s(vl));
	else if (arg == 'p')
		return (ft_p(vl));
	else if (arg == 'd')
		return (ft_d(vl));
	else if (arg == 'i')
		return (ft_i(vl));
	else if (arg == 'u')
		return (ft_u(vl));
	else if (arg == 'x')
		return (ft_x(vl));
	else if (arg == 'X')
		return (ft_upper_x(vl));
	else
		return (0);
}

int	ft_printf(const char *args, ...)
{
	int		idx;
	int		ret;
	va_list	vl;

	va_start(vl, args);
	ret = 0;
	idx = -1;
	while (args[++idx] != '\0')
	{
		if (args[idx] == '%')
		{
			if (args[idx + 1] == '%')
				write(1, "%%", 1);
			else
				ret += ft_arg_handler(args[idx + 1], &vl) - 1;
			idx++;
		}
		else
			write(1, &args[idx], 1);
		ret++;
	}
	return (ret);
}
