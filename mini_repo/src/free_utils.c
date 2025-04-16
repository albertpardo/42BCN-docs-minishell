/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spereyra <spereyra@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 16:47:41 by spereyra          #+#    #+#             */
/*   Updated: 2024/05/07 12:24:23 by spereyra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_shell(t_shell *shell)
{
	if (shell->input)
		free(shell->input);
	free_tokenlst(&shell->token_lst);
	free_pipelst(&shell->pipe_lst);
}

void	free_matrix(char **matrix)
{
	int	i;

	i = 0;
	if (!matrix)
		return ;
	while (matrix[i])
	{
		free(matrix[i]);
		i++;
	}
	free(matrix);
}

void	free_tokenlst(t_token **token_lst)
{
	t_token	*tmp;

	tmp = 0;
	while (token_lst && *token_lst)
	{
		tmp = (*token_lst)->next;
		if ((*token_lst)->word != 0)
			free ((*token_lst)->word);
		free(*token_lst);
		*token_lst = tmp;
	}
}

void	free_pipelst(t_pipe **pipe_lst)
{
	t_pipe	*tmp;

	tmp = 0;
	while (pipe_lst && *pipe_lst)
	{
		tmp = (*pipe_lst)->next;
		free_matrix((*pipe_lst)->argv_exec);
		free((*pipe_lst)->path_and_cmd);
		free_tokenlst(&(*pipe_lst)->comm_lst);
		free_tokenlst(&(*pipe_lst)->in_lst);
		free_tokenlst(&(*pipe_lst)->out_lst);
		free(*pipe_lst);
		*pipe_lst = tmp;
	}
}
