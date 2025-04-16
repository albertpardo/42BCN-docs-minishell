/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_operators.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spereyra <spereyra@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 20:20:33 by spereyra          #+#    #+#             */
/*   Updated: 2024/05/29 09:02:08 by spereyra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	error_tokenlst_pipe(t_shell *shell)
{
	ft_putendl_fd("minishell: syntax error near unexpected token `|\'", \
			STDERR_FILENO);
	shell->exit_st = 258;
	return (0);
}

static int	error_tokenlst_nl(t_shell *shell)
{
	ft_putendl_fd("minishell: syntax error near unexpected token `newline\'", \
			STDERR_FILENO);
	shell->exit_st = 258;
	return (0);
}

static int	error_tokenlst_oper(t_shell *shell, t_operator oper)
{
	if (oper == GREAT)
		ft_putendl_fd("minishell: syntax error near unexpected token `>\'", \
				STDERR_FILENO);
	else if (oper == GREAT_GREAT)
		ft_putendl_fd("minishell: syntax error near unexpected token `>>\'", \
				STDERR_FILENO);
	else if (oper == LESS)
		ft_putendl_fd("minishell: syntax error near unexpected token `<\'", \
				STDERR_FILENO);
	else if (oper == LESS_LESS)
		ft_putendl_fd("minishell: syntax error near unexpected token `<<\'", \
				STDERR_FILENO);
	shell->exit_st = 258;
	return (0);
}

/*** If OK returns 1, if error returns 0 and set shell->exit_st=258  ***/
int	check_tokenlst_operators(t_shell *shell)
{
	t_token	*cur_token;

	cur_token = 0;
	cur_token = shell->token_lst;
	if (cur_token && cur_token->oper == PIPE)
		return (error_tokenlst_pipe(shell));
	while (cur_token)
	{
		if (cur_token->next == 0 && cur_token->oper >= PIPE)
			return (error_tokenlst_nl(shell));
		if (cur_token->next && cur_token->next->oper == PIPE && cur_token->oper)
			return (error_tokenlst_pipe(shell));
		if (cur_token->next && cur_token->next->oper > PIPE \
				&& cur_token->oper > PIPE)
			return (error_tokenlst_oper(shell, cur_token->next->oper));
		cur_token = cur_token->next;
	}
	return (1);
}
