/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeldiya <akeldiya@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 14:53:09 by akeldiya          #+#    #+#             */
/*   Updated: 2024/03/06 23:31:15 by akeldiya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <string.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	int		diff;
	size_t	i;

	i = 0;
	diff = 0;
	while ((s1[i] != '\0' && s2[i] != '\0') && i < n)
	{
		if (s1[i] != s2[i])
		{
			diff = (unsigned char)s1[i] - (unsigned char)s2[i];
			return (diff);
		}
		i++;
	}
	if (i < n)
		diff = (unsigned char)s1[i] - (unsigned char)s2[i];
	return (diff);
}
/*
int	main(int argc, char **argv)
{
	if (argc == 4)
	{
		printf("%d\n", strncmp(argv[1], argv[2], atoi(argv[3])));
	    printf("%d\n", ft_strncmp(argv[1], argv[2], atoi(argv[3])));
	}
}*/
