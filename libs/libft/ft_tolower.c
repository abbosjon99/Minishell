/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeldiya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 14:53:40 by akeldiya          #+#    #+#             */
/*   Updated: 2024/03/02 14:53:42 by akeldiya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>
// #include <ctype.h>

int	ft_tolower(int c)
{
	if (c > 64 && c < 91)
	{
		return (c + 32);
	}
	return (c);
}
/*
int	main()
{
	printf("%c\n", ft_tolower('A'));
	printf("%c", tolower('A'));
}*/
