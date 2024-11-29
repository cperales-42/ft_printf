/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diurno <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 10:15:58 by diurno            #+#    #+#             */
/*   Updated: 2024/11/29 10:41:23 by diurno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

# define HEX_UPP_BASE "0123456789ABCDEF"
# define HEX_LOW_BASE "0123456789abcdef"

int		ft_printf(char const *str, ...);

/* format functions */
void	ft_putchar_pf(char c);
void	ft_putstr_pf(char *str);
void	ft_putnbr_pf(int num);
void	ft_putuint_pf(unsigned int num, size_t *counter);
void	ft_puthex_pf(unsigned int num, size_t *counter, char *base);
void	ft_putptr_pf(void *ptr, size_t *counter);

/* auxiliary functions */
char	*ft_aux_pf(unsigned long long n, char *base);

#endif
