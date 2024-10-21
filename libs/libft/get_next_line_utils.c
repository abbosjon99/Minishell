/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeldiya <akeldiya@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 18:40:33 by akeldiya          #+#    #+#             */
/*   Updated: 2024/05/13 10:57:16 by akeldiya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*gt_charshifter(char *s1, int shift)
{
	int	i;

	i = 0;
	while (s1[i + shift])
	{
		s1[i] = s1[i + shift];
		i++;
	}
	s1[i] = '\0';
	return (s1);
}

char	*gt_strjoin(char **s1, char const *s2, int len2)
{
	size_t	i;
	int		j;
	char	*nxtline;

	j = 0;
	if (*s1)
		j = gt_strlen(*s1);
	nxtline = (char *)malloc(j + len2 + 1);
	if (!nxtline)
		return (NULL);
	i = 0;
	while (*s1 && (*s1)[i])
	{
		nxtline[i] = (*s1)[i];
		i++;
	}
	j = 0;
	while (j < len2)
	{
		nxtline[i + j] = s2[j];
		j++;
	}
	nxtline[i + j] = '\0';
	free(*s1);
	return (nxtline);
}

int	gt_strnlen(char const *s)
{
	int	size;

	size = 0;
	while (s[size] != '\0')
	{
		if (s[size] == '\n')
			return (size + 1);
		size++;
	}
	return (size);
}

size_t	gt_strlen(char const *s)
{
	size_t	size;

	size = 0;
	while (s[size] != '\0')
		size++;
	return (size);
}

char	*gt_strdup(char const *s)
{
	size_t	size;
	size_t	i;
	char	*newstr;

	if (!s)
		return (NULL);
	i = 0;
	size = gt_strlen(s);
	newstr = malloc(size + 1);
	if (!newstr)
		return (NULL);
	while (i < size)
	{
		newstr[i] = s[i];
		i++;
	}
	newstr[i] = '\0';
	return (newstr);
}
