/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeldiya <akeldiya@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 14:53:20 by akeldiya          #+#    #+#             */
/*   Updated: 2024/03/07 01:57:39 by akeldiya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <string.h>

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if (*s == (char)c)
		return ((char *)s);
	return (NULL);
}
/*
int	main(int argc, char **argv)
{
	if (argc == 3)
	{
		if (ft_strchr(argv[1], argv[2][0]) != NULL)
	    	printf("%s\n", ft_strchr(argv[1], argv[2][0]));
		else
			printf("Hellllo");
	}
}*/
