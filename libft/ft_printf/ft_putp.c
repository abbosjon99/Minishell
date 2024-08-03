/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeldiya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 21:49:28 by akeldiya          #+#    #+#             */
/*   Updated: 2024/03/19 21:49:37 by akeldiya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_printhex(int c)
{
	if (c < 10)
		ft_putch('0' + c);
	else
		ft_putch(c + 87);
	return (1);
}

static int	ft_putx(unsigned long c)
{
	int	len;

	len = 0;
	if (c / 16 != 0)
	{
		len += ft_putx(c / 16);
	}
	len += ft_printhex(c % 16);
	return (len);
}

int	ft_putp(void *ptr)
{
	int	len;

	if (!ptr)
	{
		ft_putst("(nil)");
		return (5);
	}
	len = 2;
	ft_putst("0x");
	len += ft_putx((unsigned long)ptr);
	return (len);
}
