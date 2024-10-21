/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeldiya <akeldiya@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 16:20:19 by akeldiya          #+#    #+#             */
/*   Updated: 2024/03/06 20:09:49 by akeldiya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	char	*ptr;

	if (!s1 || !set)
		return (NULL);
	end = ft_strlen(s1) - 1;
	start = 0;
	while (ft_strchr(set, s1[start]) && start <= end)
		start++;
	while (ft_strchr(set, s1[end]) && start < end)
		end--;
	if (start > end)
		return (ft_substr("", 0, 0));
	ptr = ft_substr(s1, start, end - start + 1);
	if (!ptr)
		return (NULL);
	return (ptr);
}
/*
int	main(int argc, char **argv)
{
	if (argc == 3)
		printf("%s\n", (char *)ft_strtrim(argv[1], argv[2]));
	return (0);
}*/
