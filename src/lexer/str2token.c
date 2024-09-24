/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str2token.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeldiya <akeldiya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 15:25:44 by akeldiya          #+#    #+#             */
/*   Updated: 2024/09/22 22:59:54 by akeldiya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

// strdup fail should be adressed!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
static bool	ft_splitfnorm(size_t size, size_t len, char *str, t_token **tk)
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
		tk[j]->str = ft_strdup(str + i++);
		if (!tk[j]->str)
			return (false);
		j++;
		while (i < len)
		{
			if (!(str[i - 1]) && str[i])
				break ;
			i++;
		}
	}
	return (true);
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

static bool	split_token(t_data *data)
{
	size_t	size;
	size_t	len;
	char	*str;

	if (!data->live_input)
		return (false);
	str = ft_strdup(data->live_input);
	if (!str)
		return (false);
	len = ft_strlen(data->live_input);
	size = ft_strcountnull(str, len);
	data->tokens = (t_token **)malloc(sizeof(t_token *) * (size + 1));
	if (!data->tokens)
	{
		free(str);
		return (false);
	}
	if (!ft_splitfnorm(size, len, str, data->tokens))
	{
		free(str);
		return (false);
	}
	free(str);
	data->tokens[size]->str = NULL;
	return (true);
}

bool	str2token(t_data *data)
{
	int	i;

	i = 0;
	if (!split_token(data))
		return (false);
	while (data->tokens[i]->str)
	{
		printf("%s\n", data->tokens[i]->str);
		i++;
	}
	return (true);
}
