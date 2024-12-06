/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_pf.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cperales <cperales@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 19:07:27 by cperales          #+#    #+#             */
/*   Updated: 2024/12/06 19:07:29 by cperales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
// • %c Imprime un solo carácter.
// • % % para imprimir el símbolo del porcentaje.

void	ft_putchar_pf(char c, int *counter)
{
	write(1, &c, 1);
	(*counter)++;
}
