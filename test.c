/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeldiya <akeldiya@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 11:11:19 by akeldiya          #+#    #+#             */
/*   Updated: 2024/09/07 11:13:30 by akeldiya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <readline/readline.h>  // Add this for readline
#include <readline/history.h>   // Add this for history functions

typedef struct s_token
{
	char			*value;
	struct s_token	*next;
}					t_token;

t_token	*new_token(char *value)
{
	t_token	*token;

	token = malloc(sizeof(t_token));
	token->value = strdup(value);
	token->next = NULL;
	return (token);
}

void	add_token(t_token **tokens, char *value)
{
	t_token	*new;
	t_token	*tmp;

	new = new_token(value);
	if (*tokens == NULL)
	{
		*tokens = new;
	}
	else
	{
		tmp = *tokens;
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = new;
	}
}

char	*get_next_token(char **input)
{
	char	*start;

	start = *input;
	while (**input && !isspace(**input) && !strchr("|><", **input))
		(*input)++;
	return (strndup(start, *input - start));
}

t_token	*lexer(char *input)
{
	t_token	*tokens;
	char	*token;

	tokens = NULL;
	while (*input)
	{
		while (isspace(*input)) // Skip whitespace
			input++;
		if (*input == '\0')
			break ;
		token = NULL;
		// Handle special characters (|, >, <, >>, <<)
		if (*input == '|' || *input == '<' || *input == '>')
		{
			if (*input == '>' && *(input + 1) == '>')
			{
				add_token(&tokens, ">>");
				input += 2;
			}
			else if (*input == '<' && *(input + 1) == '<')
			{
				add_token(&tokens, "<<");
				input += 2;
			}
			else
			{
				token = strndup(input, 1);
				add_token(&tokens, token);
				input++;
			}
		}
		else
		{
			token = get_next_token(&input);
			add_token(&tokens, token);
		}
	}
	return (tokens);
}

void	print_tokens(t_token *tokens)
{
	while (tokens)
	{
		printf("Token: %s\n", tokens->value);
		tokens = tokens->next;
	}
}

int	main(void)
{
	char	*input;
	t_token	*tokens;

	input = readline("minishell$ ");
	tokens = lexer(input);
	print_tokens(tokens);
	free(input);
	return (0);
}
