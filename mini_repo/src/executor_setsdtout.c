/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor_setsdtout.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apardo-m <apardo-m@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 15:21:26 by apardo-m          #+#    #+#             */
/*   Updated: 2024/05/27 15:07:26 by apardo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executor.h"

// Set STDOUT = 1 when it has been changed to another File Descriptor value
void	setsdtout(t_execut *execvars)
{
	if (execvars->tmp_out != -1)
	{
		dup2(execvars->tmp_out, STDOUT_FILENO);
		close(execvars->tmp_out);
	}
}
