/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spereyra <spereyra@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 12:39:15 by spereyra          #+#    #+#             */
/*   Updated: 2024/05/29 18:07:12 by apardo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_operator	check_operator(char c)
{
	if (c == '|')
		return (PIPE);
	else if (c == '>')
		return (GREAT);
	else if (c == '<')
		return (LESS);
	else
		return (0);
}

int	handle_quotes(int i, char *input, char quote)
{
	int	j;

	j = 0;
	if (input[i + j] == quote)
	{
		j++;
		while (input[i + j] && input[i + j] != quote)
			j++;
		j++;
	}
	return (j);
}

/** Extract a word from input and add this word to the token list **/
int	handle_word(int i, char *input, t_token **token_lst)
{
	int		j;
	char	*word;

	j = 0;
	word = 0;
	while (input[i + j] && !check_operator(input[i + j]) && \
			!ft_isspace(input[i + j]))
	{
		if (input[i + j] == '\'')
			j = j + handle_quotes(i + j, input, '\'');
		else if (input[i + j] == '\"')
			j = j + handle_quotes(i + j, input, '\"');
		else
			j++;
	}
	word = ft_substr(input, i, j);
	if (!add_token(word, 0, token_lst))
		return (-1);
	return (j);
}

int	handle_operator(char *input, int i, t_token **token_lst)
{
	t_operator	oper;

	oper = check_operator(input[i]);
	if (oper == GREAT && check_operator(input[i + 1]) == GREAT)
	{
		if (!add_token(NULL, GREAT_GREAT, token_lst))
			return (-1);
		return (2);
	}
	else if (oper == LESS && check_operator(input[i + 1]) == LESS)
	{
		if (!add_token(NULL, LESS_LESS, token_lst))
			return (-1);
		return (2);
	}
	else if (oper)
	{
		if (!add_token(NULL, oper, token_lst))
			return (-1);
		return (1);
	}
	else
		return (0);
}

int	tokenizer(t_shell *shell)
{
	int		i;
	int		j;
	int		input_len;

	i = 0;
	input_len = ft_strlen(shell->input);
	while (i < input_len)
	{
		j = 0;
		while (ft_isspace(shell->input[i]))
			i++;
		if (check_operator(shell->input[i]))
			j = handle_operator(shell->input, i, &shell->token_lst);
		else
			j = handle_word(i, shell->input, &shell->token_lst);
		if (j < 0)
			return (0);
		i = i + j;
	}
	return (1);
}
