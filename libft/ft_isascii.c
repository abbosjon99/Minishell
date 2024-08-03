/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeldiya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 16:52:15 by akeldiya          #+#    #+#             */
/*   Updated: 2024/02/27 16:52:17 by akeldiya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>
// #include <stdlib.h>
// #include <ctype.h>

int	ft_isascii(int c)
{
	if (c >= 0 && c < 128)
	{
		return (1);
	}
	return (0);
}
/*
int	main(int argc, char **argv)
{
	if (argc == 2)
	{
	    printf("%d\n", ft_isascii(atoi(argv[1])));
		printf("%d", isascii(atoi(argv[1])));
	}
}*/
