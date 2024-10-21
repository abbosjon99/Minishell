/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putxx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeldiya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 21:50:11 by akeldiya          #+#    #+#             */
/*   Updated: 2024/03/19 21:50:13 by akeldiya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_printhex(int c, char xx)
{
	if (c < 10)
		ft_putch('0' + c);
	else if (xx == 'x')
		ft_putch(c + 87);
	else
		ft_putch(c + 55);
	return (1);
}

int	ft_putxx(unsigned int c, char xx)
{
	int	len;

	len = 0;
	if (c / 16 != 0)
	{
		len += ft_putxx(c / 16, xx);
	}
	len += ft_printhex(c % 16, xx);
	return (len);
}
