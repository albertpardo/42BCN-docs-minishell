/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spereyra <spereyra@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 13:22:39 by spereyra          #+#    #+#             */
/*   Updated: 2024/05/29 14:05:05 by apardo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	set_executor(t_shell *shell)
{
	t_pipe	*cur_pipe;

	cur_pipe = shell->pipe_lst;
	while (cur_pipe)
	{
		cur_pipe->argv_exec = tokenlst_to_matrix(cur_pipe->comm_lst);
		cur_pipe = cur_pipe->next;
	}
}

static int	quotes_counter(char *str)
{
	int	i;
	int	counter;

	i = 0;
	counter = 0;
	while (str[i])
	{
		if (str[i] == '\'' || str[i] == '\"')
			counter++;
		i++;
	}
	return (counter);
}

void	clean_quotes(t_shell *shell)
{
	char	*new_word;
	t_token	*cur_token;

	cur_token = shell->token_lst;
	while (cur_token != NULL)
	{
		if (cur_token->word != 0 && quotes_counter(cur_token->word) > 0)
		{
			new_word = strdup_unquoted(cur_token->word);
			free(cur_token->word);
			cur_token->word = new_word;
		}
		cur_token = cur_token->next;
	}
}
