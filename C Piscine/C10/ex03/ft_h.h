/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_h.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siwonlee <tldnjs0821222@naver.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 12:07:29 by siwonlee          #+#    #+#             */
/*   Updated: 2023/01/31 22:36:58 by siwonlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_H_H
# define FT_H_H

# include <unistd.h>
# include <errno.h>
# include <libgen.h>
# include <fcntl.h>
# include <string.h>
# include <stdlib.h>

void	hexdump(int argc, char *argv[]);
void	hexdump_c(int argc, char *argv[]);
void	print_file(int fd);
void	print_file_c(int fd);
void	ft_putstr(char *str);
int		ft_strlen(char *str);
int		ft_strcmp(char *s1, char *s2);
char	*ft_strdup(char *str);
void	global_init(void);
void	buf_init(char *buf);
void	duplicate_check(char *temp_buf, char buf[17]);
void	print_real_address(int idx);
void	print_address(int idx);
void	print_real_hex(char buf);
void	print_hex(char *buf);
void	print_address_c(int idx);
void	print_real_hex_c(char buf, int i);
void	print_hex_c(char *buf);
void	print_ascii_c(char *buf);
void	infinite_input(int flag);
int		file_size(char *file_name);
void	goinfre(char *ptr);
void	temp_buf_init(char buf[17], char **temp_buf);
void	print_addr_and_hex(char buf[17], int idx);
int		g_len;
int		g_flag;
int		g_star;
int		g_cnt;

#endif
