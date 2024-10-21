/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeldiya <akeldiya@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 14:56:14 by akeldiya          #+#    #+#             */
/*   Updated: 2024/03/07 02:00:42 by akeldiya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <string.h>

char	*ft_strrchr(const char *s, int c)
{
	size_t	len;

	len = 0;
	while (s[len])
		len++;
	while (len)
	{
		if (s[len] == (char)c)
			return ((char *)&s[len]);
		len--;
	}
	if (s[len] == (char)c)
		return ((char *)&s[len]);
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
