/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeldiya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 14:53:53 by akeldiya          #+#    #+#             */
/*   Updated: 2024/03/02 14:53:55 by akeldiya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// #include <string.h>

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*ptr;

	ptr = s;
	while (n--)
		*ptr++ = 0;
}
/*
int main() {
    char buffer[11];

    // Fill buffer with 'A'
    memset(buffer, 'A', sizeof(buffer));

    // Print buffer
    printf("Buffer after memset: %s\n", buffer);
    
    ft_bzero(buffer, sizeof(buffer));

    printf("Buffer after bzero: %s\n", buffer);

    return 0;
}*/
