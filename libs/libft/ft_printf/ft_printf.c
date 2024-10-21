/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeldiya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 23:28:00 by akeldiya          #+#    #+#             */
/*   Updated: 2024/03/15 23:28:02 by akeldiya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

static int	ft_helper(va_list args, const char *str)
{
	int	len;

	len = 0;
	if (*str == 'c')
		len += ft_putch(va_arg(args, int));
	else if (*str == '%')
		len += ft_putch('%');
	else if (*str == 's')
		len += ft_putst(va_arg(args, char *));
	else if (*str == 'p')
		len += ft_putp(va_arg(args, void *));
	else if (*str == 'd')
		len += ft_putdi(va_arg(args, int));
	else if (*str == 'i')
		len += ft_putdi(va_arg(args, int));
	else if (*str == 'u')
		len += ft_putu(va_arg(args, unsigned int));
	else if (*str == 'x')
		len += ft_putxx(va_arg(args, unsigned int), 'x');
	else if (*str == 'X')
		len += ft_putxx(va_arg(args, unsigned int), 'X');
	return (len);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		len;

	len = 0;
	va_start(args, str);
	while (*str)
	{
		if (*str != '%')
			len += ft_putch(*str);
		else
		{
			str++;
			len += ft_helper(args, str);
		}
		str++;
	}
	va_end(args);
	return (len);
}
