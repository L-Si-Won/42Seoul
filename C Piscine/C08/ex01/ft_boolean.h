/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_boolean.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siwonlee <tldnjs0821222@naver.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 14:50:26 by siwonlee          #+#    #+#             */
/*   Updated: 2023/01/23 10:50:36 by siwonlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_BOOLEAN_H
# define FT_BOOLEAN_H

# include <unistd.h>

typedef enum e_bool
{
	true = 1,
	false = 0,
}	t_bool;

# define EVEN(nbr) ((nbr) % (2) == (0))

# define EVEN_MSG "I have an even number of arguments.\n"
# define ODD_MSG "I have an odd number of arguments.\n"

# define SUCCESS 0
# define TRUE true
# define FALSE false

void	ft_putstr(char *str);
t_bool	ft_is_even(int nbr);

#endif
