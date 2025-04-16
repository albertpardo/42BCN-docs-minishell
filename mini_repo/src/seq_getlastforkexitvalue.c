/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   seq_getlastforkexitvalue.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apardo-m <apardo-m@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 15:23:12 by apardo-m          #+#    #+#             */
/*   Updated: 2024/05/25 11:23:10 by apardo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executor.h"

static int	waitforks(int npipes, pid_t *pids)
{
	int	i;
	int	status;

	i = 0;
	while (i < npipes)
		waitpid(pids[i++], &status, 0);
	return (status);
}

/*
 * Returns the exit value from the last executed command
 */

int	seq_getlastforkexitvalue(int npipes, pid_t *pids)
{
	int	laststatus;

	laststatus = waitforks(npipes, pids);
	if (WIFEXITED(laststatus))
		return (WEXITSTATUS(laststatus));
	else if (WIFSIGNALED(laststatus))
	{
		if (WTERMSIG(laststatus) == SIGQUIT)
			ft_putstr_fd("Quit: 3", STDERR_FILENO);
		ft_putstr_fd("\n", STDERR_FILENO);
		return (WTERMSIG(laststatus) + 128);
	}
	return (EXIT_FAILURE);
}
