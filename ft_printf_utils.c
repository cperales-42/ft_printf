/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cperales <cperales@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 13:31:28 by cperales          #+#    #+#             */
/*   Updated: 2024/12/11 13:31:31 by cperales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
// • %s Imprime una string (como se define por defecto en C).

void	ft_putstr_pf(char *str, int *counter)
{
	if (!str)
		str = ("(null)");
	while (*str)
		ft_putchar_pf(*str++, counter);
}

// • %d Imprime un número decimal (base 10).
// • %i Imprime un entero en base 10.

void	ft_putnbr_pf(int n, int *counter)
{
	if (n < 0)
	{
		ft_putchar_pf('-', counter);
		if (n == -2147483648)
		{
			ft_putchar_pf('2', counter);
			n = -147483648;
		}
		n = -n;
	}
	if (n >= 10)
		ft_putnbr_pf(n / 10, counter);
	ft_putchar_pf((n % 10) + '0', counter);
}

// • %u Imprime un número decimal (base 10) sin signo.

void	ft_putu_pf(unsigned int n, int *counter)
{
	if (n >= 10)
		ft_putu_pf(n / 10, counter);
	ft_putchar_pf((n % 10) + '0', counter);
}

// • %p El puntero void * dado como argumento se imprime en formato hexadecimal.

void	ft_putptr(void *ptr, int *counter)
{
	unsigned long	p;

	p = (unsigned long)ptr;
	if (!ptr)
		return (ft_putstr_pf(("(nil)"), counter));
	ft_putstr_pf("0x", counter);
	ft_puthex_pf(p, counter, 'x');
}

// • %x Imprime un número hexadecimal (base 16) en minúsculas.
// • %X Imprime un número hexadecimal (base 16) en mayúsculas.

/*void	ft_puthex_pf(unsigned long n, int *counter, const char base)
{
	char	*bs;

	bs = "0123456789abcdef";
	if (base == 'X')
		bs = "0123456789ABCDEF";
	if (n < 0)
	{
		ft_putchar_pf('-', counter);
		n *= (-1);
	}
	while (n >= 16)
	{	
		ft_putchar_pf(bs[n % 16], counter);
		n /= 16;
	}
	ft_putchar_pf(bs[n], counter);
}*/

void	ft_puthex_pf(unsigned long n, int *counter, const char format)
{
	char	*bs;

	if (format == 'X')
		bs = "0123456789ABCDEF";
	else
		bs = "0123456789abcdef";
	if (n == 0)
	{
		ft_putchar_pf('0', counter);
		return ;
	}
	if (n >= 16)
		ft_puthex_pf(n / 16, counter, format);
	ft_putchar_pf(bs[n % 16], counter);
}
