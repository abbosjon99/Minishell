/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeldiya <akeldiya@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 23:28:05 by akeldiya          #+#    #+#             */
/*   Updated: 2024/05/02 19:21:08 by akeldiya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int	ft_putch(char c);
int	ft_putst(char *str);
int	ft_putdi(int n);
int	ft_putu(unsigned int n);
int	ft_putxx(unsigned int c, char xx);
int	ft_putp(void *ptr);
int	ft_printf(const char *str, ...);

#endif
