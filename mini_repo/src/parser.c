/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spereyra <spereyra@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 19:32:41 by spereyra          #+#    #+#             */
/*   Updated: 2024/05/29 15:09:08 by apardo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	set_pipe_commlst(t_pipe *pipe_lst, t_token **token_lst)
{
	tokenlst_addback(&pipe_lst->comm_lst, *token_lst);
	if ((*token_lst)->next != 0)
	{
		*token_lst = (*token_lst)->next;
		(*token_lst)->prev->next = 0;
		(*token_lst)->prev = 0;
	}
	else
		*token_lst = 0;
}

void	set_pipe_outlst(t_pipe *pipe_lst, t_token **token_lst)
{
	tokenlst_addback(&pipe_lst->out_lst, *token_lst);
	if ((*token_lst)->next->next != 0)
	{
		*token_lst = (*token_lst)->next->next;
		(*token_lst)->prev->next = 0;
		(*token_lst)->prev = 0;
	}
	else
		*token_lst = 0;
}

void	set_pipe_inlst(t_pipe *pipe_lst, t_token **token_lst)
{
	tokenlst_addback(&pipe_lst->in_lst, *token_lst);
	if ((*token_lst)->next->next != 0)
	{
		*token_lst = (*token_lst)->next->next;
		(*token_lst)->prev->next = 0;
		(*token_lst)->prev = 0;
	}
	else
		*token_lst = 0;
}

void	set_pipe(t_pipe *pipe_lst, int cur_pipe, t_token **token_lst)
{
	while (pipe_lst->i_pipe != cur_pipe)
		pipe_lst = pipe_lst->next;
	if ((*token_lst)->word != 0)
		set_pipe_commlst(pipe_lst, token_lst);
	else if ((*token_lst)->oper == PIPE)
	{
		*token_lst = (*token_lst)->next;
		free((*token_lst)->prev);
		(*token_lst)->prev = 0;
	}
	else if ((*token_lst)->oper == GREAT || (*token_lst)->oper == GREAT_GREAT)
		set_pipe_outlst(pipe_lst, token_lst);
	else if ((*token_lst)->oper == LESS || (*token_lst)->oper == LESS_LESS)
		set_pipe_inlst(pipe_lst, token_lst);
}

int	parser(t_shell *shell)
{
	t_pipe	*new_pipe;
	int		i;
	int		cur_pipe;

	expander(shell);
	clean_quotes(shell);
	shell->pipes = count_pipes(shell->token_lst) + 1;
	new_pipe = 0;
	i = 0;
	while (shell->input[0] && i < shell->pipes)
	{
		new_pipe = newpipe(i);
		if (!new_pipe)
			return (0);
		pipelst_addback(&shell->pipe_lst, new_pipe);
		i++;
	}
	cur_pipe = 0;
	while (shell->pipe_lst && shell->token_lst)
	{
		if (shell->token_lst->oper == PIPE)
			cur_pipe++;
		set_pipe(shell->pipe_lst, cur_pipe, &shell->token_lst);
	}
	return (1);
}
