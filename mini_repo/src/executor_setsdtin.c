/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor_setsdtin.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apardo-m <apardo-m@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 15:36:13 by apardo-m          #+#    #+#             */
/*   Updated: 2024/05/27 15:39:03 by apardo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executor.h"

// Set STDIN = 0 when it has been changed to another File Descriptor value
void	setsdtin(t_execut *execvars)
{
	if (execvars->tmp_in != -1)
	{
		dup2(execvars->tmp_in, STDIN_FILENO);
		close(execvars->tmp_in);
	}
}
