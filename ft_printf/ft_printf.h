/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siwonlee <siwonlee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 17:28:36 by siwonlee          #+#    #+#             */
/*   Updated: 2023/06/19 20:00:26 by siwonlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

int		ft_printf(const char *args, ...);
int		ft_arg_handler(char arg, va_list *vl);

int		ft_c(va_list *vl);
int		ft_s(va_list *vl);
int		ft_p(va_list *vl);
int		ft_d(va_list *vl);
int		ft_i(va_list *vl);
int		ft_u(va_list *vl);
int		ft_x(va_list *vl);
int		ft_upper_x(va_list *vl);

void	ft_putstr(char *s);
int		ft_strlen(char *s);
int		ft_putaddr(unsigned long addr);
int		dec_to_hex(unsigned long addr);
int		dec_to_hex_upper(unsigned long addr);

int		ft_numlen(int n);
char	*ft_itoa(int n);
int		ft_numlen_u(long long n);
char	*ft_utoa(long long n);

#endif
