/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeldiya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 17:00:51 by akeldiya          #+#    #+#             */
/*   Updated: 2024/02/27 17:00:53 by akeldiya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>
// #include <stdlib.h>
// #include <ctype.h>

int	ft_isprint(int c)
{
	if (c < 32 || c > 126)
	{
		return (0);
	}
	return (1);
}
/*
int	main(int argc, char **argv)
{
	if (argc == 2)
	{
	    printf("%d\n", ft_isprint(atoi(argv[1])));
		printf("%d\n", ft_isprint(atoi(argv[1])));
	}
}*/
