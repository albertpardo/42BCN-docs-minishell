/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor_execute_one_builtin.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apardo-m <apardo-m@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 16:57:10 by apardo-m          #+#    #+#             */
/*   Updated: 2024/05/30 15:10:13 by apardo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executor.h"

/*
int	execute_one_builtin(t_shell *sh)
{
	t_execut	execvars;
	int			err;
	int			bltnum;

	init_execvars(&execvars);
	err = setfileinfileout(sh->pipe_lst, &execvars, 0);
	if (err == 0)
		err = fdmanager(sh->pipe_lst, &execvars);
	if (err == 0)
	{
		if (execvars.fdin > 2)
		{
			dup2(execvars.fdin, STDIN_FILENO);
			close(execvars.fdin);
		}
		if (execvars.tmp_out != -1)
		{
			dup2(execvars.fdout, 1);
			close(execvars.fdout);
		}
		bltnum = get_builtin(sh->pipe_lst->argv_exec[0]);
		//printf("before execute_one_builtin->last exit = %d\n", sh->exit_st);
		err = exec_builtin(bltnum, sh->pipe_lst->argv_exec, &(sh->envp_exec));
		//printf("after execute_one_builtin->last exit = %d\n", sh->exit_st);
	}
	setsdtout(&execvars);
	return (err);
}
*/

/*
int	execute_one_builtin(t_shell *sh)
{
	t_execut	execvars;
	int			err;
	int			bltnum;

	init_execvars(&execvars);
	err = setfileinfileout(sh->pipe_lst, &execvars, 0);
	if (err == 0)
		err = fdmanager(sh->pipe_lst, &execvars);
	if (err == 0)
	{
		if (execvars.fdin > 2)
		{
			dup2(execvars.fdin, STDIN_FILENO);
			close(execvars.fdin);
		}
		if (execvars.tmp_out != -1)
		{
			dup2(execvars.fdout, STDOUT_FILENO);
			close(execvars.fdout);
		}
		bltnum = get_builtin(sh->pipe_lst->argv_exec[0]);
		err = exec_builtin(bltnum, sh->pipe_lst->argv_exec, sh);
	}
	setsdtout(&execvars);
	setsdtin(&execvars);
	return (err);
}
*/

static void	dup_close(int fd, int std_fileno)
{
	dup2(fd, std_fileno);
	close(fd);
}

int	execute_one_builtin(t_shell *sh)
{
	t_execut	execvars;
	int			err;
	int			bltnum;

	init_execvars(&execvars);
	err = setfileinfileout(sh->pipe_lst, &execvars, 0);
	if (err == 0)
		err = fdmanager(sh->pipe_lst, &execvars);
	if (err == 0)
	{
		if (execvars.fdin > 2)
			dup_close(execvars.fdin, STDIN_FILENO);
		if (execvars.tmp_out != -1)
			dup_close(execvars.fdout, STDOUT_FILENO);
		bltnum = get_builtin(sh->pipe_lst->argv_exec[0]);
		err = exec_builtin(bltnum, sh->pipe_lst->argv_exec, sh);
	}
	setsdtout(&execvars);
	setsdtin(&execvars);
	return (err);
}
