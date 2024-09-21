/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cmdsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeldiya <akeldiya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 15:25:44 by akeldiya          #+#    #+#             */
/*   Updated: 2024/09/21 19:33:26 by akeldiya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

static char	**ft_splitfnorm(size_t size, size_t len, char *str, char **r)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (i < len)
	{
		if (str[i])
			break ;
		i++;
	}
	while (size--)
	{
		r[j] = ft_strdup(str + i++);
		if (!(r[j]))
			return (NULL);
		j++;
		while (i < len)
		{
			if (!(str[i - 1]) && str[i])
				break ;
			i++;
		}
	}
	return (r);
}

static size_t	ft_strcountnull(char *str, size_t len)
{
	size_t	size;
	size_t	i;

	i = 0;
	size = 0;
	while (i < len)
	{
		if (str[i] == '"')
		{
			while (str[i] && str[i] != '"')
				i++;
		}
		if (str[i] == '\'')
		{
			while (str[i] && str[i] != '\'')
				i++;
		}
		if (str[i] != ' ')
		{
			if (str[i + 1] == ' ' || !str[i + 1])
				size++;
		}
		else
			str[i] = '\0';
		i++;
	}
	return (size);
}

char	**cmd_split(char const *s)
{
	size_t	size;
	size_t	len;
	char	*str;
	char	**result;

	if (!s)
		return (NULL);
	str = ft_strdup(s);
	if (!str)
		return (NULL);
	len = ft_strlen(str);
	size = ft_strcountnull(str, len);
	result = (char **)malloc(sizeof(char *) * (size + 1));
	if (!result)
		return (NULL);
	result = ft_splitfnorm(size, len, str, result);
	free(str);
	result[size] = NULL;
	return (result);
}
