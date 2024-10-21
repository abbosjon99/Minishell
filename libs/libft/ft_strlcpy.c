/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeldiya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 14:43:59 by akeldiya          #+#    #+#             */
/*   Updated: 2024/03/02 14:44:17 by akeldiya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// #include <string.h>
// #include <stdio.h>

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	lenth;

	i = 0;
	lenth = 0;
	while (src[lenth])
		lenth++;
	if (size < 1)
		return (lenth);
	while (src[i] && i < size - 1)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (lenth);
}
/*
int main()
{
    char src[] = "Hello World";
    char dest[13] = "hi";
    size_t n = 11;
    size_t lenth = 0;
    
   lenth = ft_strlcpy(dest, src, n);
     printf("Copied '%s' into '%s', length %ld\n",
            src,
            dest,
            lenth
          );
    return (0);
}*/
