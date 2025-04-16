/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getlastforkexitvalue.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apardo-m <apardo-m@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 15:23:12 by apardo-m          #+#    #+#             */
/*   Updated: 2024/05/25 11:06:03 by apardo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executor.h"

static int	waitforks(int npipes, int lastpid)
{
	int	i;
	int	pid;
	int	status;
	int	laststatus;

	i = 0;
	while (i++ < npipes)
	{
		pid = wait(&status);
		if (pid == lastpid)
			laststatus = status;
	}
	return (laststatus);
}

/*
 * Returns the exit value from the last executed command
 */

int	getlastforkexitvalue(int npipes, int lastpid)
{
	int	laststatus;

	laststatus = waitforks(npipes, lastpid);
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
