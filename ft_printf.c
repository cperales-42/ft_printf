/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diurno <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 09:45:31 by diurno            #+#    #+#             */
/*   Updated: 2024/11/29 10:42:02 by diurno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
int	ft_printf(char const* fmt, ...)
{
	va_list args;
	va_start(args, fmt);
	size_t	i;

	i = 0;
	while (fmt[i])
	{
		if (fmt[i] == '%')
		{
			if (fmt[i + 1] == 'c')
				ft_putchar_pf(va_arg(args, int));
			else if (fmt[i + 1] == 's')
				ft_putstr_pf(va_arg(args, char *));
			else if (fmt[i + 1] == 'i')
				ft_putnbr_pf(va_arg(args, char *));
			i++;
		}
		else
			write(1, &fmt[i], 1);
		i++;	
	}
	va_end(args);
}

int main(int argc, char** argv)
{
	if (argc > 0)
	{
		ft_printf("Se escribira un string que metas mira: %s\n", argv[1]);
	}
}
