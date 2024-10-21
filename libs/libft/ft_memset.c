/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   -ft_memset.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeldiya <akeldiya@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 02:19:51 by akeldiya          #+#    #+#             */
/*   Updated: 2024/03/02 02:20:02 by akeldiya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// #include <string.h>

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*ptr;

	ptr = s;
	while (n--)
	{
		*ptr = (unsigned char)c;
		ptr++;
	}
	return (s);
}
/*
int	main(void) {
	char buffer[1];

	// Fill buffer with 'A'
	ft_memset(buffer, 'A', sizeof(buffer));

	// Print buffer
	printf("Buffer after memset: %s\n", buffer);

	return (0);
}*/
