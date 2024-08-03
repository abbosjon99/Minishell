/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeldiya <akeldiya@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 01:47:55 by akeldiya          #+#    #+#             */
/*   Updated: 2024/03/02 02:03:23 by akeldiya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <stdlib.h>

char	*ft_strdup(const char *s)
{
	size_t	size;
	char	*newstr;

	size = ft_strlen(s);
	newstr = (char *)malloc(sizeof(char) * (size + 1));
	if (!newstr)
		return (NULL);
	newstr[size] = '\0';
	while (size-- > 0)
	{
		newstr[size] = s[size];
	}
	return (newstr);
}
/*
int	main(int argc, char **argv)
{
	if (argc == 2)
		printf("%s\n", strdup(argv[1]));
}*/
