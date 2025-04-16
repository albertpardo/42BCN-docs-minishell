/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor_minish.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apardo-m <apardo-m@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 13:36:56 by apardo-m          #+#    #+#             */
/*   Updated: 2024/05/29 12:56:47 by apardo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executor.h"

/*
 *	Execute all pipes
 *	for each pipe , if there are filein OR fileout configure fd for the pipe
 *	when all pipes are finished, screen as STDOUT is set.
 */

static void	init_executorvars(int *i, int *pid, int *err, t_execut *execvars)
{
	init_execvars(execvars);
	*i = 0;
	*pid = 0;
	*err = 0;
}

/*
static pid_t	executor(t_pipe *one_pipe, int num_pipes, t_shell *shell)
{
	int			i;
	pid_t		pid;
	int			err;
	t_execut	execvars;

	init_executorvars(&i, &pid, &err, &execvars);
	stop_signals();//mirar si lo he activado antes
	while (err == 0 && one_pipe != NULL)
	{
		err = setfileinfileout(one_pipe, &execvars, i++);
		if (err == 0)
			err = fdmanager(one_pipe, &execvars);
		if (err == 0)
		{
			if (one_pipe->argv_exec[0] != NULL)
				pid = execute(&execvars, one_pipe, shell);
			set_execvars_tonextstep(&execvars);
			one_pipe = one_pipe->next;
		}
	}
	if (err == 0 && pid > 0)
		err = getlastforkexitvalue(num_pipes, pid);
	setsdtout(&execvars);
	setsdtin(&execvars);
	return (err);
}
*/

/* 
 * El error en 'setfileinfileout(...)' no para el bucle de pipes
 */

/*
static pid_t	executor(t_pipe *one_pipe, int num_pipes, t_shell *shell)
{
	int			i;
	pid_t		pid;
	int			err;
	t_execut	execvars;

	init_executorvars(&i, &pid, &err, &execvars);
	stop_signals();//mirar si lo he activado antes
	while (err == 0 && one_pipe != NULL)
	{
		if (setfileinfileout(one_pipe, &execvars, i++) == 0)
		{
			err = fdmanager(one_pipe, &execvars);
//			if (err == 0 && one_pipe->argv_exec[0] != NULL && \
//				one_pipe->argv_exec[0][0] != '\0')
			if (err == 0 && one_pipe->argv_exec[0] && one_pipe->argv_exec[0][0])
				pid = execute(&execvars, one_pipe, shell);
		}
		if (err == 0)
		{
			set_execvars_tonextstep(&execvars);
			one_pipe = one_pipe->next;
		}
	}
	if (err == 0 && pid > 0)
		err = getlastforkexitvalue(num_pipes, pid);
	setsdtout(&execvars);
	setsdtin(&execvars);
	return (err);
}
*/

// START  get  path in each command in pipe

static int	execut_exec(pid_t *pid, t_pipe *opipe, t_execut *evar, t_shell *sh)
{
	int	err;

	err = fdmanager(opipe, evar);
	if (err == 0 && opipe->argv_exec[0] && opipe->argv_exec[0][0])
	{
		err = set_path_cmd(opipe, sh->envp_exec);
		if (err == 0)
			*pid = execute(evar, opipe, sh);
	}
	return (err);
}

static pid_t	executor(t_pipe *one_pipe, int num_pipes, t_shell *shell)
{
	int			i;
	pid_t		pid;
	int			err;
	t_execut	execvars;

	init_executorvars(&i, &pid, &err, &execvars);
	stop_signals();
	err = 0;
	while (one_pipe != NULL)
	{
		if (setfileinfileout(one_pipe, &execvars, i++) == 0)
			err = execut_exec(&pid, one_pipe, &execvars, shell);
		set_execvars_tonextstep(&execvars);
		one_pipe = one_pipe->next;
		if (one_pipe != NULL)
			err = 0;
	}
	if (err == 0 && pid > 0)
		err = getlastforkexitvalue(num_pipes, pid);
	setsdtout(&execvars);
	setsdtin(&execvars);
	return (err);
}
// END  get  path in each command in pipe

// START executor guardando pipes en array
/*
static pid_t *mem_pids(int num)
{
	pid_t *pids;

	pids = (pid_t *)malloc(sizeof(pid_t) * num);
	if (pids == NULL)
		error_exit(ERROR_MALLOC);
	return (pids);
}

static int	executor(t_pipe *one_pipe, int num_pipes, t_shell *shell)
{
	int			i;
	pid_t		pid;
	int			err;
	t_execut	execvars;
	pid_t		*pids;

	init_executorvars(&i, &pid, &err, &execvars);
	pids = mem_pids(num_pipes);
	stop_signals();
	while (err == 0 && one_pipe != NULL)
	{
		err = setfileinfileout(one_pipe, &execvars, i);
		if (err == 0)
			err = fdmanager(one_pipe, &execvars);
		if (err == 0)
		{
			if (one_pipe->argv_exec[0] != NULL)
				pids[i++]= execute(&execvars, one_pipe, shell);
			set_execvars_tonextstep(&execvars);
			one_pipe = one_pipe->next;
		}
	}
	if (err == 0)
		err = seq_getlastforkexitvalue(num_pipes, pids);
	setsdtout(&execvars);
	free(pids);
	return (err);
}
*/
// END executor guardando pipes en array

/* Este codigo  ejecuta primero buscar path y luego heredocs */
/*
void	executor_minish(t_shell *shell)
{
	int	err_res;

	set_executor(shell);
	err_res = set_path_cmd(shell->pipe_lst, shell->envp_exec);
	if (err_res == 0)
	{
		err_res = read_heredocs(shell);
		if (err_res == 0 && shell->pipes == 1 && \
			get_builtin(shell->pipe_lst->argv_exec[0]) > -1)
			err_res = execute_one_builtin(shell);
		else if (err_res == 0)
			err_res = executor(shell->pipe_lst, shell->pipes, shell);
	}
	shell->exit_st = err_res;
	shell->pipes = 0;
	free(shell->input);
	free_tokenlst(&shell->token_lst);
	free_pipelst(&shell->pipe_lst);
}
*/

/*
void	executor_minish(t_shell *shell)
{
	int	err_res;

	set_executor(shell);
	err_res = read_heredocs(shell);
//	err_res = set_path_cmd(shell->pipe_lst, shell->envp_exec);
	if (err_res == 0)
	{
//		err_res = read_heredocs(shell);
		err_res = set_path_cmd(shell->pipe_lst, shell->envp_exec);
		if (err_res == 0 && shell->pipes == 1 && \
			get_builtin(shell->pipe_lst->argv_exec[0]) > -1)
			err_res = execute_one_builtin(shell);
		else if (err_res == 0)
			err_res = executor(shell->pipe_lst, shell->pipes, shell);
	}
	shell->exit_st = err_res;
	shell->pipes = 0;
	free(shell->input);
	free_tokenlst(&shell->token_lst);
	free_pipelst(&shell->pipe_lst);
}
*/

void	executor_minish(t_shell *shell)
{
	int	err_res;

	set_executor(shell);
	err_res = read_heredocs(shell);
	if (err_res == 0 && shell->pipes == 1 && \
		get_builtin(shell->pipe_lst->argv_exec[0]) > -1)
		err_res = execute_one_builtin(shell);
	else if (err_res == 0)
		err_res = executor(shell->pipe_lst, shell->pipes, shell);
	shell->exit_st = err_res;
	shell->pipes = 0;
	free(shell->input);
	free_tokenlst(&shell->token_lst);
	free_pipelst(&shell->pipe_lst);
}
