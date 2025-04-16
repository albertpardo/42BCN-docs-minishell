/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spereyra <spereyra@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 12:31:12 by spereyra          #+#    #+#             */
/*   Updated: 2024/04/10 13:39:51 by spereyra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	count_pipes(t_token *token_lst)
{
	int	pipes;

	pipes = 0;
	while (token_lst)
	{
		if (token_lst->oper == PIPE)
			pipes++;
		token_lst = token_lst->next;
	}
	return (pipes);
}

t_pipe	*newpipe(int index)
{
	t_pipe	*new_pipe;

	new_pipe = malloc(sizeof(t_pipe));
	if (!new_pipe)
		return (0);
	new_pipe->i_pipe = index;
	new_pipe->argv_exec = 0;
	new_pipe->path_and_cmd = 0;
	new_pipe->comm_lst = 0;
	new_pipe->in_lst = 0;
	new_pipe->out_lst = 0;
	new_pipe->next = 0;
	return (new_pipe);
}

t_pipe	*pipelst_last(t_pipe *pipe_lst)
{
	while (pipe_lst != 0)
	{
		if (pipe_lst->next == 0)
			return (pipe_lst);
		else
			pipe_lst = pipe_lst->next;
	}
	return (pipe_lst);
}

void	pipelst_addback(t_pipe **pipe_lst, t_pipe *new_pipe)
{
	if (pipe_lst && new_pipe)
	{
		if (*pipe_lst != 0)
			pipelst_last(*pipe_lst)->next = new_pipe;
		else
			*pipe_lst = new_pipe;
	}
}

void	tokenlst_addback(t_token **token_lst, t_token *new_token)
{
	t_token	*head;

	head = *token_lst;
	if (*token_lst == NULL)
	{
		*token_lst = new_token;
		return ;
	}
	while (head->next != NULL)
		head = head->next;
	head->next = new_token;
}
