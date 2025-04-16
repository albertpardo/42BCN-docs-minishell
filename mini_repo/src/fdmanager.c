/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdmanager.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apardo-m <apardo-m@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 13:50:22 by apardo-m          #+#    #+#             */
/*   Updated: 2024/05/29 12:53:25 by apardo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executor.h"

#define FILE_NULL "filename is NULL or \"\""

/* 
 * associate file descriptors  'execvars->next_fdin' and 'execvars->fdout' to
 * to in and out of the new pipe
 */

static void	managerfdpipes(t_pipe *pnode, t_execut *execvars)
{
	if (pnode->next != NULL )
	{
		pipe(execvars->next_pipe);
		execvars->next_fdin = execvars->next_pipe[PIPE0_STDIN];
		execvars->fdout = execvars->next_pipe[PIPE1_STDOUT];
	}
}

/*
 *  Get the file descriptor for the filename in 'execvars->filein'
 *  and set it to 'execvars->fdin'
 */

/*
static int	managerfdin(t_execut *execvars)
{
	int	err;

	err = 0;
	if (execvars->filein != NULL)
	{
		execvars->fdin = open(execvars->filein, O_RDONLY);
		err = test_fd_ok(execvars->fdin, execvars->filein);
	}
	return (err);
}
*/

static int	managerfdin(t_execut *execvars)
{
	int	err;

	err = 0;
	if (execvars->filein != NULL)
	{
		execvars->tmp_in = dup(STDIN_FILENO);
		execvars->fdin = open(execvars->filein, O_RDONLY);
		err = test_fd_ok(execvars->fdin, execvars->filein);
	}
	return (err);
}

/*
 *  Get the file descriptor for the filename in 'execvars->fileout'
 *  and set it to 'execvars->fdout'
 *
 *  Takes care if 'execvars->fileout' must be APPEND or TRUCATE
 */

static int	managerfdout(t_execut *execvars)
{
	int	err;

	err = 0;
	if (execvars->fileout != NULL)
	{
		execvars->tmp_out = dup(STDOUT_FILENO);
		if (execvars->isfileoutappend)
			execvars->fdout = open(execvars->fileout, O_WRONLY | O_APPEND);
		else
			execvars->fdout = open(execvars->fileout, O_WRONLY | O_TRUNC);
		err = test_fd_ok(execvars->fdout, execvars->fileout);
	}
	return (err);
}

/*
 * Set file descriptors in 'execvars' for current pipe
 */

int	fdmanager(t_pipe *pnode, t_execut *execvars)
{
	int	err;

	managerfdpipes(pnode, execvars);
	err = managerfdin(execvars);
	if (err == 0)
		err = managerfdout(execvars);
	return (err);
}
