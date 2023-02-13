/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siwonlee <tldnjs0821222@naver.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 15:24:42 by siwonlee          #+#    #+#             */
/*   Updated: 2023/01/26 10:32:19 by siwonlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	add(int a, int b);
int	sub(int a, int b);
int	mul(int a, int b);
int	div(int a, int b);
int	mod(int a, int b);
void	ft_putnbr(long long nb);
int	ft_atoi(char *str);

void	fun_init(int (*f[5])(int, int))
{
	f[0] = add;
	f[1] = sub;
	f[2] = mul;
	f[3] = div;
	f[4] = mod;
}

int	calculator(int a, int b, char op, int (*f[5])(int, int))
{
	int	result;

	result = 0;
	if (op == '+')
		result = f[0](a, b);
	if (op == '-')
		result = f[1](a, b);
	if (op == '*')
		result = f[2](a, b);
	if (op == '/')
		result = f[3](a, b);
	if (op == '%')
		result = f[4](a, b);
	return (result);
}

void	do_op(int a, int b, char op, int (*f[5])(int, int))
{
	int	result;

	if (b == 0 && op == '/')
	{
		write(1, "Stop : division by zero\n", 24);
		return ;
	}
	else if (b == 0 && op == '%')
	{
		write(1, "Stop : modulo by zero\n", 22);
		return ;
	}
	result = calculator(a, b, op, f);
	ft_putnbr(result);
}

int	main(int argc, char *argv[])
{
	int		a;
	int		b;
	int		(*f[5])(int, int);
	char	op;

	if (argc == 4)
	{
		if ((argv[2][0] == '+' || argv[2][0] == '-' || argv[2][0] == '*'
			|| argv[2][0] == '/' || argv[2][0] == '%') && argv[2][1] == '\0')
		{
			fun_init(f);
			a = ft_atoi(argv[1]);
			b = ft_atoi(argv[3]);
			op = argv[2][0];
			do_op(a, b, op, f);
		}
		else
			write(1, "0\n", 2);
	}
	return (0);
}
