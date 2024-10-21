/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeldiya <akeldiya@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 02:20:49 by akeldiya          #+#    #+#             */
/*   Updated: 2024/03/02 14:56:48 by akeldiya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned int		i;
	unsigned char		*ptr_dest;
	const unsigned char	*ptr_src;

	i = 0;
	if (!src && !dest)
		return (NULL);
	ptr_dest = dest;
	ptr_src = src;
	if (src < dest)
	{
		while (n-- > 0)
		{
			ptr_dest[n] = ptr_src[n];
		}
	}
	else
	{
		while (i < n)
		{
			ptr_dest[i] = ptr_src[i];
			i++;
		}
	}
	return (dest);
}
