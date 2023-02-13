/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_h.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siwonlee <tldnjs0821222@naver.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 20:03:18 by siwonlee          #+#    #+#             */
/*   Updated: 2023/01/27 20:23:19 by siwonlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_H_H
# define FT_H_H

# include <unistd.h>
# include <string.h>
# include <libgen.h>
# include <fcntl.h>
# include <errno.h>

void	ft_putstr(char *str);
int		ft_atoi(char *str);
int		exception(int argc, char *argv[]);
void	no_file_print(char *argv[], int errnum, int idx);
void	content_print(char *file_name, int fd, int byte_size);
void	file_print(int argc, char *argv[], int idx, int fd);
int		byte_check(char *byte);
void	infinite_input(int argc, char *argv[], int idx, int cur);
int		exception(int argc, char *argv[]);
static int	g_flag;

#endif
