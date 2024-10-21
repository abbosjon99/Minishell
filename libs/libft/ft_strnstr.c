/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeldiya <akeldiya@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 14:44:51 by akeldiya          #+#    #+#             */
/*   Updated: 2024/03/07 00:41:02 by akeldiya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <string.h>

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;

	if (!little[0])
		return ((char *)big);
	while ((len && *big))
	{
		if (*big == *little)
		{
			i = 0;
			while (little[i] && i < len)
			{
				if (big[i] != little[i])
					break ;
				i++;
			}
			if (!little[i])
				return ((char *)big);
		}
		big++;
		len--;
	}
	return (NULL);
}
/*
int main () {
    const char	*largestring = "Foo Bar	Baz";
    const char	*smallstring = "z";
    char *ptr;

    ptr = ft_strnstr(largestring,	smallstring, 5);
    printf("%s", ptr);
    return(0);
}*/
