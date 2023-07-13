/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arg1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siwonlee <siwonlee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 18:13:34 by siwonlee          #+#    #+#             */
/*   Updated: 2023/06/19 20:49:30 by siwonlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_c(va_list *vl)
{
	char	c;

	c = va_arg(*vl, int);
	write(1, &c, 1);
	return (1);
}

int	ft_s(va_list *vl)
{
	char	*s;

	s = va_arg(*vl, char *);
	if (s == NULL)
	{
		write(1, "(null)", 6);
		return (6);
	}
	ft_putstr(s);
	return (ft_strlen(s));
}

int	ft_p(va_list *vl)
{
	void	*p;

	p = va_arg(*vl, void *);
	if (p == NULL)
	{
		write(1, "0x0", 3);
		return (3);
	}
	return (ft_putaddr((unsigned long)p));
}

int	ft_d(va_list *vl)
{
	int		d;
	char	*s;
	int		ret;

	d = va_arg(*vl, int);
	s = ft_itoa(d);
	ft_putstr(s);
	ret = ft_strlen(s);
	if (s != NULL)
		free(s);
	return (ret);
}

int	ft_i(va_list *vl)
{
	int		i;
	char	*s;
	int		ret;

	i = va_arg(*vl, int);
	s = ft_itoa(i);
	ft_putstr(s);
	ret = ft_strlen(s);
	if (s != NULL)
		free(s);
	return (ret);
}
