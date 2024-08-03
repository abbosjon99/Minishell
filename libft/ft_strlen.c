/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeldiya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 14:42:38 by akeldiya          #+#    #+#             */
/*   Updated: 2024/03/02 14:43:46 by akeldiya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// #include <string.h>

size_t	ft_strlen(const char *s)
{
	size_t	size;

	size = 0;
	while (s[size])
		size++;
	return (size);
}
/*
int	main(int argc, char **argv)
{
	if (argc == 2)
	{
	    printf("%ld\n", ft_strlen(argv[1]));
		printf("%ld", strlen(argv[1]));
	}
}*/
