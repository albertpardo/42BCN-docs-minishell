/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apardo-m <apardo-m@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 14:10:23 by apardo-m          #+#    #+#             */
/*   Updated: 2024/05/29 17:16:16 by apardo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "executor.h"

static void	inout_befor_exe(int fdin, t_pipe *pnode, int *next_pipe)
{
	if (fdin > 2)
	{
		dup2(fdin, STDIN_FILENO);
		close(fdin);
	}
	if (pnode->next != NULL)
	{
		dup2(next_pipe[PIPE1_STDOUT], STDOUT_FILENO);
		close(next_pipe[PIPE1_STDOUT]);
		close(next_pipe[PIPE0_STDIN]);
	}
}

static void	inout_aft_fork(int *fdin, int fdout, int next_fdin, t_pipe *pnode)
{
	if (*fdin > 2)
		close(*fdin);
	if (pnode-> next != NULL)
	{
		close(fdout);
		*fdin = next_fdin;
	}
}

static void	exec_cmd(int tmp_out, int fdout, t_pipe *pnod, t_shell *shell)
{
	int	bltnum;
	int	err;

	err = 0;
	if (tmp_out != -1)
	{
		dup2(fdout, STDOUT_FILENO);
		close(fdout);
	}
	bltnum = get_builtin(pnod->argv_exec[0]);
	if (bltnum != -1)
	{
		err = exec_builtin(bltnum, pnod->argv_exec, shell);
		exit (err);
	}
	if (pnod->comm_lst->word != NULL)
	{
		set_defaultsignals_fork();
		if (execve(pnod->path_and_cmd, pnod->argv_exec, shell->envp_exec) == -1)
			minish_perror_onetwoseven(pnod->argv_exec[0]);
	}
	exit (EXIT_FAILURE);
}

/*
 *	Comand can be part of PIPES
 */

pid_t	execute(t_execut *evars, t_pipe *pnode, t_shell *shell)
{
	pid_t	pid;

	pid = fork();
	if (pid == -1)
		error_exit(NO_NEW_FORK);
	if (!(evars->fdin < 0 && pnode->next == NULL))
	{
		if (pid == 0)
		{
			inout_befor_exe(evars->fdin, pnode, evars->next_pipe);
			exec_cmd(evars->tmp_out, evars->fdout, pnode, shell);
		}
		inout_aft_fork(&evars->fdin, evars->fdout, evars->next_fdin, pnode);
	}
	else if (pid == 0)
		exec_cmd(evars->tmp_out, evars->fdout, pnode, shell);
	return (pid);
}
